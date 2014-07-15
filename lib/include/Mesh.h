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
	Mesh(const std::string filename, std::vector<Vertex>&& vertices, std::vector<GLuint>&& indices);
	static Mesh* Initialize(const std::string filename);
	void Draw();

private:
	//TODO change param not to use opengl specific type
	void addVertices();

private:
	std::string _filename;
	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;
	//TODO change param not to use opengl specific type
	//Only use one vbo for now, this will be used to store vertices data
	GLuint _vbo;
	GLuint _ibo;
	int _size;
};

}

#endif // __MESH_H__