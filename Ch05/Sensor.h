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
    Sensor() = default;

    // explicit 避免 float 被隐式转换成 Sensor 对象。
    explicit Sensor(float lux);
    Sensor(float lux, uint16_t ir, uint16_t ps);

    ~Sensor();

    void set(float lux,uint16_t ir,uint16_t ps);
    void print() const;

    Sensor(const Sensor&) = delete;
    Sensor& operator=(const Sensor&) = delete;

private:
    float lux_{0.0f};
    uint16_t ir_{0};
    uint16_t ps_{0};
};

#endif //CPP_LEARN_SENSOR_H
