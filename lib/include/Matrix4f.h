#ifndef __MATRIX4F_H__
#define __MATRIX4F_H__

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
	//TODO implement functions mul add sub, etc between matrices
	Matrix4f& Multiply(const Matrix4f& other);
	
	//TODO implement overload operator

	float* GetMatrix();
	float& GetAt(int x, int y);

	Matrix4f& SetMatrix(const float* data);
	Matrix4f& SetAt(int x, int y, float val);


private:
	float _mat[16];
};

}

#endif // __MATRIX4F_H__