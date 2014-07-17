#include <math.h>

#include "Vector3f.h"

//TO DO Move define to another place
#define PI 3.14159265

using namespace blaze;

Vector3f::Vector3f()
	: _x(0)
	, _y(0)
	, _z(0)
{
}

Vector3f::Vector3f(float x, float y, float z)
	: _x(x)
	, _y(y)
	, _z(z)
{
}

Vector3f::Vector3f(const Vector3f& other)
	: _x(other._x)
	, _y(other._y)
	, _z(other._z)
{
}

float Vector3f::Length() const 
{
	return sqrt(_x * _x + _y * _y + _z * _z);
}

float Vector3f::DotProduct(const Vector3f& other) const
{
	return _x * other._x + _y * other._y + _z * other._z;
}

Vector3f Vector3f::CrossProduct(const Vector3f& other) const
{
	return Vector3f(_y * other._z - _z * other._y, 
					_z * other._x - _x * other._z, 
					_z * other._y - _y * other._x);
}

Vector3f& Vector3f::Normalize()
{
	float length = Length();
	_x /= length;
	_y /= length;
	_z /= length;

	return *this;
}

Vector3f& Vector3f::Rotate(float degree)
{
	//TODO implement this
	return (*this);
}


const float Vector3f::GetX() const
{
	return _x;
}

const float Vector3f::GetY() const
{
	return _y;
}

const float Vector3f::GetZ() const
{
	return _z;
}

Vector3f Vector3f::operator - ()
{
	return Vector3f(-_x, -_y, -_z);
}

Vector3f Vector3f::operator + (const Vector3f& other)
{
	return Vector3f(_x + other._x, _y + other._y, _z + other._z);
}

Vector3f& Vector3f::operator += (const Vector3f& other)
{
	_x += other._x;
	_y += other._y;
	_z += other._z;

	return *this;
}

Vector3f Vector3f::operator - (const Vector3f& other)
{
	return Vector3f(_x - other._x, _y - other._y, _z - other._z);
}

Vector3f& Vector3f::operator -= (const Vector3f& other)
{
	_x -= other._x;
	_y -= other._y;
	_z -= other._z;

	return *this;
}

Vector3f Vector3f::operator * (float value)
{
	return Vector3f(_x * value, _y * value, _z * value);
}

Vector3f& Vector3f::operator *= (float value)
{
	_x *= value;
	_y *= value;
	_z *= value;

	return *this;
}

Vector3f Vector3f::operator / (float value)
{
	return Vector3f(_x / value, _y / value, _z / value);
}

Vector3f& Vector3f::operator /= (float value)
{
	_x /= value;
	_y /= value;
	_z /= value;

	return *this;
}

Vector3f& Vector3f::operator = (const Vector3f& other)
{
	_x = other._x;
	_y = other._y;
	_z = other._z;

	return *this;
}

