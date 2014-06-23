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
	Vector2f& operator = (const Vector2f& other);

	float Length() const;
	float DotProduct(const Vector2f& vec) const;
	Vector2f& Normalize();
	Vector2f& Rotate(float degree);

	const float GetX() const;
	const float GetY() const;
	Vector2f& SetX(float x);
	Vector2f& SetY(float y);
	Vector2f& SetXY(float x, float y);
	Vector2f& SetWithValue(float val);
	Vector2f& SetWithVector(const Vector2f& vector);

	/*
	 * Helper methods needed for calculation
	*/
	Vector2f ToNegatve() const;

	Vector2f& AddWithValue(const float val);
	Vector2f& AddWithVector(const Vector2f& other);

	Vector2f& SubWithValue(const float val);
	Vector2f& SubWithVector(const Vector2f& other);

	Vector2f& MulWithValue(const float val);
	Vector2f& MulWithVector(const Vector2f& other);
	
	Vector2f& DivWithValue(const float val);
	Vector2f& DivWithVector(const Vector2f& other);
	
private:
	float _x;
	float _y;
};

}

#endif // __VECTOR2F_H__