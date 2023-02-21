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

signals:
    void preAddLocationToModel();
    void postAddLocationToModel();
    void preResetModel();
    void postResetModel();

    void currentTemperatureChanged();

    void currentTimeChanged();

    void descriptionChanged();

private slots:
    void onDataFetchFinished(QJsonDocument weatherObject);

private:
    APIClient m_apiClient;
    //CurrentWeatherDTO currentWeather;
    QList<LocationDTO* > m_locationsList;
    QList<DailyWeatherDTO*> m_dailyWeatherList;
    bool m_isRequestingLocation;

    void getLocationInformation(const QString& location);
    void moveLocationsFromJsonArrayToLocationsList(QJsonArray locationsArray);
    double m_currentTemperature{0.0};
    QString m_currentTime;
    QString m_description;
};

#endif // DATASOURCE_H
