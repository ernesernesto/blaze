#include <GL/glew.h>

#include "Shader.h"

using namespace blaze;

Shader::Shader(GLuint programHandle, std::vector<GLuint> shaderHandles)
	: _programHandle(programHandle)
	, _shaderHandles(shaderHandles)
{
}

void Shader::Use()
{
	glUseProgram(_programHandle);
}

void Shader::Delete()
{
	glDeleteProgram(_programHandle);
	//TODO delete all shader handles
}

//TODO change return values not to use opengl specific type
GLint Shader::GetUniformLocation(const std::string& uniformName)
{
	return glGetUniformLocation(_programHandle, uniformName.c_str());
}

//TODO change return values not to use opengl specific type
void Shader::SetUniformi(GLint location, int value)
{
	glUniform1i(location, value);
}

//TODO change return values not to use opengl specific type
void Shader::SetUniformf(GLint location, float value)
{
	glUniform1f(location, value);
}

//TODO change return values not to use opengl specific type
void Shader::SetUniformVec3f(GLint location, Vector3f& vec)
{
	glUniform3f(location, vec.GetX(), vec.GetY(), vec.GetZ());
}

//TODO change return values not to use opengl specific type
void Shader::SetUniformMat4f(GLint location, Matrix4f& mat)
{
	//TODO check the correct param
	glUniformMatrix4fv(location, 0, GL_FALSE, mat.GetMatrix());
}
