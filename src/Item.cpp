#include "headers/Item.h"

Item::Item(const Item &other) {
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

void Item::setTexture(const sf::Texture& t) {
    texture = std::ref(t);
    sprite.setTexture(texture);
    size = texture.getSize();
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Item::walkMove() {
    x--;
}

bool Item::upDownTouch(Item up) {
    if (up.sprite.getGlobalBounds().intersects(this->sprite.getGlobalBounds())) return true;
    else return false;
}

const sf::Sprite &Item::getSprite() const {
    return sprite;
}

