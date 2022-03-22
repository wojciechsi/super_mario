//
// Created by wojciech on 21.03.2022.
//

#ifndef SUPER_MARIO_GAME_H
#define SUPER_MARIO_GAME_H

#include "defs.h"

#include "Menu.h"
#include "Engine.h"

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
