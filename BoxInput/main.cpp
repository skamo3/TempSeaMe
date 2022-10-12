#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "numbercontrol.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/BoxInput/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    NumberControl controller;

    engine.rootContext()->setContextProperty("NumController", &controller);
    engine.load(url);

    return app.exec();
}
