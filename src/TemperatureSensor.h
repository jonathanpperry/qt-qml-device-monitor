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
        NOTIFY temperatureChanged
    )

public:
    explicit TemperatureSensor(
        double temperature = 72.0,
        QObject *parent = nullptr
    );

    double temperature() const;
    void setTemperature(double temperature);

signals:
    void temperatureChanged(double temperature);

private:
    double m_temperature;
    QTimer m_updateTimer;
};