#pragma once

#include <iostream>

namespace stormengine {
	namespace maths {

		struct Vect3 {
			float x;
			float y;
			float z;

			Vect3();
			Vect3(const float& x, const float& y, const float& z);

			Vect3 operator+=(const Vect3& other);
			Vect3 operator-=(const Vect3& other);
			Vect3 operator*=(const Vect3& other);
			Vect3 operator/=(const Vect3& other);

			bool operator==(const Vect3& other);
			bool operator!=(const Vect3& other);

			friend Vect3& operator+(Vect3 left, const Vect3& right);
			friend Vect3& operator-(Vect3 left, const Vect3& right);
			friend Vect3& operator*(Vect3 left, const Vect3& right);
			friend Vect3& operator/(Vect3 left, const Vect3& right);

			friend std::ostream& operator<<(std::ostream& stream, const Vect3 vector);

		private:
			Vect3& add(const Vect3& other);
			Vect3& subtract(const Vect3& other);
			Vect3& multiply(const Vect3& other);
			Vect3& divide(const Vect3& other);
		};

	}
}
