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
    //QML_NAMED_ELEMENT(WeatherDataSource)
public:
    explicit DataSource(QObject *parent = nullptr);

    Q_INVOKABLE void getWeatherInformation(const int selection);
    Q_INVOKABLE void onSearchButtonPressed(const QString& location);

    QList<LocationDTO* > getLocationsList();
    void appendLocationToList(LocationDTO* locationToAdd);

signals:
    void preAddLocationToModel();
    void postAddLocationToModel();
    void preResetModel();
    void postResetModel();

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
};

#endif // DATASOURCE_H
