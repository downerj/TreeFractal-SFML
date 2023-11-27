#ifndef MATH_HXX
#define MATH_HXX

#ifdef _WIN32
#define _USE_MATH_DEFINES
#include <math.h>
#else
#include <cmath>
#endif // _WIN32

constexpr auto tau = static_cast<float>(M_PI) * 2.f;
constexpr auto degToRad = tau / 360.f;

#endif // MATH_HXX
