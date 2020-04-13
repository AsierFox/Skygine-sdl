#include "MathUtils.h"

void MathUtils::clampInt(int& n, int min, int max)
{
	if (n < min)
	{
		n = min;
	}
	else if (n > max)
	{
		n = max;
	}
}

void MathUtils::clampFloat(float& n, float min, float max)
{
	if (n < min)
	{
		n = min;
	}
	else if (n > max)
	{
		n = max;
	}
}

double MathUtils::getDistanceBetweenCoords(Point* a, Point* b)
{
	double dx = std::abs(a->x - b->x);
	double dy = std::abs(a->y - b->y);

	return std::sqrt((dx * dx) + (dy * dy));
}

bool MathUtils::isInRadius(Point* a, Point* b, int radius)
{
	double distance = getDistanceBetweenCoords(a, b);

	return distance <= radius;
}

float MathUtils::to_radians(float degrees)
{
	return degrees * (M_PI / 180.0f);
}

int MathUtils::getRandomNumber(int from, int to)
{
	if (from == 0)
	{
		return rand() % to;
	}
	return rand() % from + to;
}
