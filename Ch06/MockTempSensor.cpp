// Created by ahriu on 2026/5/23.
//
#include "MockTempSensor.h"

#include <cstdlib>
#include <iostream>
#include <ostream>

MockTempSensor::MockTempSensor()
    :temperature_(0.0f)
{
    std::cout << "MockTempSensor constructed!" << std::endl;
}

void MockTempSensor::read()
{
    // 生成 20.00 到 29.99 之间的模拟温度。
    this->temperature_ = 20.0 + (std::rand() % 1000) / 100.0;

    std::cout << "MockTempSensor Data: " << std::endl;
    std::cout << "Temperature: " << this->temperature_ << std::endl;
}

const char* MockTempSensor::name() const
{
    return "MockTempSensor";
}

MockTempSensor::~MockTempSensor()
{
    std::cout << "MockTempSensor destructed!" << std::endl;
}
