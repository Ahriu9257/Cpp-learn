//
// Created by ahriu on 2026/5/25.
//
#include "AP3216C.h"

#include <iostream>
#include <ostream>

AP3216C::AP3216C()
    :lux_(123.3)
{
    std::cout << "AP3216C constructor called" << std::endl;
}

AP3216C::~AP3216C()
{
    std::cout << "AP3216C destructor called" << std::endl;
}

double AP3216C::read() const
{
    return this->lux_;
}

std::string AP3216C::name() const
{
    return "AP3216C";
}

ISensorType AP3216C::sensorType() const
{
    return ISensorType::Light;
}
