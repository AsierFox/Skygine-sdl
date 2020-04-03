#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

struct MathUtils
{
	static void clampInt(int& n, int min, int max);
	static void clampFloat(float& n, float min, float max);
	static float to_radians(float degrees);
};
