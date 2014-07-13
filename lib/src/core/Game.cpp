#include <math.h>

#include "Keys.h"
#include "Game.h"

#include "Vector2f.h"
#include "Vertex.h"
#include "Shader.h"
#include "ShaderBuilder.h"
#include "ResourceLoader.h"

using namespace blaze;

//TODO think more throughtly about putting Shader global, should it be member instance or not?
static Shader* shader;
static Matrix4f* mat;

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
		Vector3f(1.0f, -1.0f, 0.0f),
		Vector3f(0.0f, -1.0f, 1.0f)
	};

	GLuint indices[] = 
	{
		0, 1, 3,			  
		3, 1, 2,
		2, 1, 0,
		0, 2, 3
	};
	auto meshInfo = ResourceLoader::LoadMeshFromFile("res/mesh/cube.obj");

	mesh->AddVertices(data, sizeof(data) / sizeof(Vertex), indices, sizeof(indices) / sizeof(GLuint));

	const int aVertexPosition = 0;

	const std::string vertexShader = ResourceLoader::LoadShader("res/shaders/glsl/vertex/basicVertex.vs");
	const std::string fragmentShader = ResourceLoader::LoadShader("res/shaders/glsl/fragment/basicFragment.fs");

	shader = ShaderBuilder()
		.AddVertexShader(vertexShader)
		.AddFragmentShader(fragmentShader)
		.BindAttribute(aVertexPosition, "aVertexPosition")
		.Build();
	
	shader->Use();

	mat = new Matrix4f();
	mat->Scale(0.75f, 0.75f, 1.0f);

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

//TODO remove this temp, only for test
float temp = 0.0f;
void Game::OnUpdate()
{
	temp += 0.0005f;
	float sinTemp = (float)sin(temp);
	mat->Translate(Vector3f(sinTemp, 0.0f, 0.0f));
	mat->Rotate(Vector3f(0.0f, sinTemp, 0.0f), 0.05f);

	int uniformLocation = shader->GetUniformLocation("uniformPosition");
	int uniformMatLocation = shader->GetUniformLocation("uniformMat");

	shader->SetUniformf(uniformLocation, (float)abs(sin(temp)));
	shader->SetUniformMat4f(uniformMatLocation, 1, *mat);
}

void Game::OnDraw()
{
	_mesh->Draw();
}

void Game::OnDestroy()
{
	delete _mesh;
	shader->Delete();
	delete mat;
	//TODO check which one should be deleted on this scope
}