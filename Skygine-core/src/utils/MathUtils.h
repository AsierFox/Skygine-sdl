#pragma once

#include <iostream>

#include <SDL.h>

#include "../physics/Point.h"

#define _USE_MATH_DEFINES

struct MathUtils
{
	static void clampInt(int& n, int min, int max);
	static void clampFloat(float& n, float min, float max);
	static double getDistanceBetweenCoords(Point* a, Point* b);
	static bool isInRadius(Point* a, Point* b, int radius);
	static float to_radians(float degrees);
	static int getRandomNumber(int from, int to);
};
