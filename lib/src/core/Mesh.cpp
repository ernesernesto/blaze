#include "Mesh.h"
#include "ResourceLoader.h"

using namespace blaze;

Mesh::Mesh(const std::string filename, std::vector<Vertex>&& vertices, std::vector<GLuint>&& indices)
	: _filename(filename)
	, _vertices(std::move(vertices))
	, _indices(std::move(indices))
{
	//TODO move glewInit to another place
	//TODO move all gl extensions calls to another place, so I could use another graphics API
	glewInit();
	glGenBuffers(1, &_vbo);
	glGenBuffers(1, &_ibo);
}

Mesh* Mesh::Initialize(const std::string filename)
{
	auto mesh = ResourceLoader::LoadMeshFromFile(filename);
	mesh->addVertices();

	return mesh;
}

//TODO change param not to use opengl specific type
void Mesh::addVertices()
{
	int vertexSize = _vertices.size() * Vertex::SIZE;
	int indicesSize = _indices.size();

	//TODO move all gl extensions calls to another place, so I could use another graphics API
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(GLfloat), &_vertices.at(0), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize * sizeof(GLuint), &_indices.at(0), GL_STATIC_DRAW);
}

void Mesh::Draw()
{
	//TODO move all glextensions calls to another place, so I could use another graphics API
	//TODO change the hardcoded numbers parameters on the glextensions call below
	//TODO find out what are the purpose of below extensions
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, Vertex::SIZE * 4, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
	 
	glDisableVertexAttribArray(0);
}