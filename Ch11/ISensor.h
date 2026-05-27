//
// Created by ahriu on 2026/5/25.
//

#ifndef CH06SENSORS_ISENSOR_H
#define CH06SENSORS_ISENSOR_H

#pragma once
#include <cstdint>

enum class ISensorType : uint8_t
{
    Light,
    Temp,
    Proximity
};

class ISensor
{
public:
    virtual ~ISensor() = default;
    virtual double read() const = 0;
    virtual std::string name() const = 0;
    virtual ISensorType sensorType() const = 0;
};

#endif //CH06SENSORS_ISENSOR_H
