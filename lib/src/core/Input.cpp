#include "Input.h"

using namespace blaze;

Input::Input()
	: _isMouseClicked(false)
{
	for (int i = 0; i < 256; i++)
	{
		_keys[i] = false;
	}
	for(int j = 0; j < 2; j++)
	{
		_mousePosition[j] = 0;
	}
}

Input::~Input()
{
}

Input* Input::Initialize()
{
	auto input = new Input();
	return input;
}

void Input::OnKeyDown(unsigned int key)
{
	_keys[key] = true;
}

void Input::OnKeyUp(unsigned int key)
{
	_keys[key] = false;
}

void Input::OnMouseDown(float x, float y)
{
	_isMouseClicked = true;
	_mousePosition[0] = x;
	_mousePosition[1] = y;
}

void Input::OnMouseUp()
{
	_isMouseClicked = false;
}

bool Input::IsKeyDown(unsigned int key)
{
	return _keys[key];
}

bool Input::IsMouseClicked()
{
	return _isMouseClicked;
}

Vector2f Input::GetMousePosition()
{
	return Vector2f(_mousePosition[0], _mousePosition[1]);
}