//
// Created by ahriu on 2026/5/25.
//

#ifndef CH06SENSORS_AP3216C_H
#define CH06SENSORS_AP3216C_H

#include <string>

#include "ISensor.h"

class AP3216C : public ISensor
{
public:
    AP3216C();
    ~AP3216C() override;
    double read() const override;
    std::string name() const override;
    ISensorType sensorType() const override;

private:
    double lux_;
};

#endif //CH06SENSORS_AP3216C_H
