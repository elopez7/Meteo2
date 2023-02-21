#include "datasource.h"
#include <QDebug>
#include <QDateTime>

DataSource::DataSource(QObject *parent)
    : QObject{parent}
{
    connect(&m_apiClient, &APIClient::onDataFetchFinished, this, &DataSource::onDataFetchFinished);
    setCurrentTime(QDateTime::currentDateTime().toString("hh:mm AP-dddd, dd-MMM-yyyy"));
}

void DataSource::getWeatherInformation(const int selection)
{
    m_isRequestingLocation = false;
    LocationDTO* information = m_locationsList.at(selection);
    m_apiClient.onGetWeather(information->m_latitude, information->m_longitude);
}

void DataSource::onSearchButtonPressed(const QString &location)
{
    getLocationInformation(location);
}

void DataSource::getLocationInformation(const QString& location)
{
    if(!m_locationsList.empty())
    {
        emit preResetModel();
        m_locationsList.clear();
        emit postResetModel();
    }
    m_isRequestingLocation = true;
    m_apiClient.onGetLocations(location);
}

void DataSource::moveLocationsFromJsonArrayToLocationsList(QJsonArray locationsArray)
{
    for(auto i : locationsArray)
    {
        QJsonObject locationObject{i.toObject()};
        LocationDTO* newLocation{new LocationDTO(locationObject.value(QStringLiteral("name")).toString(),
                                                 locationObject.value(QStringLiteral("country")).toString(),
                                                 locationObject.value(QStringLiteral("state")).toString(),
                                                 locationObject.value(QStringLiteral("lat")).toDouble(),
                                                 locationObject.value(QStringLiteral("lon")).toDouble(),
                                                 this)};
        appendLocationToList(newLocation);
    }
}

void DataSource::appendLocationToList(LocationDTO *locationToAdd)
{
    emit preAddLocationToModel();
    qDebug() << locationToAdd->m_locationName << " " << locationToAdd->m_countryName;
    m_locationsList.append(locationToAdd);
    emit postAddLocationToModel();
}

QList<LocationDTO *> DataSource::getLocationsList()
{
    return m_locationsList;
}

void DataSource::onDataFetchFinished(QJsonDocument fetchedObject)
{
    if(!m_isRequestingLocation)
    {

        QJsonObject currentWeatherJsonObject = fetchedObject["current"].toObject();

        setCurrentTemperature(currentWeatherJsonObject["temp"].toDouble());

        double timeStamp{currentWeatherJsonObject["dt"].toDouble()};
        QDateTime forecastTime{};
        forecastTime.setSecsSinceEpoch(timeStamp);
        setCurrentTime(forecastTime.toString("hh:mm AP-dddd, dd-MMM-yyyy"));


        return;
    }

    QJsonArray locationsArray = fetchedObject.array();
    moveLocationsFromJsonArrayToLocationsList(locationsArray);
}

double DataSource::getCurrentTemperature() const
{
    return m_currentTemperature;
}

void DataSource::setCurrentTemperature(double newCurrentTemperature)
{
    if (qFuzzyCompare(m_currentTemperature, newCurrentTemperature))
        return;
    m_currentTemperature = newCurrentTemperature;
    emit currentTemperatureChanged();
}

QString DataSource::getCurrentTime() const
{
    return m_currentTime;
}

void DataSource::setCurrentTime(const QString &newCurrentTime)
{
    if (m_currentTime == newCurrentTime)
        return;
    m_currentTime = newCurrentTime;
    emit currentTimeChanged();
}

QString DataSource::setDescription() const
{
    return m_description;
}

void DataSource::setDescription(const QString &newDescription)
{
    if (m_description == newDescription)
        return;
    m_description = newDescription;
    emit descriptionChanged();
}
