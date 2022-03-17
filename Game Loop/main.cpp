#include "game.h"
#include <iostream>
#include <memory>

Game *game = nullptr;

int main(int argc, const char* argv[])
{
	game = new Game();

	game->initialize("PotatoEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();

	return 0;
}