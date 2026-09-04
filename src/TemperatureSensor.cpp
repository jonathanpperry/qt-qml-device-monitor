#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(
    double temperature,
    QObject *parent)
    : QObject(parent),
      m_temperature(temperature)
{
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