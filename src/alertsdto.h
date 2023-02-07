#ifndef ALERTSDTO_H
#define ALERTSDTO_H

#include <QString>

struct AlertsDTO
{
    AlertsDTO(const QString& senderName, const QString& alertEventName,
              const qint64 alertStartTime, const qint64 alertEndTime,
              const QString& alertDescription)
        : m_senderName{senderName}
        , m_alertEventName{alertEventName}
        , m_alertStartTime{alertStartTime}
        , m_alertEndTime{alertEndTime}
        , m_alertDescription{alertDescription}
    {}

    QString m_senderName;
    QString m_alertEventName;
    qint64 m_alertStartTime;
    qint64 m_alertEndTime;
    QString m_alertDescription;
};

#endif // ALERTSDTO_H
