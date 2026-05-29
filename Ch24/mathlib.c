#include "mathlib.h"

#include <math.h>
#include <stddef.h>

double mathlib_mean(const double* arr, size_t n)
{
    if (arr == NULL || n == 0)
    {
        return 0.0;
    }

    double sum = 0.0;
    for (size_t i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    return sum / (double)n;
}

double mathlib_stddev(const double* arr, size_t n)
{
    if (arr == NULL || n == 0)
    {
        return 0.0;
    }

    const double mean = mathlib_mean(arr, n);
    double squared_sum = 0.0;

    for (size_t i = 0; i < n; ++i)
    {
        const double diff = arr[i] - mean;
        squared_sum += diff * diff;
    }

    return sqrt(squared_sum / (double)n);
}
