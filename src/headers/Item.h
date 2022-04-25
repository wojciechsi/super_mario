#ifndef SUPER_MARIO_ITEM_H
#define SUPER_MARIO_ITEM_H

#include <SFML/Graphics.hpp>
#include <string>
#include "defs.h"

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

    Item() = default;

    //Item(Item&&);

    Item(const Item& other);

    /**
     * Po zadaniu tekstury ustawia też wymiary i środek
     * @param s ścieżka do tekstury
     */
    void setTexture (std::string s);

    void setTexture (const sf::Texture& t);

    void draw(sf::RenderWindow& iWindow);

    /**
     * Przesuwa jak mario chodzi
     * @todo inna nazwa metody
     */
    void walkMove ();

    bool upDownTouch (Item);

    inline bool isOnScreen() {if (x > -10 and x < SCREEN_WIDTH) return true; else return false;}

protected:

    float x{}, y{}; //pozycja

    sf::Vector2u size; //rozmiar na mapie

    sf::Sprite sprite;
public:
    const sf::Sprite &getSprite() const;

private:

    sf::Texture texture;
};


#endif //SUPER_MARIO_ITEM_H
