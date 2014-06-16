#ifndef __MAINCOMPONENT_H__
#define __MAINCOMPONENT_H__

#include "Platform.h"
#include "Game.h"

#ifdef _DEBUG
#define DEBUG_OUTPUT printf
#else
#define DEBUG_OUTPUT
#endif

namespace blaze
{

class MainComponent
{
public:
	MainComponent();
	~MainComponent();
	void Initialize(int width, int height, const char* title);
	void Start();
	void Stop();

private:
	void run();
	void render();
	void cleanUp();

private:
	Platform* _platform;
	Game* _game;
	bool _isRunning;
};

}

#endif // __MAINCOMPONENT_H__