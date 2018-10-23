#include "vect4.h"

namespace stormengine
{
	namespace maths
	{

		Vect4::Vect4(const float& x, const float& y, const float& z, const float& w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vect4 Vect4::operator+=(const Vect4& other)
		{
			return add(other);
		}

		Vect4 Vect4::operator-=(const Vect4& other)
		{
			return subtract(other);
		}

		Vect4 Vect4::operator*=(const Vect4& other)
		{
			return multiply(other);
		}

		Vect4 Vect4::operator/=(const Vect4& other)
		{
			return divide(other);
		}

		bool Vect4::operator==(const Vect4& other)
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		bool Vect4::operator!=(const Vect4& other)
		{
			return !(*this == other);
		}

		Vect4& operator+(Vect4 left, const Vect4& right) {
			return left.add(right);
		}

		Vect4& operator-(Vect4 left, const Vect4& right) {
			return left.subtract(right);
		}

		Vect4& operator*(Vect4 left, const Vect4& right) {
			return left.multiply(right);
		}

		Vect4& operator/(Vect4 left, const Vect4& right)
		{
			return left.divide(right);
		}

		std::ostream& operator<<(std::ostream& stream, const Vect4 vector)
		{
			stream << "Vector3D(" << vector.x << ", " << vector.y <<
				", " << vector.z << ", " << vector.w << ")";
			return stream;
		}

		Vect4& Vect4::add(const Vect4& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		Vect4& Vect4::subtract(const Vect4& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		Vect4& Vect4::multiply(const Vect4& other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		Vect4& Vect4::divide(const Vect4& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

	}
}
