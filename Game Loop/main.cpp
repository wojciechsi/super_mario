#include "game.h"
#include <iostream>

#define FRAME_DURATION 40 // 25 fps
Game *game = nullptr;

int main()
{
	game = new Game();

	game->initialize("PotatoEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
        auto frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
        auto frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DURATION)
            SDL_Delay(FRAME_DURATION - frameTime);

    }
	game->clean();

    delete game; //wyciek jest tak czy siak

	return 0;
}