#include "game.h"
#include <iostream>

Game::Game()
{

}

Game::~Game()
{

}

void Game::initialize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "Wszystkie systemy zosta³y poprawnie zainicjalizowane." <<std::endl;
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (window)
		{
			std::cout << "Okno zainicjowane poprawnie." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer zainicjowany poprawnie." << std::endl;
		}
		IsRunning = true;
	}
	else
	{
		IsRunning = false;
	}

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		IsRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	count++;
	std::cout << count << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Wszystko zakonczono poprawnie";
}

