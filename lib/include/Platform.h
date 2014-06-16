#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "Window.h"
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
	Platform(Window* window);
	~Platform();

	static Platform* Initialize(int widht, int height, const char* title);
	void OnPreFrame();
	void OnPostFrame();
	void Render();

	bool IsExitRequested();

private:
	Window* _window;
	//Input* _input;
	//DeviceContext* device
	bool _isRunning;
};

}

#endif // __PLATFORM_H__