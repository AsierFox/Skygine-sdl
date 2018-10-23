#pragma once

#include <iostream>

#include "vect2spec.h"
#include "matr4spec.h"
#include "fileutilsspec.h"

namespace stormengine
{
	namespace test
	{

		struct Test
		{
			static void test()
			{
				Vect2Spec::sumVectorsShouldSum();

				Matr4Spec::sumMatrixShouldMultiply();
				Matr4Spec::matrixShouldGetSameCorrectColumnWithUnion();

				FileUtilsSpec::shouldReadMainFile();

				system("pause");
			}
		};

	}
}
