#include <GL/glew.h>

#include "ShaderBuilder.h"

using namespace blaze;

typedef std::pair<GLenum, std::string> ShaderPair;
typedef std::pair<GLuint, std::string> AttributePair;


ShaderBuilder::ShaderBuilder()
	: _shaders()
	, _attributes()
{
}

ShaderBuilder& ShaderBuilder::AddVertexShader(std::string shaderSource)
{
	_shaders.push_back(ShaderPair(GL_VERTEX_SHADER, shaderSource));
	return *this;
}

ShaderBuilder& ShaderBuilder::AddGeometryShader(std::string shaderSource)
{
	_shaders.push_back(ShaderPair(GL_GEOMETRY_SHADER, shaderSource));
	return *this;
}

ShaderBuilder& ShaderBuilder::AddFragmentShader(std::string shaderSource)
{
	_shaders.push_back(ShaderPair(GL_FRAGMENT_SHADER, shaderSource));
	return *this;
}

ShaderBuilder& ShaderBuilder::BindAttribute(GLuint location, std::string name)
{
	_attributes.push_back(AttributePair(location, name));
	return *this;
}	

/*
 * One "shader program" have many shader handles. Basically this Build() method do these things
 * 1. Iterate through all ShaderType - ShaderSource pair on _shaders and create the shaderHandle
 * 2. Attach the resulting shaderHandle to the "shader program"
 * 2. Iterate through all Location - Name pair on _attributes and bind it
 * 3. Link progam and validate
 */
Shader* ShaderBuilder::Build()
{
	GLuint shaderProgramHandle = glCreateProgram();
	//TODO check if program creation success

	std::vector<GLuint> vecShaderHandle;

	for (auto i = _shaders.begin(); i != _shaders.end(); ++i)
	{
		GLenum type = (*i).first;
		const char* source = (*i).second.c_str();
		GLuint shaderHandle = glCreateShader(type);
		glShaderSource(shaderHandle, 1, &source, NULL);
		glCompileShader(shaderHandle);
		//if(glGetShaderiv(shader, GL_COMPILE_STATUS))
		//{
		//	throw error;
		//}

		glAttachShader(shaderProgramHandle, shaderHandle);

		vecShaderHandle.push_back(shaderHandle);
	}

	glLinkProgram(shaderProgramHandle);
	//TODO check if linking succeess
	
	glValidateProgram(shaderProgramHandle);
	//TODO check if validate success

	return new Shader(shaderProgramHandle, vecShaderHandle);
}