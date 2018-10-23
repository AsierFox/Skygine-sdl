#include "vect3.h"

namespace stormengine {
	namespace maths {

		Vect3::Vect3() {
			Vect3(.0f, .0f, .0f);
		}

		Vect3::Vect3(const float& x, const float& y, const float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vect3 Vect3::operator+=(const Vect3& other) {
			return add(other);
		}

		Vect3 Vect3::operator-=(const Vect3& other) {
			return subtract(other);
		}

		Vect3 Vect3::operator*=(const Vect3& other) {
			return multiply(other);
		}

		Vect3 Vect3::operator/=(const Vect3& other)
		{
			return divide(other);
		}

		bool Vect3::operator==(const Vect3& other)
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool Vect3::operator!=(const Vect3& other)
		{
			return !(*this == other);
		}

		Vect3& operator+(Vect3 left, const Vect3& right) {
			return left.add(right);
		}

		Vect3& operator-(Vect3 left, const Vect3& right) {
			return left.subtract(right);
		}

		Vect3& operator*(Vect3 left, const Vect3& right) {
			return left.multiply(right);
		}

		Vect3& operator/(Vect3 left, const Vect3& right) {
			return left.divide(right);
		}

		std::ostream& operator<<(std::ostream& stream, const Vect3 vector) {
			stream << "Vector3D(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
			return stream;
		}

		Vect3& Vect3::add(const Vect3& other) {
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		Vect3& Vect3::subtract(const Vect3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		Vect3& Vect3::multiply(const Vect3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		Vect3& Vect3::divide(const Vect3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

	}
}
