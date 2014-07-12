#ifndef __MATRIX4F_H__
#define __MATRIX4F_H__

#include "Vector3f.h"

namespace blaze
{

/*
	Mathematicians laid out matrix not in a way programmers laid out matrix 
	in contiguous array. So in mathematicians pov, it would be like this
	m[0] m[4] m[8]  m[12]
	m[1] m[5] m[9]  m[13]
	m[2] m[6] m[10] m[14]
	m[3] m[7] m[11] m[15]

	Translation components occupy the 13th, 14th, and 15th elements 
	This has an effect when multiplying matrix with vector on the shader.
	To get the desired effect, calculations must in the form of mat * vec, 
	not vec * mat as it would get different results

	That's why in setting OpenGL matrix, we laid it out as column major matrix 
	(passing GL_FALSE as the third param of glUniformMatrix family)
	see Shader.cpp SetUniformMat implementation
*/
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