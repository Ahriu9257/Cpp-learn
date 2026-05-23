//
// Created by ahriu on 2026/5/23.
//
#include "AP3216Csensor.h"

#include <iostream>
#include <ostream>

AP3216C::AP3216C()
    : lux_(0.0f), ir_(0), ps_(0)
{
    std::cout << "AP3216C sensor constructed!" << std::endl;
}

void AP3216C::read()
{
    // 先用固定值模拟 AP3216C 的一次读数。
    this->lux_ = 123.3f;
    this->ir_ = 100;
    this->ps_ = 200;

    std::cout << "AP3216C Data: " << std::endl;
    std::cout << "LUX: " << this->lux_ << std::endl;
    std::cout << "IR: " << this->ir_ << std::endl;
    std::cout << "PS: " << this->ps_ << std::endl;
}

const char* AP3216C::name() const
{
    return "AP3216C";
}

AP3216C::~AP3216C()
{
    std::cout << "AP3216C destructed!" << std::endl;
}
