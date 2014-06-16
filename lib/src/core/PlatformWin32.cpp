#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Platform.h"

using namespace blaze;

Platform::Platform(Window* window)
	: _window(window)
{
}

Platform::~Platform()
{
}

Platform* Platform::Initialize(int width, int height, const char* title)
{
	auto window = Window::Create(width, height, title);
	auto platform = new Platform(window /*device*/);
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
}

void Platform::Render()
{
	_window->Render();
}

bool Platform::IsExitRequested()
{
	return _window->IsExitRequested();
}