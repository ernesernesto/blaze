#include <iostream>

#include "Keys.h"
#include "Game.h"
using namespace blaze;

Game::Game(Input* input)
	:_input(input)
{
}
Game::~Game()
{
}

Game* Game::Initialize(Input* input)
{
	auto game = new Game(input);
	return game;
}

void Game::GetInput()
{
	if (_input->IsKeyDown(Keys::KEY_A))
		printf("Button %d pressed! \n", Keys::KEY_A);
	if (_input->IsKeyDown(Keys::KEY_B))
		printf("Button %d pressed! \n", Keys::KEY_B);
}

void Game::Update()
{
}