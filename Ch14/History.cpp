//
// Created by ahriu on 2026/5/27.
//
#include "History.h"

#include <algorithm>
#include <iostream>
#include <numeric>
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
    if (data_.empty())
    {
        return 0.0;
    }
    float sum = std::accumulate(data_.begin(), data_.end(), 0.0);

    return sum / static_cast<float>(data_.size());
}

std::size_t History::count_above(float threshold) const
{
    return static_cast<std::size_t>(
        std::count_if(data_.begin(),data_.end(),
                [threshold](float value)
                {return value > threshold;}));
}

std::vector<float> History::sort_copy() const
{
    std::vector<float> copy = data_;
    std::sort(copy.begin(), copy.end());
    return copy;
}

const std::vector<float>& History::get_data() const
{
    return data_;
}