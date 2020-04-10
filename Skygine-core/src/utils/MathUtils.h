#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

#include "../physics/Point.h"

struct MathUtils
{
	static void clampInt(int& n, int min, int max);
	static void clampFloat(float& n, float min, float max);
	static double getDistanceBetweenCoords(Point* a, Point* b);
	static bool isInRadius(Point* a, Point* b, int radius);
	static float to_radians(float degrees);
};
