#pragma once

#include <cstddef>
#include <vector>

class Statistics
{
public:
    explicit Statistics(std::vector<double> values);

    std::size_t size() const;
    double mean() const;
    double stddev() const;

private:
    std::vector<double> values_;
};
