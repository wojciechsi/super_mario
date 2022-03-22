//
// Created by wojciech on 21.03.2022.
//

#include "headers/Object.h"

void Object::draw(sf::RenderWindow &iWindow) {
    sprite.setPosition(x, y);

    iWindow.draw(sprite);
}

Object::Object(int iX, int iY) :x(iX),
                                y(iY) {}

Object::Object() {}

void Object::setTexture(std::string s) {
    texture.loadFromFile(s);
    sprite.setTexture(texture);
}
