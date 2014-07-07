#include <iostream>
#include <fstream>

#include "Keys.h"
#include "Game.h"

#include "Vector2f.h"
#include "Vertex.h"
#include "Shader.h"
#include "ShaderBuilder.h"

using namespace blaze;

Game::Game(Input* input, Mesh* mesh)
	: _input(input)
	, _mesh(mesh)
{
}

Game::~Game()
{
}

Game* Game::Initialize(Input* input)
{
	auto mesh = new Mesh();
	Vertex data[] = 
	{ 
		Vector3f(-1.0f, -1.0f, 0.0f),
		Vector3f(0.0f, 1.0f,  0.0f),
		Vector3f(1.0f, -1.0f, 0.0f)
	};

	mesh->AddVertices(data, sizeof(data) / sizeof(Vertex));

	const int aVertexPosition = 0;

	std::ifstream vertexShaderFile("res/shaders/glsl/vertex/basicVertex.vs");
	std::ifstream fragmentShaderFile("res/shaders/glsl/fragment/basicFragment.fs");

	if(!vertexShaderFile.is_open())
	{
		//TODO should throw runtime exception here
		printf("Failed to open shader file!\n");
	}

	if(!fragmentShaderFile.is_open())
	{
		//TODO should throw runtime exception here
		printf("Failed to open shader file!\n");
	}

	const std::string vertexShader(
		(std::istreambuf_iterator<char>(vertexShaderFile)),
		std::istreambuf_iterator<char>()
		);

	const std::string fragmentShader(
		(std::istreambuf_iterator<char>(fragmentShaderFile)),
		std::istreambuf_iterator<char>()
		);

	Shader* shader = ShaderBuilder()
		.AddVertexShader(vertexShader)
		.AddFragmentShader(fragmentShader)
		.BindAttribute(aVertexPosition, "aVertexPosition")
		.Build();
	
	shader->Use();

	auto game = new Game(input, mesh);
	return game;
}

void Game::OnInput()
{
	if(_input->IsKeyDown(Keys::KEY_A))
		printf("Button %d pressed! \n", Keys::KEY_A);
	if(_input->IsKeyDown(Keys::KEY_B))
		printf("Button %d pressed! \n", Keys::KEY_B);
	if(_input->IsMouseClicked())
	{
		Vector2f mousePosition = _input->GetMousePosition();
		int x = mousePosition.GetX();
		int y = mousePosition.GetY();
		printf("Mouse clicked on x : %d, y : %d \n", x, y);	
	}
}

void Game::OnUpdate()
{
}

void Game::OnDraw()
{
	_mesh->Draw();
}

void Game::OnDestroy()
{
	delete _mesh;
	//TODO check which one should be deleted on this scope
}