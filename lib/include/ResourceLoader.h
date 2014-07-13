#ifndef __RESOURCELOADER_H__
#define __RESOURCELOADER_H__

#include <vector>

#include "Mesh.h"

namespace blaze
{

typedef std::pair<Vertex*, GLuint*> MeshInfo;

class ResourceLoader
{
public:
	static const std::string LoadShader(const std::string filename);
	static std::string LoadMeshFromFile(const std::string filename);
};

}

#endif // __RESOURCELOADER_H__