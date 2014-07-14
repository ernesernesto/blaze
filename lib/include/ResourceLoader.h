#ifndef __RESOURCELOADER_H__
#define __RESOURCELOADER_H__

#include <vector>

#include "Mesh.h"

namespace blaze
{

class ResourceLoader
{
public:
	static const std::string LoadShader(const std::string filename);
	static Mesh* LoadMeshFromFile(const std::string filename);
private:
	/*
	 * Tokenize input string into parameters delimited by whitespace
	*/
	static void tokenizeString(const char* str, std::vector<std::string>& tokens);
};

}

#endif // __RESOURCELOADER_H__