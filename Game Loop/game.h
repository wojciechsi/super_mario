#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();

	void initialize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean(); 
	void makeFullscreen();
	
	bool running() {return IsRunning;}
	 
private:
	int count = 0;
	bool IsRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool FullScreen = 0;

};


#endif