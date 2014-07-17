#ifndef __VECTOR2F_H__
#define __VECTOR2F_H__

namespace blaze
{

class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(const Vector2f& other);

	float Length() const;
	float DotProduct(const Vector2f& vec) const;
	Vector2f& Normalize();
	Vector2f& Rotate(float degree);

	const float GetX() const;
	const float GetY() const;

	/*
	 * Helper methods needed for calculation
	*/
	Vector2f operator - ();

	Vector2f operator + (const Vector2f& vec);
	Vector2f& operator += (const Vector2f& vec);

	Vector2f operator - (const Vector2f& vec);
	Vector2f& operator -= (const Vector2f& vec);

	Vector2f operator * (float value);
	Vector2f& operator *= (float value);
	
	Vector2f operator / (float value);
	Vector2f& operator /= (float value);
	
	Vector2f& operator = (const Vector2f& other);

private:
	float _x;
	float _y;
};

}

#endif // __VECTOR2F_H__