#ifndef __INPUT_H__
#define __INPUT_H__

#include "Vector2f.h"

namespace blaze
{

class Input
{
public:
	static Input* Initialize();
	~Input();

	void OnKeyDown(unsigned int key);
	void OnKeyUp(unsigned int key);
	void OnMouseDown(float x, float y);
	void OnMouseUp();

	bool IsKeyDown(unsigned int key);
	bool IsMouseClicked();
	Vector2f GetMousePosition();

private:
	Input();
private:
	bool _keys[256];
	bool _isMouseClicked;
	int _mousePosition[2];
};

}

#endif // __INPUT_H__