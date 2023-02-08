#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>

#include "apiclient.h"

APIClient::APIClient(QObject *parent)
    : QObject{parent}
    , m_netManager{new QNetworkAccessManager{this}}
    , m_netReply{nullptr}
    , m_dataBuffer{new QByteArray{}}
{

    buildAPIUrl();
    //TO-DO
    //Connect this to a QML push button for later.
    onGetWeather();
}

void APIClient::buildAPIUrl()
{
    QFile file("D:/Projects/Qt/Meteo2/secrets.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return;
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
    QJsonObject jsonObject = jsonDoc.object();
    QJsonObject weatherMapObject = jsonObject["OpenWeatherMap"].toObject();

    qDebug() << "Json Object" << weatherMapObject["url"];

    WeatherAPIUrl.setScheme("https");
    WeatherAPIUrl.setUrl(weatherMapObject["url"].toString());
    WeatherAPIUrl.setPath(weatherMapObject["weatherEndPoint"].toString());
    QUrlQuery weatherQueries;
    weatherQueries.addQueryItem(latitedeQuery, "33.44");
    weatherQueries.addQueryItem(longitudedeQuery, "94.04");
    weatherQueries.addQueryItem(appIDQuery, weatherMapObject["APIKey"].toString());
    weatherQueries.addQueryItem(unitsQUery, weatherMapObject["unitQuery"].toString());

    WeatherAPIUrl.setQuery(weatherQueries);
}

void APIClient::onGetWeather()
{
    QNetworkRequest request{WeatherAPIUrl};
    qDebug() << WeatherAPIUrl;
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

    //qDebug() << "Data fetch finished: " << QString(*m_data_buffer);

    //Turn the data into a json document
    QJsonDocument doc{QJsonDocument::fromJson(*m_dataBuffer)};
    qDebug() << "Data fetch finished: " << doc;
    /*
    //What if you get an object from the server
    QJsonDocument objectDoc{QJsonDocument::fromJson(*m_data_buffer)};
    QJsonObject jsonDocumentAsObject{objectDoc.toVariant().toJsonObject()};
    */

    //Turn document into json array
    //QJsonArray array = doc.array();
/*
    for(auto i : array)
    {
        QJsonObject object{i.toObject()};
        QVariantMap map{object.toVariantMap()};
        QString title{map["title"].toString()};
        int id{map["id"].toInt()};
    }
*/
}


