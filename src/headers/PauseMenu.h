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
    void blur(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void up();
    void down();
    void handleInput();
    bool getexitStatus();
    void changeExitStatus();

private:
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text pauseMenu[2];
    int selected;
    float cooldown = 15.f;
    float cooldownmin = 0.f;
    float cooldownmax = 15.f;
    bool exit = false;
};


#endif //SUPER_MARIO_PAUSEMENU_H
