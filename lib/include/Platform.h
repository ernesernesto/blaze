#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "Window.h"
#include "Input.h"
#include "Renderer.h"

#ifdef _DEBUG
#define DEBUG_OUTPUT printf
#else
#define DEBUG_OUTPUT
#endif

namespace blaze
{

class Platform
{
public:
	Platform(Window* window, Renderer* renderer);
	~Platform();

	static Platform* Initialize(int widht, int height, const char* title, Input* input);
	void OnPreFrame();
	void OnPostFrame();
	void Render();

	bool IsExitRequested();

private:
	Window* _window;
	Renderer* _renderer;
	bool _isRunning;
};

}

#endif // __PLATFORM_H__