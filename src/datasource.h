#ifndef DATASOURCE_H
#define DATASOURCE_H
#include "apiclient.h"

#include <QObject>

class DataSource : public QObject
{
    Q_OBJECT
public:
    explicit DataSource(QObject *parent = nullptr);
    void sendRequest();
signals:

private:

};

#endif // DATASOURCE_H
