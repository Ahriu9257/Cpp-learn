#pragma once

#include <cstdint>

namespace mylib
{
namespace sensor
{

enum class SensorType : std::uint8_t
{
    Light,
    Temp,
    Proximity
};

} // namespace sensor
} // namespace mylib
