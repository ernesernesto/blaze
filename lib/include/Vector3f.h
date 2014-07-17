#ifndef __VECTOR3F_H__
#define __VECTOR3F_H__

namespace blaze
{

class Vector3f
{
public:
	Vector3f();
	Vector3f(float x, float y, float z);
	Vector3f(const Vector3f& other);

	float Length() const;
	float DotProduct(const Vector3f& vec) const;
	Vector3f CrossProduct(const Vector3f& vec) const;
	Vector3f& Normalize();
	Vector3f& Rotate(float degree);

	const float GetX() const;
	const float GetY() const;
	const float GetZ() const;

	/*
	 * Helper methods needed for calculation
	*/
	Vector3f operator - ();

	Vector3f operator + (const Vector3f& vec);
	Vector3f& operator += (const Vector3f& vec);

	Vector3f operator - (const Vector3f& vec);
	Vector3f& operator -= (const Vector3f& vec);

	Vector3f operator * (float value);
	Vector3f& operator *= (float value);
	
	Vector3f operator / (float value);
	Vector3f& operator /= (float value);
	
	Vector3f& operator = (const Vector3f& other);
	
private:
	float _x;
	float _y;
	float _z;
};

}

#endif // __VECTOR3F_H__