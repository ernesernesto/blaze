#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>

#include <GLFW/glfw3.h>

namespace Blaze
{ 

class Window
{
public:
	static Window* InitializeWindow(int width, int height, const char* title);
	void Render();
	bool IsCloseRequested();
	int GetWidth();
	int GetHeight();
	const char* GetTitle();
	~Window();

private:
	Window(int width, int height, const char* title);

	void initialize();
private:
	int _width;
	int _height;
	const char* _title;
	GLFWwindow* _window;
};

}
#endif // __WINDOW_H__
