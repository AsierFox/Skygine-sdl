#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

struct MathUtils
{
	static void clamp(float& n, float min, float max);
	static float to_radians(float degrees);
};
