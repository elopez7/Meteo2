#ifndef WEATHERDTO_H
#define WEATHERDTO_H

#include <QString>
#include <QList>

struct WeatherDescriptionDTO
{
    int m_id;
    QString m_weatherParameter;
    QString m_weatherDescription;
    QString m_weatherIcon;
};

struct WeatherDTO
{
    WeatherDTO(const QString& forecastTime,
               const int pressure,
               const int humidityPercentage,
               const double dewPoint,
               const double uvi,
               const int cloudPercentage,
               const int windSpeed,
               const int windDirection,
               const double windGust,
               const QList<WeatherDescriptionDTO>& weatherDescriptionObjects)
        : m_forecastTime(forecastTime)
        , m_pressure(pressure)
        , m_humidityPercentage(humidityPercentage)
        , m_dewPoint(dewPoint)
        , m_uvi(uvi)
        , m_cloudPercentage(cloudPercentage)
        , m_windSpeed(windSpeed)
        , m_windDirection(windDirection)
        , m_windGust(windGust)
        , m_weatherDescriptionObjects{weatherDescriptionObjects}

    {}
    QString m_forecastTime;
    int m_pressure;
    int m_humidityPercentage;
    double m_dewPoint;
    double m_uvi;
    int m_cloudPercentage;
    int m_windSpeed;
    int m_windDirection; // Degrees
    double m_windGust;
    QList<WeatherDescriptionDTO> m_weatherDescriptionObjects;
};

struct CurrentWeatherDTO : WeatherDTO
{
    CurrentWeatherDTO(const QString& forecastTime,
                      const int pressure,
                      const int humidityPercentage,
                      const double dewPoint,
                      const double uvi,
                      const int cloudPercentage,
                      const int windSpeed,
                      const int windDirection,
                      const double windGust,
                      const QList<WeatherDescriptionDTO>& weatherDescriptionObjects,
                      const QString& sunriseTime,
                      const QString& sunsetTime,
                      const double temperature,
                      const double feelsLike,
                      const int visibility)
        : WeatherDTO{forecastTime,
                     pressure,
                     humidityPercentage,
                     dewPoint,
                     uvi,
                     cloudPercentage,
                     windSpeed,
                     windDirection,
                     windGust,
                     weatherDescriptionObjects}
        , m_sunriseTime{sunriseTime}
        , m_sunsetTime{sunsetTime}
        , m_temperature{temperature}
        , m_feelsLike{feelsLike}
        , m_visibility{visibility}
    {}
    QString m_sunriseTime;
    QString m_sunsetTime;
    double m_temperature;
    double m_feelsLike;
    int m_visibility;
};

struct HourlyWeatherDTO : WeatherDTO
{
    HourlyWeatherDTO(const QString& forecastTime,
                     const int pressure,
                     const int humidityPercentage,
                     const double dewPoint,
                     const double uvi,
                     const int cloudPercentage,
                     const int windSpeed,
                     const int windDirection,
                     const double windGust,
                     const QList<WeatherDescriptionDTO>& weatherDescriptionObjects,
                     const double temperature,
                     const double feelsLike,
                     const int visibility,
                     const double pop)
        : WeatherDTO{forecastTime,
                     pressure,
                     humidityPercentage,
                     dewPoint,
                     uvi,
                     cloudPercentage,
                     windSpeed,
                     windDirection,
                     windGust,
                     weatherDescriptionObjects}
        , m_temperature{temperature}
        , m_feelsLike{feelsLike}
        , m_visibility{visibility}
        , m_pop{pop}
    {}

    double m_temperature;
    double m_feelsLike;
    int m_visibility;
    double m_pop;
};

struct DailyTemperatureDTO
{
    double m_day;
    double m_min;
    double m_max;
    double m_night;
    double m_eve;
    double m_morning;
};

struct DailyFeelsLikeDTO
{
    double m_day;
    double m_night;
    double m_eve;
    double m_morning;
};

struct DailyWeatherDTO : WeatherDTO
{
    DailyWeatherDTO(const QString& forecastTime,
                    const int pressure,
                    const int humidityPercentage,
                    const double dewPoint,
                    const double uvi,
                    const int cloudPercentage,
                    const int windSpeed,
                    const int windDirection,
                    const double windGust,
                    const QList<WeatherDescriptionDTO>& weatherDescriptionObjects,
                    const QString& sunriseTime,
                    const QString& sunsetTime,
                    const QString& moonriseTime,
                    const QString& moonsetTime,
                    const double pop,
                    const double snowPercentage,
                    const DailyTemperatureDTO& dailyTemperature,
                    const DailyFeelsLikeDTO dailyFeelsLike)
        : WeatherDTO{forecastTime,
                     pressure,
                     humidityPercentage,
                     dewPoint,
                     uvi,
                     cloudPercentage,
                     windSpeed,
                     windDirection,
                     windGust,
                     weatherDescriptionObjects}
        , m_sunriseTime{sunriseTime}
        , m_sunsetTime{sunsetTime}
        , m_moonriseTime{moonriseTime}
        , m_moonsetTime{moonsetTime}
        , m_pop{pop}
        , m_snowPercentage{snowPercentage}
        , m_dailyTemperature{dailyTemperature}
        , m_deilyFeelsLike{dailyFeelsLike}
    {}
    QString m_sunriseTime;
    QString m_sunsetTime;
    QString m_moonriseTime;
    QString m_moonsetTime;
    double m_pop;
    double m_snowPercentage;
    DailyTemperatureDTO m_dailyTemperature;
    DailyFeelsLikeDTO m_deilyFeelsLike;
};

#endif // WEATHERDTO_H
