//
// Created by ahriu on 2026/5/23.
//
#include "Sensor.h"

#include <iostream>
#include <ostream>

Sensor::Sensor(float lux)
    : lux_(lux), ir_(0), ps_(0)
{
    std::cout << "Sensor constructed only with lux :" << this << std::endl;
}

Sensor::Sensor(float lux, uint16_t ir, uint16_t ps)
    : lux_(lux), ir_(ir), ps_(ps)
{
    std::cout << "Sensor constructed : " << this << std::endl;
}

Sensor::~Sensor()
{
    std::cout << "Sensor destroyed : " << this << std::endl;
}

void Sensor::set(float lux, uint16_t ir, uint16_t ps)
{
    this->lux_ = lux;
    this->ir_ = ir;
    this->ps_ = ps;
}

void Sensor::print() const
{
    std::cout << "Sensor Data :" << std::endl;
    std::cout << "lux = " << this->lux_ << std::endl;
    std::cout << "ir = " << this->ir_ << std::endl;
    std::cout << "ps = " << this->ps_ << std::endl;
}
