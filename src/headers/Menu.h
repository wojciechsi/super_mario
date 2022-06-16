#ifndef SUPER_MARIO_MENU_H
#define SUPER_MARIO_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.h"
#include "defs.h"
#include "TexturesStorage.h"

#define Max_main_menu 5
/**
 * Klasa zapewniająca opcje wyboru
 */
class Menu {
public:
    Menu() : Menu(SCREEN_WIDTH, SCREEN_HEIGHT) {}
    Menu(float width, float height);

    /**
     * Metoda wyświetla menu na ekranie.
     */
    void draw(sf::RenderWindow& window);

    /**
     * Do góry...
     */
    void drawOptions(sf::RenderWindow& window);
    void up();
    void down();
    bool getEnd();
    void select();
    bool getOptions();
    void setOptions();
    void handleKeyboardInput(sf::RenderWindow &window);
    int Pressed()
    {
        return selected;
    }
    void setEnd();
private:
    sf::RectangleShape background;
    int selected;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text mainMenu[Max_main_menu];
    sf::Text optionsMenu[2];
    float cooldown = 15.f;
    float cooldownmin = 0.f;
    float cooldownmax = 15.f;
    bool end = false;
    bool wantLeave = false;
    bool newGame = false;
    bool options = false;
public:
    bool isNewGame() const;

public:
    bool doWantToLeave() const;
};


#endif //SUPER_MARIO_MENU_H
