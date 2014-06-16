#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <Windows.h>
#include "Input.h"

namespace blaze
{ 

class Window
{
public:
	~Window();

	static Window* Initialize(int widht, int height, const char* title, Input* inputHandler);
	void Render();
	LRESULT HandleMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	int GetWidth();
	int GetHeight();
	const char* GetTitle();

	bool IsExitRequested();

private:
	Window(HWND handle, Input* inputHandler);
	Window(const Window& other);

private:
	HWND _windowHandle;
	Input* _inputHandler;
	bool _isExitRequested;

};

}
#endif // __WINDOW_H__