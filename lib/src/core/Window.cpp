#include <stdio.h>
#include <stdlib.h>

#include "Window.h"

bool _win32_isExitRequested = false;
namespace
{

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch(message)
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
			_win32_isExitRequested = true;
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

}

using namespace blaze;

Window::Window(HWND handle)
	: _windowHandle(handle)
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
	return window;
}

void Window::Render()
{
}
