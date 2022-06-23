#ifndef SUPER_MARIO_TEXTBOX_H
#define SUPER_MARIO_TEXTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <memory>

#include "defs.h"

#define DELETE_KEY 8
#define ENTER_KEY  13
#define ESCAPE_KEY 27

class TextBox
{
public:
    TextBox();
    TextBox(int size, sf::Color color, bool sel);
    /**
     * Ustawia pozycję pola tekstowego.
     */
    void setPosition(sf::Vector2f pos);
    void setLimit(bool ToF);
    /**
     * Ustawia limit znaków w polu tekstowym.
     * @param ToF
     * @param lim
     */
    void setLimit(bool ToF, int lim);
    /**
     * Ustawia flagę wybranego pola tekstowego.
     * @param sel Czy pole tekstowe jest wybrane.
     */
    void setSelected(bool sel);
    /**
     * Zwraca tekst w polu tekstowym w formie std::string.
     */
    std::string getText();
    /**
     * Wyświetla pole tekstowe na ekranie.
     * @param window Okno wyświetlania
     */
    void draw(sf::RenderWindow& window);
    /**
     * Metoda odpowiedzialna za działanie klasy.
     * @param ev Czy użytkownik wpisuje nazwę z klawiatury.
     */
    void typed(sf::Event ev);


private:
    sf::Text textBox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    /**
     * Logika wpisywania do pola tekstowego.
     * @param charTyped Wpisany znak.
     */
    void inputLogic(int charTyped);
    /**
     * Metoda odpowiedzialna za usuwanie ostatniego znaku.
     */
    void deleteLastChar();
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
};






#endif //SUPER_MARIO_TEXTBOX_H
