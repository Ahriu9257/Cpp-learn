#pragma once

#include "mylib/sensor/SensorType.h"

#include <string>

namespace mylib
{
namespace sensor
{

class ISensor
{
public:
    virtual ~ISensor() = default;

    virtual double read() const = 0;
    virtual std::string name() const = 0;
    virtual SensorType type() const = 0;
};

} // namespace sensor
} // namespace mylib
