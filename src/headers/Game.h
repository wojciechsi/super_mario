#ifndef SUPER_MARIO_GAME_H
#define SUPER_MARIO_GAME_H

#include "defs.h"
#include "Menu.h"
#include "Mario.h"
#include "Level.h"
/**
 * Klasa odpowiedzialna za inicjalizacje programu
 * i jego ciągłość działania.
 * Należy ją wywołać w głównym pliku.
 */
class Game {
public:
    Game() = default;

    /**
     * Głowna pętla programu
     */
    void run();



private:
    sf::RenderWindow window = sf::RenderWindow(
            sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
            "Super Mario Bros");

    void updateWindow (sf::RenderWindow&);

    Mario mario;

    Level level;

    bool gameON = true;

    void handleEvents();

    bool ifMarioShouldDie();
};



#endif //SUPER_MARIO_GAME_H
