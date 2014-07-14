#include <iostream>
#include <fstream>
#include <string>

#include "ResourceLoader.h"

using namespace blaze;

const std::string ResourceLoader::LoadShader(const std::string filename)
{
	std::ifstream file(filename);

	if(!file.is_open())
	{
		//TODO should throw runtime exception here
		printf("Failed to open shader file!\n");
	}

	return std::string(
		(std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>()
		);
}

Mesh* ResourceLoader::LoadMeshFromFile(const std::string filename)
{
	std::ifstream file(filename);
	if(!file.is_open())
	{
		//TODO should throw runtime exception here
		printf("Failed to open shader file!\n");
	}
	
	std::string line;
	std::vector<std::string> tokens;
	std::vector<Vertex> positions;
	while(std::getline(file, line))
	{
		if(line.substr(0, 1) == "#")
			continue;

		tokens.clear();
		tokenizeString(line.c_str(), tokens);

		std::string type = tokens.at(0);
		if(type == "v")
		{
			positions.push_back(Vector3f(
					atof(tokens.at(1).c_str()), 
					atof(tokens.at(2).c_str()), 
					atof(tokens.at(3).c_str())));
		}
		else if(type == "vt")
			printf("read a textures %s \n", line.c_str());
		else if(type == "vn")
			printf("read a normal %s \n", line.c_str());
		else if(type == "f")
			printf("read a face %s \n", line.c_str());
		else
			printf("read something else %s \n", line.c_str());
			
	}
	GLuint test[12];
	/*int size = positions.size;
	Vertex data[size]; 
	int i = 0;
	for(auto v = positions.begin(); v != positions.end(); v++, i++)
	{
		data[i] = *v;
	}*/
	return new Mesh();
	//return std::pair;
}

void ResourceLoader::tokenizeString(const char* str, std::vector<std::string>& tokens)
{
	do
	{
		const char *begin = str;
		while(*str != ' ' && *str)
			str++;

		tokens.push_back(std::string(begin, str));
	} 
	while(*str++ != 0);
}
