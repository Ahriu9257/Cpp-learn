//
// Created by ahriu on 2026/5/23.
//

#ifndef CH05SENSOR_ISENSOR_H
#define CH05SENSOR_ISENSOR_H

#pragma once

class ISensor
{
public:
    // 基类通过指针删除派生类对象时，析构函数必须是 virtual。
    virtual ~ISensor() = default;

    virtual double read() = 0;

    virtual std::string name() const = 0;
};

#endif //CH05SENSOR_ISENSOR_H
