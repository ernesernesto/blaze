#include <memory>

#include "Matrix4f.h"

using namespace blaze;

Matrix4f::Matrix4f()
{
	InitIdentity();
}

Matrix4f::Matrix4f(const Matrix4f& other)
{
	for(int i = 0; i < 16; i ++)
	{
		_mat[i] = other._mat[i];
	}
}

Matrix4f& Matrix4f::operator = (const Matrix4f& other)
{
	return SetValues(other._mat);
}


float& Matrix4f::operator [](int index)
{
	return _mat[index];
}

const float& Matrix4f::operator [](int index) const
{
	return _mat[index];
}

Matrix4f& Matrix4f::InitIdentity()
{
	memset(this->_mat, 0, 16 * sizeof(float));
	_mat[0] = float(1);
	_mat[5] = float(1);
	_mat[10] = float(1);
	_mat[15] = float(1);
	return *this;
}

Matrix4f& Matrix4f::Clear()
{
	memset(this->_mat, 0, 16 * sizeof(float));
	return *this;
}

Matrix4f& Matrix4f::Multiply(const Matrix4f& other)
{
	Matrix4f temp(*this);
	
	/*
	 * Not know why I've done this, choosing to unroll all the loop than
	 * using loop with method calling inside it, probably like "set" functions
	 * This way could make data access faster, but haven't had the time to test it yet
	*/
	_mat[0] = temp[0] * other[0] + temp[4] * other[1] + temp[8] * other[2] + temp[12] * other[3];
	_mat[1] = temp[1] * other[0] + temp[5] * other[1] + temp[9] * other[2] + temp[13] * other[3];
	_mat[2] = temp[2] * other[0] + temp[6] * other[1] + temp[10] * other[2] + temp[14] * other[3];
	_mat[3] = temp[3] * other[0] + temp[7] * other[1] + temp[11] * other[2] + temp[15] * other[3];
	
	_mat[4] = temp[0] * other[4] + temp[4] * other[5] + temp[8] * other[6] + temp[12] * other[7];
	_mat[5] = temp[1] * other[4] + temp[5] * other[5] + temp[9] * other[6] + temp[13] * other[7];
	_mat[6] = temp[2] * other[4] + temp[6] * other[5] + temp[10] * other[6] + temp[14] * other[7];
	_mat[7] = temp[3] * other[4] + temp[7] * other[5] + temp[11] * other[6] + temp[15] * other[7];
	
	_mat[8] = temp[0] * other[8] + temp[4] * other[9] + temp[8] * other[10] + temp[12] * other[11];
	_mat[9] = temp[1] * other[8] + temp[5] * other[9] + temp[9] * other[10] + temp[13] * other[11];
	_mat[10] = temp[2] * other[8] + temp[6] * other[9] + temp[10] * other[10] + temp[14] * other[11];
	_mat[11] = temp[3] * other[8] + temp[7] * other[9] + temp[11] * other[10] + temp[15] * other[11];
	
	_mat[12] = temp[0] * other[12] + temp[4] * other[13] + temp[8] * other[14] + temp[12] * other[15];
	_mat[13] = temp[1] * other[12] + temp[5] * other[13] + temp[9] * other[14] + temp[13] * other[15];
	_mat[14] = temp[2] * other[12] + temp[6] * other[13] + temp[10] * other[14] + temp[14] * other[15];
	_mat[15] = temp[3] * other[12] + temp[7] * other[13] + temp[11] * other[14] + temp[15] * other[15];

	return *this;
}

Matrix4f& Matrix4f::Translate(float x, float y, float z)
{
	_mat[12] = x;
	_mat[13] = y;
	_mat[14] = z;

	return *this;
}

Matrix4f& Matrix4f::Translate(const Vector3f& translationVector)
{
	_mat[12] = translationVector.GetX();
	_mat[13] = translationVector.GetY();
	_mat[14] = translationVector.GetZ();

	return *this;
}

Vector3f Matrix4f::GetTranslationVector() const
{
	return Vector3f(_mat[12], _mat[13], _mat[14]);
}

const float* Matrix4f::GetValues() const
{
	return _mat;
}

float& Matrix4f::GetAt(int x, int y)
{
	return _mat[x * 4 + y];
}

Matrix4f& Matrix4f::SetValues(const float* data)
{
	memcpy(_mat, data, 16 * sizeof(float));
	return *this;
}

Matrix4f& Matrix4f::SetAt(int x, int y, float val)
{
	_mat[x * 4 + y] = val;
	return *this;
}
