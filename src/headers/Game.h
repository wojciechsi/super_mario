#ifndef SUPER_MARIO_GAME_H
#define SUPER_MARIO_GAME_H

#include "defs.h"

#include "Menu.h"
#include "Engine.h"

/**
 * Klasa odpowiedzialna za inicjalizacje programu.
 * Należy ją wywołać w głównym pliku.
 */
class Game {
public:
    Game() = default;
    void run();

private:
    sf::RenderWindow window = sf::RenderWindow(
            sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
            "Super Mario Bros");
    Engine engine;
};


#endif //SUPER_MARIO_GAME_H
