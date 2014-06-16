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
	bool IsCloseRequested();

	int GetWidth();
	int GetHeight();
	const char* GetTitle();

private:
	Window(HWND handle);
	void initialize();
private:
	HWND _windowHandle;
};

}
#endif // __WINDOW_H__