//
// Created by ahriu on 2026/5/23.
//
#include "Sensor.h"

#include <iostream>
#include <ostream>

void Sensor::set(float lux, uint16_t ir, uint16_t ps)
{
    this->lux_ = lux;
    this->ir_ = ir;
    this->ps_ = ps;
}

void Sensor::print() const
{
    std::cout << "Sensor Data : " << std::endl;
    std::cout << "lux = " << lux_ << std::endl;
    std::cout << "ir = " << ir_ << std::endl;
    std::cout << "ps = " << ps_ << std::endl;
}
