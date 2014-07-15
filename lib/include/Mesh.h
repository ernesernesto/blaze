#ifndef __MESH_H__
#define __MESH_H__

#include <vector>
#include <GL/glew.h>
#include "Vertex.h"

namespace blaze
{

class Mesh
{
public:
	Mesh();

	//TODO change param not to use opengl specific type
	void AddVertices(std::vector<Vertex> vertices, int vertexCount, std::vector<GLuint> indices, int indicesCount);

	void Draw();

private:
	//TODO change param not to use opengl specific type
	//Only use one vbo for now, this will be used to store vertices data
	GLuint _vbo;
	GLuint _ibo;
	int _size;
};

}

#endif // __MESH_H__