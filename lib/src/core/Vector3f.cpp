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

Vector3f& Vector3f::operator = (const Vector3f& other)
{
	return SetWithVector(other);
}

float Vector3f::Length() const 
{
	return sqrt(_x * _x + _y * _y + _z * _z);
}

float Vector3f::DotProduct(const Vector3f& vec) const
{
	return _x * vec.GetX() + _y * vec.GetY() + _z * vec.GetZ();
}

Vector3f Vector3f::CrossProduct(const Vector3f& vec) const
{
	float x = _y * vec.GetZ() - _z * vec.GetY();
	float y = _z * vec.GetX() - _x * vec.GetZ();
	float z = _z * vec.GetY() - _y * vec.GetX();
	return Vector3f(x, y, z);
}

Vector3f& Vector3f::Normalize()
{
	float length = Length();
	_x /= length;
	_y /= length;
	_z /= length;

	return (*this);
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

Vector3f& Vector3f::SetX(float x)
{
	_x = x;
	return *this;
}

Vector3f& Vector3f::SetY(float y)
{
	_y = y;
	return *this;
}

Vector3f& Vector3f::SetZ(float z)
{
	_z = z;
	return *this;
}

Vector3f& Vector3f::SetXYZ(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
	return *this;
}

Vector3f& Vector3f::SetWithValue(float val)
{
	_x = val;
	_y = val;
	_z = val;
	return *this;
}

Vector3f& Vector3f::SetWithVector(const Vector3f& vector)
{
	_x = vector._x;
	_y = vector._y;
	_z = vector._z;
	return *this;
}

Vector3f Vector3f::ToNegatve() const
{
	return Vector3f(-GetX(), -GetY(), -GetZ());
}

Vector3f& Vector3f::AddWithValue(const float val)
{
	_x += val;
	_y += val;
	_z += val;
	return *this;
}

Vector3f& Vector3f::AddWithVector(const Vector3f& other)
{
	_x += other._x;
	_y += other._y;
	_z += other._z;
	return *this;
}

Vector3f& Vector3f::SubWithValue(const float val)
{
	_x -= val;
	_y -= val;
	_z -= val;
	return *this;
}

Vector3f& Vector3f::SubWithVector(const Vector3f& other)
{
	_x -= other._x;
	_y -= other._y;
	_z -= other._z;
	return *this;
}

Vector3f& Vector3f::MulWithValue(const float val)
{
	_x *= val;
	_y *= val;
	_z *= val;
	return *this;
}

Vector3f& Vector3f::MulWithVector(const Vector3f& other)
{
	_x *= other._x;
	_y *= other._y;
	_z *= other._z;
	return *this;
}

Vector3f& Vector3f::DivWithValue(const float val)
{
	_x /= val;
	_y /= val;
	_z /= val;
	return *this;
}

Vector3f& Vector3f::DivWithVector(const Vector3f& other)
{
	_x /= other._x;
	_y /= other._y;
	_z /= other._z;
	return *this;
}

	
