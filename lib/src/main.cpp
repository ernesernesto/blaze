#include "Window.h"
#include "MainComponent.h"

static const int WIDTH = 800;
static const int HEIGHT = 600;
static const char* TITLE = "Engine 3D";

using namespace blaze;

int main( void )
{
	MainComponent game = MainComponent();
	game.InitializeWindow(WIDTH, HEIGHT, TITLE);
	game.Start();

	return 0;
}

