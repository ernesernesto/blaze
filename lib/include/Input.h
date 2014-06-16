#ifndef __INPUT_H__
#define __INPUT_H__

namespace blaze
{

class Input
{
public:
	static Input* Initialize();
	~Input();

	void OnKeyDown(unsigned int key);
	void OnKeyUp(unsigned int key);

	bool IsKeyDown(unsigned int key);
private:
	Input();
private:
	bool _keys[256];
};

}

#endif // __INPUT_H__