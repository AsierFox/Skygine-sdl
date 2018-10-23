#include "matr4.h"

namespace stormengine
{
	namespace maths
	{

		Matr4::Matr4()
		{
			// We can also use memset() to set the values trough memory
			for (int i = 0; i < MATRIX_LENGTH; i++)
			{
				elements[i] = .0f;
			}
		}

		Matr4::Matr4(float diagonalValue)
		{
			for (int i = 0; i < MATRIX_LENGTH; i++)
			{
				elements[i] = .0f;
			}
			elements[0 + 0 * 4] = diagonalValue;
			elements[1 + 1 * 4] = diagonalValue;
			elements[2 + 2 * 4] = diagonalValue;
			elements[3 + 3 * 4] = diagonalValue;
		}

		float Matr4::getValue(int index)
		{
			if (index >= MATRIX_LENGTH)
			{
				// TODO: Print error || throw exception
				std::cout << "Can't get index (" << index << ") from matrix, outbounds!" << std::endl;
			}

			return elements[index];
		}

		float Matr4::getValue(int row, int col)
		{
			return getValue(row + col * MATRIX_WIDTH);
		}

		void Matr4::setValue(int row, int col, float value)
		{
			elements[row + col * MATRIX_WIDTH] = value;
		}

		Vect4 Matr4::getColumn(int column)
		{
			column *= 4;
			return Vect4(elements[column], getValue(column + 1), getValue(column + 2), getValue(column + 3));
		}

		Matr4& Matr4::multiply(const Matr4& other)
		{
			for (int y = 0; y < MATRIX_WIDTH; y++)
			{
				for (int x = 0; x < MATRIX_WIDTH; x++)
				{
					float sum = .0f;

					for (int i = 0; i < MATRIX_WIDTH; i++)
					{
						// TODO: Why other.getValue(i, y) doesn't work
						sum += getValue(x, i) * other.elements[i + y * MATRIX_WIDTH];
					}

					elements[x + y * MATRIX_WIDTH] = sum;
				}
			}
			return *this;
		}

		Matr4 Matr4::operator*=(const Matr4& other)
		{
			return multiply(other);
		}

		bool Matr4::operator==(const Matr4& other)
		{
			for (int i = 0; i < MATRIX_LENGTH; i++)
			{
				if (elements[i] != other.elements[i])
				{
					return false;
				}
			}
			return true;
		}

		bool Matr4::operator!=(const Matr4& other)
		{
			return !(*this == other);
		}

		Matr4& operator*(Matr4 left, const Matr4& right)
		{
			return left.multiply(right);
		}

		// TODO: Implement this
		std::ostream& operator<<(std::ostream& stream, const Matr4 matrix)
		{
			stream << "Peding to implement Matrix printing.";
			return stream;
		}

		Matr4 Matr4::get_identity()
		{
			return Matr4(1.0f);
		}

		Matr4 Matr4::get_orthograhic(float left, float right, float top, float bottom, float near, float far)
		{
			Matr4 result(1.0f);

			result.setValue(0, 0, 2.0f / (right - left));
			result.setValue(1, 1, 2.0f / (bottom - top));
			result.setValue(2, 2, 2.0f / (near - far));

			result.setValue(0, 3, (left + right) / (left - right));
			result.setValue(1, 3, (top + bottom) / (top - bottom));
			result.setValue(2, 3, (far + near) / (far - near));

			return result;
		}

		Matr4 Matr4::get_perspective(float fov, float aspectRatio, float near, float far)
		{
			Matr4 result(1.0f);

			float a = 1.0f / tan(MathUtils::to_radians(.5f * fov));
			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.setValue(0, 0, a / aspectRatio);
			result.setValue(1, 1, a);
			result.setValue(2, 2, b);
			result.setValue(3, 2, -1.0f);
			result.setValue(2, 3, c);

			return result;
		}

		Matr4 Matr4::get_translation(const Vect3& translation)
		{
			Matr4 result(1.0f);

			result.setValue(0, 3, translation.x);
			result.setValue(1, 3, translation.y);
			result.setValue(2, 3, translation.z);

			return result;
		}

		Matr4 Matr4::get_rotation(float angle, const Vect3& axis)
		{
			Matr4 result(1.0f);

			float radians = MathUtils::to_radians(angle);
			float c = cos(radians);
			float s = sin(radians);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			// Operate by colums
			result.setValue(0, 0, x * omc + c);
			result.setValue(1, 0, y * x * omc + z * s);
			result.setValue(2, 0, x * z * omc - y * s);

			result.setValue(0, 1, x * y * omc - z * s);
			result.setValue(1, 1, y * omc + c);
			result.setValue(2, 1, y * z * omc + x * s);

			result.setValue(0, 2, x * z * omc + y * s);
			result.setValue(1, 2, y * z * omc - x * s);
			result.setValue(2, 2, z * omc + c);

			return result;
		}

		Matr4 Matr4::get_scale(const Vect3& scale)
		{
			Matr4 result(1.0f);

			result.setValue(0, 0, scale.x);
			result.setValue(1, 1, scale.y);
			result.setValue(2, 2, scale.z);

			return result;
		}

	}
}
