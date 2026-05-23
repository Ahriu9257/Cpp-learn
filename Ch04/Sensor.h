//
// Created by ahriu on 2026/5/23.
//

#ifndef CPP_LEARN_SENSOR_H
#define CPP_LEARN_SENSOR_H

#pragma once
#include <cstdint>

class Sensor
{
public:
    // 设置一次模拟传感器读数。
    void set(float lux, uint16_t ir, uint16_t ps);

    // print 不修改对象状态，因此声明为 const 成员函数。
    void print() const;

private:
    float lux_;
    uint16_t ir_;
    uint16_t ps_;
};

#endif //CPP_LEARN_SENSOR_H
