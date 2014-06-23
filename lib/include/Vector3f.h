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
	Vector3f& operator = (const Vector3f& other);

	float Length() const;
	float DotProduct(const Vector3f& vec) const;
	Vector3f CrossProduct(const Vector3f& vec) const;
	Vector3f& Normalize();
	Vector3f& Rotate(float degree);

	const float GetX() const;
	const float GetY() const;
	const float GetZ() const;

	Vector3f& SetX(float x);
	Vector3f& SetY(float y);
	Vector3f& SetZ(float z);
	Vector3f& SetXYZ(float x, float y, float z);
	Vector3f& SetWithValue(float val);
	Vector3f& SetWithVector(const Vector3f& vector);

	/*
	 * Helper methods needed for calculation
	*/
	Vector3f ToNegatve() const;

	Vector3f& AddWithValue(const float val);
	Vector3f& AddWithVector(const Vector3f& other);

	Vector3f& SubWithValue(const float val);
	Vector3f& SubWithVector(const Vector3f& other);

	Vector3f& MulWithValue(const float val);
	Vector3f& MulWithVector(const Vector3f& other);
	
	Vector3f& DivWithValue(const float val);
	Vector3f& DivWithVector(const Vector3f& other);
	
private:
	float _x;
	float _y;
	float _z;
};

}

#endif // __VECTOR3F_H__