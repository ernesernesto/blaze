#ifndef __MESH_H__
#define __MESH_H__

#include <GL/glew.h>
#include "Vertex.h"

namespace blaze
{

class Mesh
{
public:
	Mesh();
	void AddVertices(Vertex* vertices, int vertexNumber);
	void Draw();

private:
	//Only use one vbo for now, this will be used to store vertices data
	GLuint _vbo[1];
	int _size;
};

}

#endif // __MESH_H__