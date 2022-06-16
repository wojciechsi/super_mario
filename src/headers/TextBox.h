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
    void setPosition(sf::Vector2f pos);
    void setLimit(bool ToF);
    void setLimit(bool ToF, int lim);
    void setSelected(bool sel);
    std::string getText();
    void draw(sf::RenderWindow& window);
    void typed(sf::Event ev);
    static TextBox createTextBox();


private:
    sf::Text textBox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    void inputLogic(int charTyped);
    void deleteLastChar();
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
};






#endif //SUPER_MARIO_TEXTBOX_H
