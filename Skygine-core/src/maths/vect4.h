#pragma once

#include <iostream>

namespace stormengine {
	namespace maths {

		struct Vect4 {
			float x;
			float y;
			float z;
			float w;

			// Use system lowlevel default constructor, for using union at matr4 class
			Vect4() = default;
			Vect4(const float& x, const float& y, const float& z, const float& w);

			Vect4 operator+=(const Vect4& other);
			Vect4 operator-=(const Vect4& other);
			Vect4 operator*=(const Vect4& other);
			Vect4 operator/=(const Vect4& other);

			bool operator==(const Vect4& other);
			bool operator!=(const Vect4& other);

			friend Vect4& operator+(Vect4 left, const Vect4& right);
			friend Vect4& operator-(Vect4 left, const Vect4& right);
			friend Vect4& operator*(Vect4 left, const Vect4& right);
			friend Vect4& operator/(Vect4 left, const Vect4& right);

			friend std::ostream& operator<<(std::ostream& stream, const Vect4 vector);

		private:
			Vect4& add(const Vect4& other);
			Vect4& subtract(const Vect4& other);
			Vect4& multiply(const Vect4& other);
			Vect4& divide(const Vect4& other);
		};

	}
}
