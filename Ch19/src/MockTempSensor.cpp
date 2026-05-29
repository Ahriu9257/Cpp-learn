#include "mylib/sensor/MockTempSensor.h"

namespace mylib
{
namespace sensor
{

MockTempSensor::MockTempSensor(double temp)
    : temp_(temp)
{
}

double MockTempSensor::read() const
{
    return temp_;
}

std::string MockTempSensor::name() const
{
    return "MockTempSensor";
}

SensorType MockTempSensor::type() const
{
    return SensorType::Temp;
}

}   // namespace sensor
}   // namespace mylib