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
