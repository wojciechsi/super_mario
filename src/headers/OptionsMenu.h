//
// Created by Tomek on 16.06.2022.
//

#ifndef SUPER_MARIO_OPTIONSMENU_H
#define SUPER_MARIO_OPTIONSMENU_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.h"
#include "defs.h"
#include "TexturesStorage.h"


#define Max_options_menu 2

class OptionsMenu
{
public:
    OptionsMenu() : OptionsMenu(SCREEN_WIDTH, SCREEN_HEIGHT) {}
    OptionsMenu(float width, float height);
    void draw(sf::RenderWindow& window);
    void up();
    void down();
    bool getEnd();
    void select();
    void handleKeyboardInput(sf::RenderWindow &window);
    int Pressed()
    {
        return selected;
    }
    void returnToMenu();
    void setReturn();
    bool getReturn();
    bool displayTextBox = false;
    bool ifTextbox();
    void setTextBox();
private:

    sf::RectangleShape background;
    int selected;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text optionsMenu[Max_options_menu];
    float cooldown = 15.f;
    float cooldownmin = 0.f;
    float cooldownmax = 15.f;
    bool wantReturn = false;



};

#endif //SUPER_MARIO_OPTIONSMENU_H
