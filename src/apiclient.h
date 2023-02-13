#ifndef APICLIENT_H
#define APICLIENT_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class APIClient : public QObject
{
    Q_OBJECT
public:
    explicit APIClient(QObject *parent = nullptr);

signals:
    void onDataFetchFinished(QJsonDocument weatherObject);

public slots:
    void onGetLocations(const QString& location);
    void onGetWeather(const double latitude, const double longitude);
    void dataReadyRead();
    void dataReadFinished();

private:
    QNetworkAccessManager *m_netManager;
    QNetworkReply *m_netReply;
    QByteArray *m_dataBuffer;

    QString m_latitudeValue;
    QString m_longitudeValue;

    QUrl WeatherAPIUrl;

    QString appIDQuery{QStringLiteral("appid")};
    QString unitsQUery{QStringLiteral("units")};
    QJsonObject weatherMapObject;

    void parseUserSecrets();
    void buildLocationRequestUrl(const QString &location);
    void buildWeatherRequestUrl(const double latitude, const double longitude);
    QUrlQuery buildWeatherRequestQueries(const double latitude, const double longitude);
    void sendGetRequest();
};

#endif // APICLIENT_H
