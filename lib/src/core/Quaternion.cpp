#include <math.h>

#include "Quaternion.h"

using namespace blaze;

Quaternion::Quaternion()
	: _x(0)
	, _y(0)
	, _z(0)
	, _w(0)
{
}

Quaternion::Quaternion(float x, float y, float z, float w)
	: _x(x)
	, _y(y)
	, _z(z)
	, _w(w)
{
}

Quaternion::Quaternion(const Quaternion& other)
	: _x(other._x)
	, _y(other._y)
	, _z(other._z)
	, _w(other._w)
{
}

Quaternion& Quaternion::operator = (const Quaternion& other)
{
	return SetWithQuaternion(other);
}

float Quaternion::Length() const
{
	return sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
}

Quaternion& Quaternion::Normalize()
{
	float length = Length();
	_x /= length;
	_y /= length;
	_z /= length;
	_w /= length;

	return (*this);
}

Quaternion& Quaternion::Conjugate()
{
	return SetXYZW(-_x, -_y, -_z, _w);
}

Quaternion& Quaternion::MultiplyWithQuaternion(const Quaternion& other)
{
	//TODO find out what do the formula do
	float w = (_w * other._w) - (_x * other._x) - (_y * other._y) - (_z * other._z);
	float x = (_x * other._w) + (_w * other._x) + (_z * other._y) - (_y * other._z);
	float y = (_y * other._w) + (_w * other._y) + (_x * other._z) - (_z * other._x);
	float z = (_z * other._w) + (_w * other._z) + (_y * other._x) - (_x * other._z);
	return SetXYZW(x, y, z, w);
}

Quaternion& Quaternion::MultiplyWithVector3f(const Vector3f& other)
{
	//TODO find out what do the formula do
	float otherX = other.GetX();
	float otherY = other.GetY();
	float otherZ = other.GetZ();

	float w = (-_x * otherX) - (_y * otherY) - (_z * otherZ);
	float x = (_w * otherX) + (_z * otherY) - (_y * otherZ);
	float y = (_w * otherY) + (_x * otherZ) - (_z * otherX);
	float z = (_w * otherZ) + (_y * otherX) - (_x * otherZ);
	return SetXYZW(x, y, z, w);
}

const float Quaternion::GetX() const
{
	return _x;
}

const float Quaternion::GetY() const
{
	return _y;
}

const float Quaternion::GetZ() const
{
	return _z;
}

const float Quaternion::GetW() const
{
	return _w;
}

Quaternion& Quaternion::SetX(float x)
{
	_x = x;
	return *this;
}

Quaternion& Quaternion::SetY(float y)
{
	_y = y;
	return *this;
}

Quaternion& Quaternion::SetZ(float z)
{
	_z = z;
	return *this;
}

Quaternion& Quaternion::SetW(float w)
{
	_w = w;
	return *this;
}

Quaternion& Quaternion::SetXYZW(float x, float y, float z, float w)
{
	_x = x;
	_y = y;
	_z = z;
	_w = w;
	return *this;
}

Quaternion& Quaternion::SetWithQuaternion(const Quaternion& other)
{
	_x = other._x;
	_y = other._y;
	_z = other._z;
	_w = other._w;
	return *this;
}