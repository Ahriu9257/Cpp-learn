//
// Created by ahriu on 2026/5/23.
//

#ifndef CH05SENSOR_AP3216CSENSOR_H
#define CH05SENSOR_AP3216CSENSOR_H

#pragma once

#include <cstdint>
#include <string>

#include "ISensor.h"

class AP3216C : public ISensor
{
public:
    AP3216C();

    double read() override;

    std::string name() const override;

    ~AP3216C() override;

private:
    double lux_;
};

#endif //CH05SENSOR_AP3216CSENSOR_H
