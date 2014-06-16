#include "Input.h"

using namespace blaze;

Input::Input()
{
	for (int i = 0; i < 256; i++)
	{
		_keys[i] = false;
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

bool Input::IsKeyDown(unsigned int key)
{
	return _keys[key];
}