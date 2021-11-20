#pragma once
#include <iostream>
#include <cmath>

template<class T>
class Vector2d
{
public:
	T x;
	T y;

	//Constructor assigns the inputs to x and y.
	Vector2d() : x(T(0)), y(T(0)) {};
	Vector2d(const T& vx, const T& vy) : x(vx), y(vy) {};

	/*The following operators simply return Vector2ds that
	  have operations performed on the relative (x, y) values*/
	Vector2d& operator+=(const Vector2d& v) { x += v.x; y += v.y; return *this; }
	Vector2d& operator-=(const Vector2d& v) { x -= v.x; y -= v.y; return *this; }
	Vector2d& operator*=(const Vector2d& v) { x *= v.x; y *= v.y; return *this; }
	Vector2d& operator/=(const Vector2d& v) { x /= v.x; y /= v.y; return *this; }

	//Apply scalar operations.
	Vector2d& operator*=(const T& s) { x *= s; y *= s; return *this; }
	Vector2d& operator/=(const T& s) { x /= s; y /= s; return *this; }

	//Negate both the x and y values.
	Vector2d operator-() const { return Vector2d(-x, -y); }

	double magnitude() { return sqrt(x * x + y * y); }
	double dotProduct(const Vector2d& v) { return this->x * v.x + this->y * v.y; }
	void normalise() {
		double mag = this->magnitude();
		x = x / mag;
		y = y / mag;
	}

	//Check if the Vectors have the same values (uses pairwise comparison of `std::tuple` on the x,y values of L and R.


	friend bool operator==(const Vector2d& L, const Vector2d& R) { return (L.x == R.x) and (L.y == R.y); }
	friend bool operator!=(const Vector2d& L, const Vector2d& R) { return !(L == R); }


	friend std::ostream& operator<<(std::ostream& os, const Vector2d& v) { os << "(" << v.x << "," << v.y << ")"; return os; }
};

template<class T> Vector2d<T> operator+(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) += R; }
template<class T> Vector2d<T> operator-(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) -= R; }
template<class T> Vector2d<T> operator*(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) *= R; }
template<class T> Vector2d<T> operator/(const Vector2d<T>& L, const Vector2d<T>& R) { return Vector2d<T>(L) /= R; }

template<class T> Vector2d<T> operator*(const T& s, const Vector2d<T>& v) { return Vector2d<T>(v) *= s; }
template<class T> Vector2d<T> operator*(const Vector2d<T>& v, const T& s) { return Vector2d<T>(v) *= s; }
template<class T> Vector2d<T> operator/(const T& s, const Vector2d<T>& v) { return Vector2d<T>(v) /= s; }
template<class T> Vector2d<T> operator/(const Vector2d<T>& v, const T& s) { return Vector2d<T>(v) /= s; }