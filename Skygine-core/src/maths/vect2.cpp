#include "vect2.h"

namespace stormengine
{
	namespace maths
	{

		Vect2::Vect2()
		{
			// TODO: Call self contructor passing .0f (don't know why it doesn't work)
			this->x = .0f;
			this->y = .0f;
		}

		Vect2::Vect2(const float& x, const float& y)
		{
			this->x = x;
			this->y = y;
		}

		Vect2 Vect2::operator+=(const Vect2& other)
		{
			return add(other);
		}

		Vect2 Vect2::operator-=(const Vect2& other)
		{
			return subtract(other);
		}

		Vect2 Vect2::operator*=(const Vect2& other)
		{
			return multiply(other);
		}

		Vect2 Vect2::operator/=(const Vect2& other)
		{
			return divide(other);
		}

		bool Vect2::operator==(const Vect2& other)
		{
			return x == other.x && y == other.y;
		}

		bool Vect2::operator!=(const Vect2& other)
		{
			return !(*this == other);
		}

		Vect2& operator+(Vect2 left, const Vect2& right)
		{
			return left.add(right);
		}

		Vect2& operator-(Vect2 left, const Vect2& right)
		{
			return left.subtract(right);
		}

		Vect2& operator*(Vect2 left, const Vect2& right)
		{
			return left.multiply(right);
		}

		Vect2& operator/(Vect2 left, const Vect2& right)
		{
			return left.divide(right);
		}

		std::ostream& operator<<(std::ostream& stream, const Vect2 vector)
		{
			stream << "Vector2D(" << vector.x << ", " << vector.y << ")";
			return stream;
		}

		Vect2& Vect2::add(const Vect2& other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		Vect2& Vect2::subtract(const Vect2& other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vect2& Vect2::multiply(const Vect2& other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		Vect2& Vect2::divide(const Vect2& other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

	}
}
