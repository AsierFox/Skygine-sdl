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

float MathUtils::to_radians(float degrees)
{
	return degrees * (M_PI / 180.0f);
}
