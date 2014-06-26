#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Platform.h"

using namespace blaze;

Platform::Platform(Window* window, Renderer* renderer)
	: _window(window)
	, _renderer(renderer)
{
}

Platform::~Platform()
{
}

Platform* Platform::Initialize(int width, int height, const char* title, Input* input)
{
	auto window = Window::Initialize(width, height, title, input);
	auto renderer = Renderer::Initialize(window->GetDeviceContext());

	auto platform = new Platform(window, renderer);
	return platform;
}

void Platform::OnPreFrame()
{
	MSG msg;
	if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void Platform::OnPostFrame()
{
	SwapBuffers(_window->GetDeviceContext());
}

void Platform::Render()
{
	_renderer->Render();
}

bool Platform::IsExitRequested()
{
	return _window->IsExitRequested();
}
