#include <stdio.h>
#include <stdlib.h>

#include "Window.h"

using namespace blaze;


namespace
{
Window* w;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return w->HandleMessage(hwnd, message, wParam, lParam);
}

}

Window::Window(HWND handle)
	: _windowHandle(handle)
	, _isExitRequested(false)
{
}

Window::Window(const Window& other)
	: _windowHandle(other._windowHandle)
	, _isExitRequested(other._isExitRequested)
{
}

Window::~Window()
{
}

Window* Window::Create(int width, int height, const char* title)
{
	HWND handle = 0;
	WNDCLASS windowClass;
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = 0;
    windowClass.hIcon = 0;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	windowClass.lpszClassName = title;
    windowClass.lpszMenuName = 0;

	if(!RegisterClass(&windowClass))
	{
		MessageBox(0, "Window registration failed!", "Error!", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}

	handle = CreateWindow(windowClass.lpszClassName, windowClass.lpszClassName, WS_VISIBLE, 
		CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, windowClass.hInstance, NULL);

	if(!handle)
	{
		MessageBox(0, "Window registration failed!", "Error!", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}

	auto window = new Window(handle);
	w = window;
	return window;
}

void Window::Render()
{
}

LRESULT Window::HandleMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (message)
	{
	case WM_KEYDOWN:
	{
		//inputHandler->OnKeyDown((unsigned int)wParam);
		break;
	}
	case WM_KEYUP:
	{
		//inputHandler->OnKeyUp((unsigned int)wParam);
		break;
	}
	case WM_CLOSE:
	{
		_isExitRequested = true;
		PostQuitMessage(0);
		break;
	}
	default:
	{
		result = DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	}
	return result;
}

bool Window::IsExitRequested()
{
	return _isExitRequested;
}