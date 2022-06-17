#ifndef SUPER_MARIO_GAME_H
#define SUPER_MARIO_GAME_H

#include <chrono>
#include "defs.h"
#include "Menu.h"
#include "Mario.h"
#include "Level.h"
#include "Window.h"
#include "OptionsMenu.h"
#include "TexturesStorage.h"
#include "PauseMenu.h"


/**
 * Silnik gry
 */
class Game {
public:
    Game();

    /**
     * Głowna pętla programu
     */
    void run();

private:
    Window window;
    Mario mario;
    Level level;
    Menu menu;
    OptionsMenu optionsMenu;
    PauseMenu pauseMenu;
    sf::Music gameMusic;
    sf::Music menuMusic;

    bool gameON = true;
    bool paused = false;
    bool getBackToMenu = false;
    float gameCooldown = 15.f;
    float gameCooldownmin = 0.f;
    float gameCooldownmax = 15.f;

    sf::Text scoreDisplayText; //@todo ScoreBar class
    sf::Text gameOverText[3];
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();

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

    /**
     * Wstrzymuje grę.
     */
    void pause();

    /**
     * Wznawia grę/
     */
    void unpause();

    /**
     * Wyświetla menu główne.
     */
    void displayMenu();

    /**
     * Rozpoczyna grę od początku;
     */
    void restartGame(int lives = 3) {mario = Mario(lives); level = Level(); gameMusic.play();}

    /**
     * Przechwytuje wezwanie pauzy.
     */
    void handlePauseEvent();

    /**
     * Przechwytuje wezwanie do zamknięcia okna.
     */
    void handleWindowExit();

    /**
     * Wyświetla grę na ekranie.
     */
    void displayGame();

    /**
     * Wyświetla ilość pozostałych żyć.
     */
    void displayLives();

    void displayScore();

    void loadSoundAndText();
};

#endif //SUPER_MARIO_GAME_H
