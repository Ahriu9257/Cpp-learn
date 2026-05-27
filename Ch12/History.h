//
// Created by ahriu on 2026/5/27.
//

#ifndef CH06SENSORS_HISTORY_H
#define CH06SENSORS_HISTORY_H

#pragma once
#include <cstddef>
#include <vector>

class History
{
public:
    explicit History(std::size_t capacity); //最大容量

    void push(float value); //加入一个新值

    float average() const;

    void print() const;

    std::size_t size() const;

    std::size_t capacity() const;

private:
    std::vector<float> data_;

    std::size_t capacity_;
};

#endif //CH06SENSORS_HISTORY_H
