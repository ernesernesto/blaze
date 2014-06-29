#ifndef __GAME_H__
#define __GAME_H__

#include "Input.h"
#include "Mesh.h"

namespace blaze
{

class Game
{
public:
	~Game();
	static Game* Initialize(Input* input);

	void OnInput();
	void OnUpdate();
	void OnDraw();
	void OnDestroy();

private:
	Game(Input* input, Mesh* mesh);
private:
	Input* _input;
	Mesh* _mesh;
};

}

#endif // __GAME_H__