#include "mylib/sensor/AP3216CSensor.h"

namespace mylib
{
namespace sensor
{

AP3216CSensor::AP3216CSensor(double lux)
    : lux_(lux)
{
}

double AP3216CSensor::read() const
{
    return lux_;
}

std::string AP3216CSensor::name() const
{
    return "AP3216C";
}

SensorType AP3216CSensor::type() const
{
    return SensorType::Light;
}

} // namespace sensor
} // namespace mylib
