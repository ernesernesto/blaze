#include <GL/glew.h>

#include "ShaderBuilder.h"

using namespace blaze;

typedef std::pair<GLenum, const std::string> ShaderPair;
typedef std::pair<GLuint, const std::string> AttributePair;


ShaderBuilder::ShaderBuilder()
	: _shaders()
	, _attributes()
{
}

ShaderBuilder& ShaderBuilder::AddVertexShader(const std::string& shaderSource)
{
	_shaders.push_back(ShaderPair(GL_VERTEX_SHADER, shaderSource));
	return *this;
}

ShaderBuilder& ShaderBuilder::AddGeometryShader(const std::string& shaderSource)
{
	_shaders.push_back(ShaderPair(GL_GEOMETRY_SHADER, shaderSource));
	return *this;
}

ShaderBuilder& ShaderBuilder::AddFragmentShader(const std::string& shaderSource)
{
	_shaders.push_back(ShaderPair(GL_FRAGMENT_SHADER, shaderSource));
	return *this;
}

ShaderBuilder& ShaderBuilder::BindAttribute(GLuint location, const std::string& name)
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

		GLint isCompiled = false;
		glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &isCompiled);
		if(!isCompiled)
		{
			GLint logLength;
			glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &logLength);

			char* logInformation = new char[logLength];
			glGetShaderInfoLog(shaderHandle, logLength, NULL, logInformation);
			
			//TODO get shader name for better information
			printf("Failed compiling shader, %s\n", logInformation);
			delete logInformation;
		}

		glAttachShader(shaderProgramHandle, shaderHandle);

		vecShaderHandle.push_back(shaderHandle);
	}

	for (auto i = _attributes.begin(); i != _attributes.end(); ++i)
	{
		GLuint location = (*i).first;
		const char* attribute = (*i).second.c_str();
		glBindAttribLocation(shaderProgramHandle, location, attribute);
	}

	GLint isLinked = false;
	glLinkProgram(shaderProgramHandle);

	glGetProgramiv(shaderProgramHandle, GL_LINK_STATUS, &isLinked);
	if(!isLinked)
	{
		//TODO get info why this failed
		printf("Failed linking shader program\n");
	}
	
	GLint isValidated = false;
	glValidateProgram(shaderProgramHandle);

	glGetProgramiv(shaderProgramHandle, GL_VALIDATE_STATUS, &isValidated);
	if(!isValidated)
	{
		//TODO get info why this failed
		printf("Failed linking shader program\n");	
	}

	return new Shader(shaderProgramHandle, vecShaderHandle);
}