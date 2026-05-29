#include "Statistics.h"
#include "mathlib.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace
{
bool expect_near(double actual, double expected, double eps, const char* label)
{
    if (std::fabs(actual - expected) > eps)
    {
        std::cerr << label << " failed: actual=" << actual
                  << ", expected=" << expected << std::endl;
        return false;
    }

    return true;
}
}

int main()
{
    const double raw[] = {1.0, 2.0, 3.0, 4.0};

    if (!expect_near(mathlib_mean(raw, 4), 2.5, 1e-9, "C mean"))
    {
        return 1;
    }

    Statistics stats({1.0, 2.0, 3.0, 4.0});
    if (stats.size() != 4)
    {
        std::cerr << "Statistics size failed" << std::endl;
        return 1;
    }

    if (!expect_near(stats.mean(), 2.5, 1e-9, "C++ wrapper mean"))
    {
        return 1;
    }

    if (!expect_near(stats.stddev(), std::sqrt(1.25), 1e-9, "C++ wrapper stddev"))
    {
        return 1;
    }

    try
    {
        Statistics empty({});
        (void)empty;
        std::cerr << "empty Statistics should throw" << std::endl;
        return 1;
    }
    catch (const std::invalid_argument&)
    {
    }

    std::cout << "Ch24 C/C++ interop test passed" << std::endl;
    return 0;
}
