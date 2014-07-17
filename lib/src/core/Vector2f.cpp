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

float Vector2f::Length() const 
{
	return sqrt(_x * _x + _y * _y);
}

float Vector2f::DotProduct(const Vector2f& other) const
{
	return _x * other._x + _y * other._y;
}

Vector2f& Vector2f::Normalize()
{
	float length = Length();
	_x /= length;
	_y /= length;

	return *this;
}

Vector2f& Vector2f::Rotate(float degree)
{
	float rad = degree * PI / 180;
	float cosine = cos(rad);
	float sine =  sin(rad);

	return Vector2f(_x * cosine - _y * sine, _x * sine + _y * cosine);
}

const float Vector2f::GetX() const
{
	return _x;
}

const float Vector2f::GetY() const
{
	return _y;
}

Vector2f Vector2f::operator - ()
{
	return Vector2f(-_x, -_y);
}

Vector2f Vector2f::operator + (const Vector2f& other)
{
	return Vector2f(_x + other._x, _y + other._y);
}

Vector2f& Vector2f::operator += (const Vector2f& other)
{
	_x += other._x;
	_y += other._y;

	return *this;
}

Vector2f Vector2f::operator - (const Vector2f& other)
{
	return Vector2f(_x - other._x, _y - other._y);
}

Vector2f& Vector2f::operator -= (const Vector2f& other)
{
	_x -= other._x;
	_y -= other._y;

	return *this;
}

Vector2f Vector2f::operator * (float value)
{
	return Vector2f(_x * value, _y * value);
}

Vector2f& Vector2f::operator *= (float value)
{
	_x *= value;
	_y *= value;
	
	return *this;
}

Vector2f Vector2f::operator / (float value)
{
	return Vector2f(_x / value, _y / value);
}

Vector2f& Vector2f::operator /= (float value)
{
	_x /= value;
	_y /= value;

	return *this;
}

Vector2f& Vector2f::operator = (const Vector2f& other)
{
	_x = other._x;
	_y = other._y;

	return *this;
}

