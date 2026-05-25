// Created by ahriu on 2026/5/23.
//
#include "MockTempSensor.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

MockTempSensor::MockTempSensor()
    :temperature_(25.0)
{
    std::cout << "MockTempSensor constructed!" << std::endl;
}

double MockTempSensor::read()
{
    this->temperature_ +=0.5;
    return this->temperature_;
}

std::string MockTempSensor::name() const
{
    return "MockTempSensor";
}

MockTempSensor::~MockTempSensor()
{
    std::cout << "MockTempSensor destructed!" << std::endl;
}
