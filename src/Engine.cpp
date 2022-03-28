#include "headers/Engine.h"

void Engine::updateWindow(sf::RenderWindow & iWindow) {
    mario.MoveStatus();
    mario.draw(iWindow);
}
