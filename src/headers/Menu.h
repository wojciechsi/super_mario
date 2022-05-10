#ifndef SUPER_MARIO_MENU_H
#define SUPER_MARIO_MENU_H

#include <SFML/Graphics.hpp>

#define Max_main_menu 5
/**
 * Klasa zapewniająca opcje wyboru
 */
class Menu {
public:
    Menu(float width, float height);
    void draw(sf::RenderWindow& window);
    void Up();
    void Down();

    int Pressed()
    {
        return selected;
    }
    ~Menu();
private:
    int selected;
    sf::Font font;
    sf::Text mainMenu[Max_main_menu];
};


#endif //SUPER_MARIO_MENU_H
