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

    Item(int x, int y, std::shared_ptr<sf::Texture> t) : Item(x, y) {setTexture(t);};

    Item(const Item& other);

    /**
     * Po zadaniu tekstury ustawia też wymiary i środek.
     * @param s ścieżka do tekstury
     */
    void setTexture (std::string s);

    void setTexture(std::shared_ptr<sf::Texture> t);

    void draw(sf::RenderWindow& iWindow);

    /**
     * Przemieszcza wszystkie elementy o jednen krok w lewo
     */
    void moveOneStepLeft ();

    /**
     * Funkcja filtrująca iteracje
     * @return czy analiza danego elementu ma sens
     */
    inline bool isOnScreen() {if (x > -SCREEN_LOAD_OFFSET and x < (SCREEN_WIDTH + SCREEN_LOAD_OFFSET)) return true; else return false;}
    inline bool isAround(float ix) {if (x > ix -20 and x < ix +20 ) return true; else return false;}
    inline bool isNearbyX(const Item& other) {
        if (abs(this->x - other.x) < 20)
            return true;
        else return false;
    }
    //----------x-------------------
    //-----------ix---------------

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
    std::weak_ptr<sf::Texture> pTexture;
};


#endif //SUPER_MARIO_ITEM_H
