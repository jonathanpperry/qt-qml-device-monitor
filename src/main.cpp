#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QVariant>

#include "TemperatureSensor.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TemperatureSensor sensor(72.0);

    QQmlApplicationEngine engine;

    engine.setInitialProperties({
        { "temperatureSensor", QVariant::fromValue(&sensor) }
    });

    engine.loadFromModule("DeviceMonitor", "Main");

    return app.exec();
}