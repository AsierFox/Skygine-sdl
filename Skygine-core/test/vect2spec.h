#pragma once

#include <iostream>

#include "../src/maths/vect2.h"

using namespace stormengine;
using namespace maths;

namespace stormengine
{
	namespace test
	{

		struct Vect2Spec
		{
			static void sumVectorsShouldSum()
			{
				std::cout << "Vect2Spec.sumVectorsShouldSum" << std::endl;

				Vect2 vectA;
				Vect2 vectB(1, 1);
				Vect2 result = vectA + vectB;

				Vect2 vect2RestultAssert(1, 1);

				std::cout << result << std::endl;
				std::cout << vect2RestultAssert << std::endl;

				std::cout << "Is correct operator sum " << (vect2RestultAssert == result) << std::endl;
			}

		private:
			static void sumOperatorShouldSum(Vect2 vect)
			{
				//
			}
		};

	}
}
