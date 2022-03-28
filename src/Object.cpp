#include "headers/Object.h"

void Object::draw(sf::RenderWindow &iWindow) {
   sprite.setPosition(x, y);

    iWindow.draw(sprite);
}

Object::Object(int iX, int iY) :x(iX), y(iY) {this -> shape.setSize(sf::Vector2f(50.f, 50.f));}

Object::Object() {}

void Object::setTexture(std::string s) {
    texture.loadFromFile(s);
    sprite.setTexture(texture);
}

void Object::move(const float x, const float y)
{
    this -> x += x;
    this -> y += y;
}
