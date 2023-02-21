// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"

#include "datasource.h"
#include "locationmodel.h"


#include <QDateTime>


int main(int argc, char *argv[])
{
    set_qt_environment();

    QGuiApplication app(argc, argv);

/*
    QString timeStamp{"1676935777"};
    qint64 convertedStamp{timeStamp.toLongLong()};
    QDateTime myDateTime{QDateTime::fromSecsSinceEpoch(convertedStamp)};
    qDebug() << "Converted Timestamp" << myDateTime;
*/

    QQmlApplicationEngine engine;

    LocationModel locationModel;
    DataSource* dataSource{new DataSource(&engine)};
    locationModel.setDataSource(dataSource);

    qmlRegisterSingletonType<DataSource*>("org.esteban.data", 1, 0, "DataSource", [&](QQmlEngine *, QJSEngine *) -> QObject *{
        return dataSource;
    });

    qmlRegisterSingletonType<LocationModel>("org.esteban.Locations", 1, 0, "LocationModel", [&](QQmlEngine *, QJSEngine *) -> QObject *{
        return &locationModel;
    });

    const QUrl url(u"qrc:Main/main.qml"_qs);
    QObject::connect(
                &engine, &QQmlApplicationEngine::objectCreated, &app,
                [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
    //dataSource->onSearchButtonPressed("London");

    return app.exec();
}
