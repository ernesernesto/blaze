#include <Windows.h>
#include <iostream>

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
	if (_input->IsKeyDown(16 ))
		printf("Button %d pressed! \n");
	//if (!_input->IsKeyDown(VK_LSHIFT))
	//	printf("Button %d released! \n");
}

void Game::Update()
{
}