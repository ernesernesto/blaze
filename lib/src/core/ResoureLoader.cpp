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
	std::vector<GLuint> indices;
	while(std::getline(file, line))
	{
		if(line.substr(0, 1) == "#" || line.empty())
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
		{
			GLuint ind[3];
			int count = std::sscanf(tokens.at(1).c_str(), "%d/%d/%d", &ind[0], &ind[1], &ind[2]);
			/*
			indices.push_back(atoi(tokens.at(1).c_str()) - 1);
			indices.push_back(atoi(tokens.at(2).c_str()) - 1);
			indices.push_back(atoi(tokens.at(3).c_str()) - 1);
			*/
			indices.push_back(ind[0] - 1);
			indices.push_back(ind[1] - 1);
			indices.push_back(ind[2] - 1);
		}
		else
			printf("read something else %s \n", line.c_str());
			
	}

	return new Mesh(filename, std::move(positions), std::move(indices));
}

void ResourceLoader::tokenizeString(const char* str, std::vector<std::string>& tokens)
{
	/*
	 * TODO Fix Bug for edge case
	 * consider file that is read have two spaces after the type
	 * v  0.000000 1.000000 0.500000
	 *  ^^ two spaces would lead to bad tokens
	 * also consider trailing spaces after a line
	 * v 0.000000 1.000000 0.500000 
	 *                             ^^ would made token size larger than it should be
	*/
	do
	{
		const char *begin = str;
		while(*str != ' ' && *str)
			str++;

		tokens.push_back(std::string(begin, str));
	} 
	while(*str++ != 0);
}
