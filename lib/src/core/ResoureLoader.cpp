#include <iostream>
#include <fstream>

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

std::string ResourceLoader::LoadMeshFromFile(const std::string filename)
{
	std::ifstream file(filename);

	if(!file.is_open())
	{
		//TODO should throw runtime exception here
		printf("Failed to open shader file!\n");
	}

	std::string test = std::string(
		(std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>()
		);

	return "";
	//return std::pair;
}
