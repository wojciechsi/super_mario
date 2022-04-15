#include "headers/Item.h"

Item::Item(Item &other) {
    this->x = other.x;
    this->y = other.y;
    this->sprite = other.sprite;
    this->size = other.size;
    this->texture = other.texture;
}

void Item::draw(sf::RenderWindow &iWindow) {
   sprite.setPosition(x, y);
   iWindow.draw(sprite);
}

Item::Item(int iX, int iY) : x(iX), y(iY) {}

void Item::setTexture(std::string s) {
    texture.loadFromFile(s);
    sprite.setTexture(texture);
    size = texture.getSize();
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Item::walkMove() {
    x--;
}

