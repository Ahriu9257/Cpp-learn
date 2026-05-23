//
// Created by ahriu on 2026/5/23.
//

#ifndef CH05SENSOR_MOCKTEMPSENSOR_H
#define CH05SENSOR_MOCKTEMPSENSOR_H

#pragma once

#include "ISensor.h"

class MockTempSensor : public ISensor
{
public:
    MockTempSensor();
    void read() override;
    const char* name() const override;
    ~MockTempSensor() override;

private:
    double temperature_;
};

#endif //CH05SENSOR_MOCKTEMPSENSOR_H
