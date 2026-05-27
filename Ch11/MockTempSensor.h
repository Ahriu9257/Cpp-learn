//
// Created by ahriu on 2026/5/25.
//

#ifndef CH06SENSORS_MOCKTEMPSENSOR_H
#define CH06SENSORS_MOCKTEMPSENSOR_H

#include <string>

#include "ISensor.h"

class MockTempSensor : public ISensor
{
public:
    MockTempSensor();
    ~MockTempSensor() override;
    double read() const override;
    std::string name() const override;
    ISensorType sensorType() const override;

private:
    double temperature_;
};

#endif //CH06SENSORS_MOCKTEMPSENSOR_H
