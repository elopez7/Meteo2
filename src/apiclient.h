#ifndef APICLIENT_H
#define APICLIENT_H

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class APIClient : public QObject
{
    Q_OBJECT
public:
    explicit APIClient(QObject *parent = nullptr);

signals:

public slots:
    void onGetWeather();
    void dataReadyRead();
    void dataReadFinished();

private:
    QNetworkAccessManager *m_netManager;
    QNetworkReply *m_netReply;
    QByteArray *m_dataBuffer;

    QString m_latitudeValue;
    QString m_longitudeValue;
    QString m_APIKeyValue;
    QString m_excludeValue;
    QString m_unitsValue;

    QUrl WeatherAPIUrl;

    QString baseUrl{QStringLiteral("https//api.openweathermap.org")};
    QString weatherEndPoint{QStringLiteral("/data/3.0/onecall")};
    QString latitedeQuery{QStringLiteral("lat")};
    QString longitudedeQuery{QStringLiteral("lon")};
    QString appIDQuery{QStringLiteral("appid")};
    QString unitsQUery{QStringLiteral("units")};


    void buildAPIUrl();

};

#endif // APICLIENT_H
