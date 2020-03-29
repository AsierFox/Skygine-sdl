#include "MathUtils.h"

void MathUtils::clamp(float& n, float min, float max)
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
