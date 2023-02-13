#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QUrlQuery>

#include "apiclient.h"

APIClient::APIClient(QObject *parent)
    : QObject{parent}
    , m_netManager{new QNetworkAccessManager{this}}
    , m_netReply{nullptr}
    , m_dataBuffer{new QByteArray{}}
{
    parseUserSecrets();
}

void APIClient::onGetLocations(const QString &location)
{
    buildLocationRequestUrl(location);
    sendGetRequest();
}

void APIClient::buildLocationRequestUrl(const QString &location)
{
    WeatherAPIUrl.setScheme("https");
    WeatherAPIUrl.setUrl(weatherMapObject["url"].toString());
    WeatherAPIUrl.setPath(weatherMapObject["geocodeEndPoint"].toString());

    QUrlQuery locationQueries;
    locationQueries.addQueryItem("q", location);
    locationQueries.addQueryItem("limit", "5");
    locationQueries.addQueryItem(appIDQuery, weatherMapObject["APIKey"].toString());

    WeatherAPIUrl.setQuery(locationQueries);
    qDebug() << WeatherAPIUrl;
}

void APIClient::parseUserSecrets()
{
    QFile file("D:/Projects/Qt/Meteo2/secrets.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return;
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
    QJsonObject jsonObject = jsonDoc.object();
    weatherMapObject = jsonObject["OpenWeatherMap"].toObject();
}

void APIClient::onGetWeather(const double latitude, const double longitude)
{
    buildWeatherRequestUrl(latitude, longitude);
    sendGetRequest();
}

void APIClient::buildWeatherRequestUrl(const double latitude, const double longitude)
{
    WeatherAPIUrl.setScheme("https");
    WeatherAPIUrl.setUrl(weatherMapObject["url"].toString());
    WeatherAPIUrl.setPath(weatherMapObject["weatherEndPoint"].toString());

    QUrlQuery weatherQueries{buildWeatherRequestQueries(latitude, longitude)};

    WeatherAPIUrl.setQuery(weatherQueries);
}

QUrlQuery APIClient::buildWeatherRequestQueries(const double latitude, const double longitude)
{
    QUrlQuery weatherQueries;
    weatherQueries.addQueryItem(weatherMapObject["latitudeQuery"].toString(), QString::number(latitude, 'f'));
    weatherQueries.addQueryItem(weatherMapObject["longitudeQuery"].toString(), QString::number(longitude, 'f'));
    weatherQueries.addQueryItem(appIDQuery, weatherMapObject["APIKey"].toString());
    weatherQueries.addQueryItem(unitsQUery, weatherMapObject["unitQuery"].toString());
    weatherQueries.addQueryItem("exclude", "minutely");

    return weatherQueries;
}

void APIClient::sendGetRequest()
{
    QNetworkRequest request{WeatherAPIUrl};
    m_netReply = m_netManager->get(request);

    connect(m_netReply, &QIODevice::readyRead, this, &APIClient::dataReadyRead);
    connect(m_netReply, &QNetworkReply::finished, this, &APIClient::dataReadFinished);
}

void APIClient::dataReadyRead()
{
    m_dataBuffer->append(m_netReply->readAll());
}

void APIClient::dataReadFinished()
{
    if(m_netReply->error())
    {
        qDebug() << "Error: " << m_netReply->errorString();
        return;
    }
    QJsonDocument doc{QJsonDocument::fromJson(*m_dataBuffer)};
    m_dataBuffer->clear();
    emit onDataFetchFinished(doc);
}


