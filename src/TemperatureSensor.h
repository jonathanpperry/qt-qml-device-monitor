#pragma once

#include <QObject>
#include <QTimer>
#include <QtQmlIntegration/qqmlintegration.h>

class TemperatureSensor : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("TemperatureSensor is provided by C++")

    Q_PROPERTY(double temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)

public:
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    explicit TemperatureSensor(
        double temperature = 72.0,
        QObject *parent = nullptr);

    double temperature() const;
    void setTemperature(double temperature);
    bool isRunning() const;

signals:
    void temperatureChanged(double temperature);
    void runningChanged(bool running);

private:
    double m_temperature;
    QTimer m_updateTimer;
};