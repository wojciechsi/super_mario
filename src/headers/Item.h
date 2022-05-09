#ifndef SUPER_MARIO_ITEM_H
#define SUPER_MARIO_ITEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include "defs.h"
#include <memory>

struct Bonduaries {
    sf::FloatRect leftBonduary;
    sf::FloatRect rightBonduary;
    sf::FloatRect topBonduary;
    sf::FloatRect bottomBonduary;
};

/**
 * Klasa przechowuje informacje o obiekcie w grze
 */
class Item {
public:

    /**
     * Umieszcza na ekranie element w zadanym miejscu.
     * @param x
     * @param y
     */
    Item(int x, int y);

    Item() : x(0), y(0), size(sf::Vector2u(0,0)) { };

    Item(int x, int y, const sf::Texture& t) : Item(x, y) {setTexture(t);};

    Item(const Item& other);

    /**
     * Po zadaniu tekstury ustawia też wymiary i środek
     * @param s ścieżka do tekstury
     */
    void setTexture (std::string s);

    void setTexture (const sf::Texture& t);

    void draw(sf::RenderWindow& iWindow);

    /**
     * Przemieszcza wszystkie elementy o jednen krok w lewo
     */
    void moveOneStepLeft ();

    bool upDownTouch (Item);

    inline bool isOnScreen() {if (x > -10 and x < (SCREEN_WIDTH + 10)) return true; else return false;}


protected:

    float x{}, y{}; //pozycja

    sf::Vector2u size; //rozmiar na mapie

    sf::Sprite sprite;
public:
    const sf::Sprite &getSprite() const;

    sf::Sprite getSprite() {return sprite;}

    Bonduaries getBonduariesBoxes();

private:

    sf::Texture texture;
};


#endif //SUPER_MARIO_ITEM_H
