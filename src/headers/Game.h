#ifndef SUPER_MARIO_GAME_H
#define SUPER_MARIO_GAME_H

#include <chrono>
#include "defs.h"
#include "Menu.h"
#include "Mario.h"
#include "Level.h"
#include "Window.h"
#include "TexturesStorage.h"
#include "PauseMenu.h"


/**
 * Silnik gry
 */
class Game {
public:
    Game() = default;

    /**
     * Głowna pętla programu
     */
    void run();

private:
    Window window;
    Mario mario;
    Level level;
    Menu menu;
    PauseMenu pauseMenu;
    bool gameON = true;
    bool paused = false;
    float gameCooldown = 15.f;
    float gameCooldownmin = 0.f;
    float gameCooldownmax = 15.f;




    /**
     * Aktualizuje stan gry i przetwarza informaje.
     */
    void updateGame ();

    /**
     * Przetwarza wydarzenia spoza mechaniki gry.
     */
    void handleEvents();

    /**
     * Wysyła aktualne dane do wyświetlenia.
     */
    void renderContent();

    /**
     * Przetwarza relacje między elementami gry.
     */
    void processRelations();

    /**
     * Wyszukuje możliwość i wyzwala śmierci wrogów lub gracza.
     */
    void updateWhatMarioWithEnemiesDo ();

    void pause();

    void unpause();
};

#endif //SUPER_MARIO_GAME_H
