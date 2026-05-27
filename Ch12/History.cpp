//
// Created by ahriu on 2026/5/27.
//
#include "History.h"

#include <iostream>
#include <ostream>

History::History(std::size_t capacity)
    :capacity_(capacity)
{
    data_.reserve(capacity_);
}

void History::push(float value)
{
    if (capacity_ == 0)
    {
        return;
    }

    if (data_.size() >= capacity_)
    {
        data_.erase(data_.begin());
    }
    data_.push_back(value);
}

float History::average() const
{
    if (capacity_ == 0)
    {
        return 0;
    }
    float sum = 0;
    for (float data : data_)
    {
        sum += data;
    }

    return sum / data_.size();
}

void History::print() const
{
    std::cout << "History data : " << std::endl;

    for (float data : data_)
    {
        std::cout << data << std::endl;
    }
}

std::size_t History::size() const
{
    return data_.size();
}

std::size_t History::capacity() const
{
    return capacity_;
}