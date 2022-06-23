//
// Created by Tomek on 03.06.2022.
//

#ifndef SUPER_MARIO_PAUSEMENU_H
#define SUPER_MARIO_PAUSEMENU_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.h"
#include "defs.h"
#include "TexturesStorage.h"



class PauseMenu{
private:
    sf::Texture blurTexture;
    sf::Sprite  blurSprite;
public:
    PauseMenu() : PauseMenu(SCREEN_WIDTH, SCREEN_HEIGHT) {}
    PauseMenu(float width, float height);
    ~PauseMenu();
    /**
     * Nakładanie efektu rozmycia w menu pauzy.
     * @param window
     */
    void blur(sf::RenderWindow& window);
    /**
     * Wyświetlanie menu pauzy podczas gry.
     * @param window
     */
    void draw(sf::RenderWindow& window);
    /**
     * Wybór opcji powyżej.
     */
    void up();
    /**
     * Wybór opcji poniżej.
     */
    void down();
    /**
     * Przetwarzanie danych wejściowych użytkownika.
     */
    void handleInput();
    /**
     * Informacja, czy użytkownik chce wrócić do menu.
     * @return Informacja o powrocie do menu.
     */
    bool getexitStatus();
    /**
     * Zmienia flagę powrotu do menu głównego.
     */
    void changeExitStatus();
    /**
     * Zwraca flagę, czy użytkownik chce powrócić do gry.
     * @return Flaga powrotu do gry.
     */
    bool getBackStatus();
    /**
     * Zmiana flagi powrotu do gry.
     */
    void changeBackStatus();

private:
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text pauseMenu[2];
    int selected;
    float cooldown = 15.f;
    float cooldownmax = 15.f;
    bool exit = false;
    bool back = false;
};


#endif //SUPER_MARIO_PAUSEMENU_H
