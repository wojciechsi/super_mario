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
    /**
     * Metoda wyświetla menu opcji na ekranie
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
     * Przetwarzania danych wejściowych użytkownika
     */
    void handleKeyboardInput(sf::RenderWindow &window);
    /**
     * Metoda zwraca wybraną opcję w menu opcji.
     */
    int Pressed()
    {
        return selected;
    }
    /**
     * Metoda zwraca informacje, czy użytkownik chce wrócić do menu.
     */
    void returnToMenu();
    /**
     * Metoda ustawia flagę powrotu do menu głównego.
     */
    void setReturn();
    /**
     * Metoda zwraca informację, czy użytkownik chce wrócić do menu głównego.
     */
    bool getReturn();
    bool displayTextBox = false;
    /**
     * Metoda zwraca informację, czy użytkownik chce wyświetlić pole tekstowe.
     */
    bool ifTextbox();
    /**
     * Metoda ustawia flagę pola tekstowego..
     */
    void setTextBox();
private:

    sf::RectangleShape background;
    int selected;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text optionsMenu[Max_options_menu];
    float cooldown = 15.f;
    float cooldownmin = 0.f;
    float cooldownmax = 30.f;
    bool wantReturn = false;



};

#endif //SUPER_MARIO_OPTIONSMENU_H
