#include "Mesh.h"

using namespace blaze;

Mesh::Mesh()
{
	//TODO move glewInit to another place
	//TODO move all gl extensions calls to another place, so I could use another graphics API
	glewInit();
	glGenBuffers(1, _vbo);
}

void Mesh::AddVertices(Vertex* vertices, int vertexNumber)
{
	_size = vertexNumber * Vertex::SIZE;
	//TODO move all gl extensions calls to another place, so I could use another graphics API
	glBindBuffer(GL_ARRAY_BUFFER, _vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, _size * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
}

void Mesh::Draw()
{
	//TODO move all glextensions calls to another place, so I could use another graphics API
	//TODO change the hardcoded numbers parameters on the glextensions call below
	//TODO find out what are the purpose of below extensions
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * 4, 0);
	glDrawArrays(GL_TRIANGLES, 0, _size);
	glDisableVertexAttribArray(0);
}