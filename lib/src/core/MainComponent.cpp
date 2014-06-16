#include <Windows.h>
#include <stdint.h>
#include <thread>

#include "MainComponent.h"

using namespace blaze;

MainComponent::MainComponent()
	: _isRunning(false) 
{
}

MainComponent::~MainComponent()
{
}

void MainComponent::Initialize(int width, int height, const char* title)
{
	auto input = Input::Initialize();

	_platform = Platform::Initialize(width, height, title, input);
	_game = Game::Initialize(input);
}

void MainComponent::Start()
{
	run();
}

void MainComponent::Stop()
{
	_isRunning = false;
}

void MainComponent::run()
{
	_isRunning = true;
	int frames = 0;
	double frameCounter = 0;

	const double frameTime = 1.0 / 5000;

	double previousTime = timeGetTime();
	double lag = 0.0;

	while(_isRunning)
	{
		bool needRender = false;

		double currentTime = timeGetTime();
		double passedTime = currentTime - previousTime;
		previousTime = currentTime;

		lag += passedTime / 1000;
		frameCounter += passedTime / 1000;

		while (lag >= frameTime)
		{
			needRender = true;
			lag -= frameTime;
			
			if(_platform->IsExitRequested())
				Stop();

			_platform->OnPreFrame();
			_game->GetInput();
			_game->Update();
			_platform->OnPostFrame();

			if(frameCounter >= 1)
			{
				DEBUG_OUTPUT("%d\n", frames);
				frames = 0;
				frameCounter = 0;
			}
		}

		if(needRender)
		{
			frames++;
			render();
			//TODO RENDER PER FRAMETIME
		}
		else
		{
			std::chrono::milliseconds duration(1);
			std::this_thread::sleep_for(duration);
		}
	}

	cleanUp();
}

void MainComponent::render()
{
	//game.render
	_platform->Render();
}

void MainComponent::cleanUp()
{
	//delete _window;
}
