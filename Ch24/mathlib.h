#ifndef CH24_MATHLIB_H
#define CH24_MATHLIB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

double mathlib_mean(const double* arr, size_t n);
double mathlib_stddev(const double* arr, size_t n);

#ifdef __cplusplus
}
#endif

#endif
