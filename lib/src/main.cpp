#include "Window.h"
#include "MainComponent.h"

static const int WIDTH = 800;
static const int HEIGHT = 600;
static const char* TITLE = "Engine 3D";

using namespace Blaze;

int main( void )
{
	auto window = Window::InitializeWindow(WIDTH, HEIGHT, TITLE);

	MainComponent game = MainComponent(window);
	game.Start();

	return 0;
}

