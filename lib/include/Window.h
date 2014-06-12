#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>

#include <GLFW/glfw3.h>

namespace blaze
{ 

class Window
{
public:
	~Window();

	static Window* Create(int widht, int height, const char* title);
	void Render();
	bool IsCloseRequested();

	int GetWidth();
	int GetHeight();
	const char* GetTitle();

private:
	Window(int width, int height, const char* title);
	void initialize();
private:
	int _width;
	int _height;
	const char* _title;
	GLFWwindow* _glfwWindow;
};

}
#endif // __WINDOW_H__