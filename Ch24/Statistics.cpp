#include "Statistics.h"

#include "mathlib.h"

#include <stdexcept>
#include <utility>

Statistics::Statistics(std::vector<double> values)
    : values_(std::move(values))
{
    if (values_.empty())
    {
        throw std::invalid_argument("Statistics needs at least one value");
    }
}

std::size_t Statistics::size() const
{
    return values_.size();
}

double Statistics::mean() const
{
    return mathlib_mean(values_.data(), values_.size());
}

double Statistics::stddev() const
{
    return mathlib_stddev(values_.data(), values_.size());
}
