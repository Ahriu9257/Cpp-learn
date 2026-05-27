//
// Created by ahriu on 2026/5/27.
//

#ifndef CH06SENSORS_MOCKSENSORS_H
#define CH06SENSORS_MOCKSENSORS_H

#pragma once

#include "ISensor.h"

class LightSensor : public ISensor
{
public:
    std::string name() const override { return "LightSensor"; }

    float read() const override { return 123.4f; }
};

class TempSensor : public ISensor
{
public:
    std::string name() const override { return "TempSensor"; }

    float read() const override { return 23.4f; }
};


class ProximitySensor : public ISensor
{
public:
    std::string name() const override { return "ProximitySensor"; }

    float read() const override { return 52.4f; }
};

#endif //CH06SENSORS_MOCKSENSORS_H
