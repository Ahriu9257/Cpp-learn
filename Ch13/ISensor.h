//
// Created by ahriu on 2026/5/27.
//

#ifndef CH06SENSORS_ISENSOR_H
#define CH06SENSORS_ISENSOR_H

#pragma once
#include <string>

class ISensor
{
public:
    virtual ~ISensor() = default;

    virtual std::string name() const = 0;

    virtual float read() const = 0;
};

#endif //CH06SENSORS_ISENSOR_H
