#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(
    double temperature,
    QObject *parent)
    : QObject(parent),
      m_temperature(temperature)
{
    connect(
        &m_updateTimer,
        &QTimer::timeout,
        this,
        [this]()
        {
            setTemperature(m_temperature + 0.5);
        });

    m_updateTimer.start(1000);
}

double TemperatureSensor::temperature() const
{
    return m_temperature;
}

void TemperatureSensor::setTemperature(double temperature)
{
    if (m_temperature == temperature)
    {
        return;
    }

    m_temperature = temperature;

    emit temperatureChanged(m_temperature);
}

bool TemperatureSensor::isRunning() const
{
    return m_updateTimer.isActive();
}

void TemperatureSensor::start()
{
    // Start the timer and notify QML.
    m_updateTimer.start();
    emit runningChanged(true);
}

void TemperatureSensor::stop()
{
    // Stop the timer and notify QML.
    m_updateTimer.stop();
    emit runningChanged(false);
}