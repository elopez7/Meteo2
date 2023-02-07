#ifndef LOCATIONDTO_H
#define LOCATIONDTO_H

#include <QString>

struct LocationDTO
{
    LocationDTO(const QString& locationName, const QString& countryName,
                const QString& stateName, const double latitude,
                const double longitude)
        : m_locationName{locationName}
        , m_countryName{countryName}
        , m_stateName{stateName}
        , m_latitude{latitude}
        , m_longitude{longitude}

    {}

    QString m_locationName;
    QString m_countryName;
    QString m_stateName;
    double m_latitude;
    double m_longitude;
};

#endif // LOCATIONDTO_H
