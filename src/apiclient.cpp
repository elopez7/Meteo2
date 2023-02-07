#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "apiclient.h"

APIClient::APIClient(QObject *parent)
    : QObject{parent}
    , m_netManager{new QNetworkAccessManager{this}}
    , m_netReply{nullptr}
    , m_dataBuffer{new QByteArray{}}
{

    //TO-DO
    //Connect this to a QML push button for later.
    //onGetWeather();
}

void APIClient::onGetWeather()
{
    const QUrl API_ENDPOINT{QStringLiteral("https://api.openweathermap.org/data/3.0/onecall?lat=33.44&lon=94.04&appid=e701b754480e00672928449a6c2d991a&units=metric")};
    QNetworkRequest request{API_ENDPOINT};
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
