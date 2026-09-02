#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TemperatureSensor.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TemperatureSensor sensor(72.0);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(
        "temperatureSensor",
        &sensor
    );

    engine.loadFromModule("DeviceMonitor", "Main");

    return app.exec();
}