#ifndef __SHADER_H__
#define __SHADER_H__

#include <vector>

namespace blaze
{

class Shader
{
public:
	Shader(GLuint programHandle, std::vector<GLuint> shaderHandles);
	void Use();
	void Delete();
private:
	GLuint _programHandle;
	std::vector<GLuint> _shaderHandles;
};

}

#endif // __SHADER_H__