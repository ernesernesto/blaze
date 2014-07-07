#ifndef __SHADERBUILDER_H__
#define __SHADERBUILDER_H__

#include <vector>

#include <Windows.h>
#include <GL/GL.h>
#include "Shader.h"

namespace blaze
{

class ShaderBuilder
{
public:
	ShaderBuilder();

	ShaderBuilder& AddVertexShader(const std::string& shaderSource);
	ShaderBuilder& AddGeometryShader(const std::string& shaderSource);
	ShaderBuilder& AddFragmentShader(const std::string& shaderSource);

	//TODO find out how to replace Gl defined types
	ShaderBuilder& BindAttribute(GLuint location, const std::string& name);

	/*
	 * All shader creation (AddShader and BindAttribute) should be called consecutively to store shaders information
	 * before calling Build() method. Build() will call the real OpenGL calls (glAttachShaders and glBindAttribute)
	 * and returns resulting Shader ready to be used
	*/
	Shader* Build();

private:
	/*
	 * Shader type and its source for the "Shader Program" to use
	*/
	std::vector< std::pair<GLenum, const std::string> > _shaders;
	/*
	 * Attribute location for the shader and the name to bound to that location
	*/
	std::vector< std::pair<GLuint, std::string> > _attributes;
};

}

#endif // __SHADERBUILDER_H__