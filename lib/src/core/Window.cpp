#include <stdio.h>
#include <stdlib.h>

// Use glew static lib
#define GLEW_STATIC
#include <GL/glew.h>

#include "Window.h"

using namespace Blaze;

Window::Window(int width, int height, const char* title)
	: _width(width)
	, _height(height)
	, _title(title)
	, _window(nullptr)
{
}

Window::~Window()
{
	delete _window;
	glfwTerminate();
}

Window* Window::InitializeWindow(int width, int height, const char* title)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return false;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	auto window = new Window(width, height, title);
	window->initialize();

	return window;
}

void Window::initialize()
{
	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if (_window == NULL){
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(_window);

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}
}

void Window::Render()
{
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

bool Window::IsCloseRequested()
{
	return (glfwGetKey(_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(_window) == 0 );
}

int Window::GetWidth()
{
	return _width;
}

int Window::GetHeight()
{
	return _height;
}

const char* Window::GetTitle()
{
	return _title;
}
