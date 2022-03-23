#ifndef SUPER_MARIO_OBJECT_H
#define SUPER_MARIO_OBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * Klasa przechowuje informacje o obiekcie w grze
 */
class Object {
public:
    Object(int, int);

    Object();

    void setTexture (std::string);

    void draw(sf::RenderWindow& iWindow);
private:
    double x, y;

    sf::Sprite sprite;

    sf::Texture texture;
};


#endif //SUPER_MARIO_OBJECT_H
