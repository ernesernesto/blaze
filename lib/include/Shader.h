#ifndef __SHADER_H__
#define __SHADER_H__

#include <vector>

#include "Vector3f.h"
#include "Matrix4f.h"

namespace blaze
{

/* TODO revisit overall architecture of Shader, must have one layer on abstraction inside Shader to support
 * multiple graphics API, could be driver abstractions. shader->GetUniform would call
 * driver->GetUniform suitable for graphics implementation
*/ 

class Shader
{
public:
	Shader(GLuint programHandle, std::vector<GLuint> shaderHandles);
	void Use();
	void Delete();

	//TODO change return values not to use opengl specific type
	GLint GetUniformLocation(const std::string& uniformName);

	void SetUniformi(GLint location, int value);
	void SetUniformf(GLint location, float value);
	void SetUniformVec3f(GLint location, Vector3f& vec);
	void SetUniformMat4f(GLint location, Matrix4f& mat);

private:
	GLuint _programHandle;
	std::vector<GLuint> _shaderHandles;
};

}

#endif // __SHADER_H__