#ifndef __GAME_H__
#define __GAME_H__

#include "Input.h"

namespace blaze
{

class Game
{
public:
	~Game();
	static Game* Initialize(Input* input);

	void GetInput();
	void Update();

private:
	Game(Input* input);
private:
	Input* _input;

};

}

#endif // __GAME_H__