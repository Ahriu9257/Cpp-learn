//
// Created by ahriu on 2026/5/23.
//

#ifndef CH05SENSOR_AP3216CSENSOR_H
#define CH05SENSOR_AP3216CSENSOR_H

#pragma once

#include <cstdint>

#include "ISensor.h"

class AP3216C : public ISensor
{
public:
    AP3216C();

    void read() override;

    const char* name() const override;

    ~AP3216C() override;

private:
    float lux_;
    uint16_t ir_;
    uint16_t ps_;
};

#endif //CH05SENSOR_AP3216CSENSOR_H
