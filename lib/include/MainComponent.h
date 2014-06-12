#ifndef __MAINCOMPONENT_H__
#define __MAINCOMPONENT_H__

#include "Window.h"
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
	void InitializeWindow(int width, int height, const char* title);
	void Start();
	void Stop();

private:
	void run();
	void render();
	void cleanUp();

private:
	Window* _window;
	bool _isRunning;
};

}

#endif // __MAINCOMPONENT_H__