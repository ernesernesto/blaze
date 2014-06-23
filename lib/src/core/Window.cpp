#include <stdio.h>
#include <stdlib.h>

#include "Window.h"

using namespace blaze;


/*
 * Need to redirect WndProc into class method because Input should be handled another place.
 * The simplest and fastest way I could achieve now is using "Global Variables" 
 * as described on http://web.archive.org/web/20051125022758/www.rpi.edu/~pudeyo/articles/wndproc/
 *
*/
namespace
{
Window* w;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return w->HandleMessage(hwnd, message, wParam, lParam);
}

}

Window::Window(HWND handle, Input* inputHandler)
	: _windowHandle(handle)
	, _isExitRequested(false)
	, _inputHandler(inputHandler)
{
}

Window::Window(const Window& other)
	: _windowHandle(other._windowHandle)
	, _inputHandler(other._inputHandler)
	, _isExitRequested(other._isExitRequested)
{
}

Window::~Window()
{
}

Window* Window::Initialize(int width, int height, const char* title, Input* inputHandler)
{
	HWND handle = 0;
	WNDCLASS windowClass;
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WndProc;
	windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
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

	auto window = new Window(handle, inputHandler);
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
		_inputHandler->OnKeyDown((unsigned int)wParam);
		break;
	}
	case WM_KEYUP:
	{
		_inputHandler->OnKeyUp((unsigned int)wParam);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		_inputHandler->OnMouseDown(x, y);
		break;
	}
	case WM_LBUTTONUP:
	{
		_inputHandler->OnMouseUp();
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