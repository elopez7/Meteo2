#include "datasource.h"
#include <QDebug>

DataSource::DataSource(QObject *parent)
    : QObject{parent}
{
    connect(&m_apiClient, &APIClient::onDataFetchFinished, this, &DataSource::onDataFetchFinished);
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
        qDebug() << currentWeatherJsonObject;
        return;
    }

    QJsonArray locationsArray = fetchedObject.array();
    moveLocationsFromJsonArrayToLocationsList(locationsArray);
}
