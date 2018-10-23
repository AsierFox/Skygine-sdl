#pragma once

#include <iostream>

namespace stormengine {
	namespace maths {

		struct Vect2 {
			float x;
			float y;

			Vect2();
			Vect2(const float& x, const float& y);

			Vect2 operator+=(const Vect2& other);
			Vect2 operator-=(const Vect2& other);
			Vect2 operator*=(const Vect2& other);
			Vect2 operator/=(const Vect2& other);

			bool operator==(const Vect2& other);
			bool operator!=(const Vect2& other);

			friend Vect2& operator+(Vect2 left, const Vect2& right);
			friend Vect2& operator-(Vect2 left, const Vect2& right);
			friend Vect2& operator*(Vect2 left, const Vect2& right);
			friend Vect2& operator/(Vect2 left, const Vect2& right);

			friend std::ostream& operator<<(std::ostream& stream, const Vect2 vector);

		private:
			Vect2& add(const Vect2& other);
			Vect2& subtract(const Vect2& other);
			Vect2& multiply(const Vect2& other);
			Vect2& divide(const Vect2& other);
		};

	}
}
