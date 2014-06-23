#ifndef __QUATERNION_H__
#define __QUATERNION_H__

#include "Vector3f.h"

namespace blaze
{

class Quaternion
{
public:
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(const Quaternion& other);
	Quaternion& operator = (const Quaternion& other);

	float Length() const;
	Quaternion& Normalize();
	Quaternion& Conjugate();
	Quaternion& MultiplyWithQuaternion(const Quaternion& other);
	Quaternion& MultiplyWithVector3f(const Vector3f& other);

	const float GetX() const;
	const float GetY() const;
	const float GetZ() const;
	const float GetW() const;

	Quaternion& SetX(float x);
	Quaternion& SetY(float y);
	Quaternion& SetZ(float z);
	Quaternion& SetW(float w);
	Quaternion& SetXYZW(float x, float y, float z, float w);
	Quaternion& SetWithQuaternion(const Quaternion& other);

private:
	float _x;
	float _y;
	float _z;
	float _w;
};

}

#endif // __MATRIX4F_H__