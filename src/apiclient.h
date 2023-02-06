#ifndef APICLIENT_H
#define APICLIENT_H

#include <QObject>

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

};

#endif // APICLIENT_H
