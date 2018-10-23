#pragma once

#include <iostream>

#include "../src/maths/matr4.h"
#include "../src/maths/vect4.h"

using namespace stormengine;
using namespace maths;

namespace stormengine
{
	namespace test
	{
		
		struct Matr4Spec
		{
		
			static void sumMatrixShouldMultiply()
			{
				std::cout << "Matr4Spec.sumMatrixShouldMultiply" << std::endl;

				Matr4 matrA = Matr4::get_translation(Vect3(2, 3, 4));
				matrA *= Matr4::get_identity();

				Matr4 resultAssert = Matr4::get_translation(Vect3(2, 3, 4));

				bool assert = resultAssert == matrA;

				std::cout << "Matrix multiplied by 1: " << assert << std::endl;
			}

			static void matrixShouldGetSameCorrectColumnWithUnion()
			{
				std::cout << "Matr4Spec.matrixShouldGetSameCorrectColumnWithUnion" << std::endl;

				Matr4 matr = Matr4::get_translation(Vect3(2, 3, 4));

				Vect4 columnUnionArray = matr.columns[3];
				Vect4 columnMethodVect4 = matr.getColumn(3);

				std::cout << "Get column by Union: " << columnUnionArray << std::endl;
				std::cout << "Get column by Method: " << columnMethodVect4 << std::endl;
				std::cout << "Union Array top,right value: " << matr.elements[12] << std::endl;
				std::cout << "Union Vect4 top,right value: " << matr.columns[3].x << std::endl;

				bool assert = &matr.elements[12] == &matr.columns[3].x;

				std::cout << "Should be same memory address with union: " << assert << std::endl;
			}
		
		};

	}
}
