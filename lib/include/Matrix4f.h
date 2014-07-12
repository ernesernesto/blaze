#ifndef __MATRIX4F_H__
#define __MATRIX4F_H__

#include "Vector3f.h"

namespace blaze
{

class Matrix4f
{
public:
	Matrix4f();
	Matrix4f(const Matrix4f& other);
	Matrix4f& operator = (const Matrix4f& other);

	float& operator [](int index);
	const float& operator [](int index) const;

	Matrix4f& InitIdentity();
	Matrix4f& Clear();

	//TODO implement functions mul add sub, etc between matrices
	Matrix4f& Multiply(const Matrix4f& other);
	Matrix4f& Translate(float x, float y, float z);
	Matrix4f& Translate(const Vector3f& translationVector);

	Vector3f GetTranslationVector() const;
	//TODO implement overload operator

	const float* GetValues() const;
	float& GetAt(int x, int y);

	Matrix4f& SetValues(const float* data);
	Matrix4f& SetAt(int x, int y, float val);

private:
	float _mat[16];
};

}

#endif // __MATRIX4F_H__