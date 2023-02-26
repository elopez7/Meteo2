#ifndef DATASOURCE_H
#define DATASOURCE_H
#include "apiclient.h"
#include "locationdto.h"
#include "weatherdto.h"

#include "qqmlregistration.h"
#include <QJsonArray>
#include <QObject>

class DataSource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double currentTemperature READ getCurrentTemperature WRITE setCurrentTemperature NOTIFY currentTemperatureChanged)
    Q_PROPERTY(QString currentTime READ getCurrentTime WRITE setCurrentTime NOTIFY currentTimeChanged)
    Q_PROPERTY(QString description READ setDescription WRITE setDescription NOTIFY descriptionChanged)

    Q_PROPERTY(double feelsLike READ getFeelsLike WRITE setFeelsLike NOTIFY feelsLikeChanged)
    Q_PROPERTY(double humidity READ getHumidity WRITE setHumidity NOTIFY humidityChanged)
    Q_PROPERTY(double wind READ getWind WRITE setWind NOTIFY windChanged)
    Q_PROPERTY(double clouds READ getClouds WRITE setClouds NOTIFY cloudsChanged)
public:
    explicit DataSource(QObject *parent = nullptr);

    Q_INVOKABLE void getWeatherInformation(const int selection);
    Q_INVOKABLE void onSearchButtonPressed(const QString& location);

    QList<LocationDTO* > getLocationsList();
    void appendLocationToList(LocationDTO* locationToAdd);

    double getCurrentTemperature() const;
    void setCurrentTemperature(double newCurrentTemperature);

    QString getCurrentTime() const;
    void setCurrentTime(const QString &newCurrentTime);

    QString setDescription() const;
    void setDescription(const QString &newDescription);

    double getFeelsLike() const;
    void setFeelsLike(double newFeelsLike);

    double getHumidity() const;
    void setHumidity(double newHumidity);

    double getWind() const;
    void setWind(double newWind);

    double getClouds() const;
    void setClouds(double newClouds);

signals:
    void preAddLocationToModel();
    void postAddLocationToModel();
    void preResetModel();
    void postResetModel();

    void currentTemperatureChanged();

    void currentTimeChanged();

    void descriptionChanged();

    void feelsLikeChanged();

    void humidityChanged();

    void windChanged();

    void cloudsChanged();

private slots:
    void onDataFetchFinished(QJsonDocument weatherObject);

private:
    APIClient m_apiClient;
    //CurrentWeatherDTO currentWeather;
    QList<LocationDTO* > m_locationsList;
    QList<DailyWeatherDTO*> m_dailyWeatherList;
    bool m_isRequestingLocation;
    double m_currentTemperature{0.0};
    QString m_currentTime;
    QString m_description;
    double m_feelsLike;
    double m_humidity;
    double m_wind;
    double m_clouds;

    void getLocationInformation(const QString& location);
    void moveLocationsFromJsonArrayToLocationsList(QJsonArray locationsArray);
    void setCurrentWeatherData(QJsonDocument fetchedObject);
    void setWeatherDescription(QJsonObject currentWeatherJsonObject);
    void setTimeOfForecast(QJsonObject currentWeatherJsonObject);
    void setWeatherDetails(QJsonObject currentWeatherJsonObject);
};

#endif // DATASOURCE_H
