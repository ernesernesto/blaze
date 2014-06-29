#include <Windows.h>
#include <GL/GL.h>

#include "Renderer.h"

using namespace blaze;

Renderer::Renderer(HDC deviceContext, HGLRC renderContext)
	: _deviceContext(deviceContext)
	, _renderContext(renderContext)
{
}

Renderer::~Renderer()
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(_renderContext);

	//TODO release device context
}

Renderer* Renderer::Initialize(HDC deviceContext)
{
	HGLRC renderingContext = wglCreateContext(deviceContext);
	//TODO error checking of rendering context creation

	auto renderer = new Renderer(deviceContext, renderingContext);

	wglMakeCurrent(renderer->_deviceContext, renderer->_renderContext);
	renderer->initGraphics();

	return renderer;
}

void Renderer::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

const char* Renderer::GetRendererVersion()
{
	return reinterpret_cast<const char*>(glGetString(GL_VERSION));
}

void Renderer::initGraphics()
{
	glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	//TODO Depth clamp for later
}

