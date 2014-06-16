#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <Windows.h>

namespace blaze
{ 

class Window
{
public:
	~Window();

	static Window* Create(int widht, int height, const char* title);
	void Render();
	LRESULT HandleMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	int GetWidth();
	int GetHeight();
	const char* GetTitle();

	bool IsExitRequested();

private:
	Window(HWND handle);
	Window(const Window& other);
	void initialize();

private:
	HWND _windowHandle;
	bool _isExitRequested;
};

}
#endif // __WINDOW_H__