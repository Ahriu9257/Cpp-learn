//
// Created by ahriu on 2026/5/23.
//
#include "AP3216Csensor.h"

#include <iostream>
#include <ostream>

AP3216C::AP3216C()
    : lux_(123.4)
{
    std::cout << "AP3216C sensor constructed!" << std::endl;
}

double AP3216C::read()
{
    this->lux_ += 1.0;
    return lux_;
}

std::string AP3216C::name() const
{
    return "AP3216C Light Sensor";
}

AP3216C::~AP3216C()
{
    std::cout << "AP3216C destructed!" << std::endl;
}
