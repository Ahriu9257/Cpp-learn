//
// Created by ahriu on 2026/5/25.
//
#include "MockTempSensor.h"

#include <iostream>
#include <ostream>

MockTempSensor::MockTempSensor()
    :temperature_(25.0)
{
    std::cout << " MockTempSensor constructed!" << std::endl;
}

MockTempSensor::~MockTempSensor()
{
    std::cout << " MockTempSensor deconstructed!" << std::endl;
}

double MockTempSensor::read() const
{
    return this->temperature_;
}

std::string MockTempSensor::name() const
{
    return "MockTempSensor";
}

ISensorType MockTempSensor::sensorType() const
{
    return ISensorType::Temp;
}