#pragma once

#include <QObject>
#include <QTimer>
class TemperatureSensor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(
        double temperature
        READ temperature
        WRITE setTemperature
        NOTIFY temperatureChanged)

    Q_PROPERTY(
        bool running
        READ isRunning
        NOTIFY runningChanged)

public:
    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    explicit TemperatureSensor(
        double temperature = 72.0,
        QObject *parent = nullptr
    );

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