#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <Windows.h>

namespace blaze
{
class Renderer
{
public:
	~Renderer();
	static Renderer* Initialize(HDC deviceContext);
	void Render();

private:
	Renderer(HDC deviceContext, HGLRC renderContext);

	void initGraphics();

private:
	HDC _deviceContext;
	HGLRC _renderContext;
};

}

#endif // __RENDERER_H__