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

void Item::moveOneStepLeft() {
    x--;
}

const sf::Sprite &Item::getSprite() const {
    return sprite;
}

Bonduaries Item::getBonduariesBoxes() {
    sf::FloatRect rectangle = sprite.getGlobalBounds();
    Bonduaries b;
    b.leftBonduary = sf::FloatRect (rectangle.left, rectangle.top,
                                     ITEM_COLL_WIDTH, rectangle.height);
    b.rightBonduary = sf::FloatRect (rectangle.left + rectangle.width, rectangle.top,
                                      -ITEM_COLL_WIDTH, rectangle.height);
    b.topBonduary = sf::FloatRect (rectangle.left + ITEM_COLL_OFFSET, rectangle.top,
                                    rectangle.width -2*ITEM_COLL_OFFSET,  ITEM_COLL_WIDTH);
    b.bottomBonduary = sf::FloatRect (rectangle.left + ITEM_COLL_OFFSET, rectangle.top + rectangle.height,
                                       rectangle.width - 2*ITEM_COLL_OFFSET, ITEM_COLL_WIDTH);
    return b;
}

void Item::setTexture(std::shared_ptr<sf::Texture> t) {
    pTexture = t;
    sprite.setTexture(*pTexture.lock());
    size = texture.getSize();
    sprite.setOrigin(size.x / 2, size.y / 2);
}


