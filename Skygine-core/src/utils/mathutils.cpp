#include "mathutils.h"

namespace stormengine
{
	namespace utils
	{

		float MathUtils::to_radians(float degrees)
		{
			return degrees * (M_PI / 180.0f);
		}

	}
}