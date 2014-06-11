#ifndef __MAINCOMPONENT_H__
#define __MAINCOMPONENT_H__

#include "Window.h"

namespace Blaze
{

#define FRAME_CAP 5000;

class MainComponent
{
public:
	MainComponent(Window* window);
	~MainComponent();
	void Start();
	void Stop();


private:
	void run();
	void render();
	void cleanUp();
	double getTime();

private:
	Window* _window;
	bool _isRunning;
};

}

#endif // __MAINCOMPONENT_H__
