#ifndef SUPER_MARIO_MENU_H
#define SUPER_MARIO_MENU_H

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "defs.h"

#define Max_main_menu 5
/**
 * Klasa zapewniająca opcje wyboru
 */
class Menu {
public:
    Menu() : Menu(SCREEN_WIDTH, SCREEN_HEIGHT) {}
    Menu(float width, float height);
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
    ~Menu();
private:
    int selected;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
    float cooldown = 15.f;
    float cooldownmin = 0.f;
    float cooldownmax = 15.f;
    bool end = false;
};


#endif //SUPER_MARIO_MENU_H
