#pragma once

#include "mylib/sensor/ISensor.h"

#include <string>

namespace mylib
{
namespace sensor
{

class MockTempSensor final : public ISensor
{
public:
    explicit MockTempSensor(double temp);

    double read() const override;
    std::string name() const override;
    SensorType type() const override;

private:
    double temp_;
};

}   // namespace sensor
}   // namespace mylib