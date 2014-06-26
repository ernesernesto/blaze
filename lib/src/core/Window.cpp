#include <stdio.h>
#include <stdlib.h>

#include "Window.h"

using namespace blaze;


/*
 * Need to redirect WndProc into class method because Input should be handled another place.
 * The simplest and fastest way I could achieve now is using "Global Variables" 
 * as described on http://web.archive.org/web/20051125022758/www.rpi.edu/~pudeyo/articles/wndproc/
*/
 
namespace
{
Window* w;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return w->HandleMessage(hwnd, message, wParam, lParam);
}

}

Window::Window(HWND windowHandle, HDC deviceContext, Input* inputHandler)
	: _windowHandle(windowHandle)
	, _deviceContext(deviceContext)
	, _isExitRequested(false)
	, _inputHandler(inputHandler)
{
}

Window::Window(const Window& other)
	: _windowHandle(other._windowHandle)
	, _deviceContext(other._deviceContext)
	, _inputHandler(other._inputHandler)
	, _isExitRequested(other._isExitRequested)
{
}

Window::~Window()
{
}

Window* Window::Initialize(int width, int height, const char* title, Input* inputHandler)
{
	HWND windowHandle = 0;
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

	windowHandle = CreateWindow(windowClass.lpszClassName, windowClass.lpszClassName, WS_VISIBLE, 
		CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, windowClass.hInstance, NULL);

	if(!windowHandle)
	{
		MessageBox(0, "Window registration failed!", "Error!", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}

	HDC deviceContext = GetDC(windowHandle);

	PIXELFORMATDESCRIPTOR pixelFormatDescriptor = {
		sizeof(PIXELFORMATDESCRIPTOR),									// Size  
		1,																// Version  
		PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER,     // Flags  
        PFD_TYPE_RGBA,													// The kind of framebuffer, RGBA or pallete
        32,																// Color depth of frame buffer 
        0, 0, 0, 0, 0, 0,												// Color bits (ignored)  
        0,																// No alpha buffer  
        0,																// Alpha bits (ignored)  
        0,																// No accumulation buffer  
        0, 0, 0, 0,														// Accum bits (ignored)  
        24,																// Number of bits for depth buffer 
        8,																// Number of bits for stencil buffer  
        0,																// No auxiliary buffers  
        PFD_MAIN_PLANE,													// Main layer  
        0,																// Reserved  
        0, 0, 0,														// No layer, visible, damage masks  
    };

	int pixelFormat;

	pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor);
	if(pixelFormat == 0)
	{
		MessageBox(0, "Choose Pixel Format Failed!", "Error!", MB_OK | MB_ICONEXCLAMATION);
		return NULL;
	}

	SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor);

	auto window = new Window(windowHandle, deviceContext, inputHandler);
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

HDC Window::GetDeviceContext()
{
	return _deviceContext;
}

bool Window::IsExitRequested()
{
	return _isExitRequested;
}