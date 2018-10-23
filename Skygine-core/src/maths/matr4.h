#pragma once

#include <math.h>

#include "vect3.h"
#include "vect4.h"
#include "../utils/mathutils.h"

using namespace stormengine;
using namespace utils;

namespace stormengine {
	namespace maths {

#define MATRIX_LENGTH 16 // 4 * 4
#define MATRIX_WIDTH  4

		struct Matr4
		{
			/* Make Array & Vect4 pointing to same memory address,
			 * for efficient access & more polivalent structure access.
			 */
			union
			{
				float elements[MATRIX_LENGTH];
				Vect4 columns[MATRIX_WIDTH];
			};

			Matr4();
			Matr4(float diagonalValue);

			float getValue(int index);
			/* To get an element from the "matrix" by row/col, we are going to use:
			 * row + col * 4 (width)
			 */
			float getValue(int row, int col);
			void setValue(int row, int col, float value);

			/* Very ineficient! Don't use it! Just for testing purposes!
			 * This method creates a copy of the array in memory to return the column.
			 * We implemented union to access columns through Vect4 structures.
			 */
			Vect4 getColumn(int index);

			/* Multiply one matrix with another one.
			 *
			 * Using column major ordering, like so (OpenGL uses this ordering):
			 * - 0 4      -
			 * | 1 5      |
			 * | 2 ...    |
			 * - 3     15 -
			 */
			Matr4& multiply(const Matr4& other);

			Matr4 operator*=(const Matr4& other);
			bool operator==(const Matr4& other);
			bool operator!=(const Matr4& other);

			friend Matr4& operator*(Matr4 left, const Matr4& right);

			friend std::ostream& operator<<(std::ostream& stream, const Matr4 matrix);
			
			/* Get matrix with diagonal equals to 1.0f value.
			 */
			static Matr4 get_identity();
			/* Calculated using Orthographic matrix formula.
			 */
			static Matr4 get_orthograhic(float left, float right, float top, float bottom, float near, float far);
			/* Calculated using Perspective matrix formula.
			 */
			static Matr4 get_perspective(float fov, float aspectRatio, float near, float far);
			static Matr4 get_translation(const Vect3& translation);
			static Matr4 get_rotation(float angle, const Vect3& axis);
			static Matr4 get_scale(const Vect3& scale);
		};

	}
}
