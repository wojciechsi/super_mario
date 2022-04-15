#ifndef SUPER_MARIO_ITEM_H
#define SUPER_MARIO_ITEM_H

#include <SFML/Graphics.hpp>
#include <string>

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

    Item(Item& other);

    /**
     * Po zadaniu tekstury ustawia też wymiary i środek
     * @param s ścieżka do tekstury
     */
    void setTexture (std::string s);

    void draw(sf::RenderWindow& iWindow);

    /**
     * Przesuwa jak mario chodzi
     * @todo inna nazwa metody
     */
    void walkMove ();

protected:

    float x{}, y{}; //pozycja

    sf::Vector2u size; //rozmiar na mapie

    sf::Sprite sprite;
private:

    sf::Texture texture;
};


#endif //SUPER_MARIO_ITEM_H
