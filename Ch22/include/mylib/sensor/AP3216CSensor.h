#pragma once

#include "mylib/sensor/ISensor.h"

#include <string>

namespace mylib
{
namespace sensor
{

class AP3216CSensor final : public ISensor
{
public:
    explicit AP3216CSensor(double lux);

    double read() const override;
    std::string name() const override;
    SensorType type() const override;

private:
    double lux_;
};

} // namespace sensor
} // namespace mylib
