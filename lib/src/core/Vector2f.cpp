#include <math.h>

#include "Vector2f.h"

//TO DO Move define to another place
#define PI 3.14159265

using namespace blaze;

Vector2f::Vector2f()
	: _x(0)
	, _y(0)
{
}

Vector2f::Vector2f(float x, float y)
	: _x(x)
	, _y(y)
{
}

Vector2f::Vector2f(const Vector2f& other)
	: _x(other._x)
	, _y(other._y)
{
}

Vector2f& Vector2f::operator = (const Vector2f& other)
{
	return SetWithVector(other);
}


float Vector2f::Length() const 
{
	return sqrt(_x * _x + _y * _y);
}

float Vector2f::DotProduct(const Vector2f& vec) const
{
	return _x * vec.GetX() + _y * vec.GetY();
}

Vector2f& Vector2f::Normalize()
{
	float length = Length();
	_x  /= length;
	_y /= length;

	return (*this);
}

Vector2f& Vector2f::Rotate(float degree)
{
	float rad = degree * PI / 180;
	float cosine = cos(rad);
	float sine =  sin(rad);

	SetXY(_x * cosine - _y * sine, _x * sine + _y * cosine);
	return (*this);
}


const float Vector2f::GetX() const
{
	return _x;
}

const float Vector2f::GetY() const
{
	return _y;
}

Vector2f& Vector2f::SetX(float x)
{
	_x = x;
	return *this;
}

Vector2f& Vector2f::SetY(float y)
{
	_y = y;
	return *this;
}

Vector2f& Vector2f::SetXY(float x, float y)
{
	_x = x;
	_y = y;
	return *this;
}

Vector2f& Vector2f::SetWithValue(float val)
{
	_x = val;
	_y = val;
	return *this;
}

Vector2f& Vector2f::SetWithVector(const Vector2f& vector)
{
	_x = vector._x;
	_y = vector._y;
	return *this;
}

Vector2f Vector2f::ToNegatve() const
{
	return Vector2f(-GetX(), -GetY());
}

Vector2f& Vector2f::AddWithValue(const float val)
{
	_x += val;
	_y += val;
	return *this;
}

Vector2f& Vector2f::AddWithVector(const Vector2f& other)
{
	_x += other._x;
	_y += other._y;
	return *this;
}

Vector2f& Vector2f::SubWithValue(const float val)
{
	_x -= val;
	_y -= val;
	return *this;
}

Vector2f& Vector2f::SubWithVector(const Vector2f& other)
{
	_x -= other._x;
	_y -= other._y;
	return *this;
}

Vector2f& Vector2f::MulWithValue(const float val)
{
	_x *= val;
	_y *= val;
	return *this;
}

Vector2f& Vector2f::MulWithVector(const Vector2f& other)
{
	_x *= other._x;
	_y *= other._y;
	return *this;
}

Vector2f& Vector2f::DivWithValue(const float val)
{
	_x /= val;
	_y /= val;
	return *this;
}

Vector2f& Vector2f::DivWithVector(const Vector2f& other)
{
	_x /= other._x;
	_y /= other._y;
	return *this;
}
