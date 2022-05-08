#include "headers/MovingItem.h"

MovingItem::MovingItem(int iX, int iY) : Item(iX, iY) {}

void MovingItem::move(const float x, const float y)
{
    //@todo space condition (there is no other place for that!!!)
    this -> x += x;
    this -> y += y;
}

bool MovingItem::isOnTopOfAny() const {
    return onTopOfAny;
}

void MovingItem::setOnTopOfAny(bool onTopOfAny) {
    MovingItem::onTopOfAny = onTopOfAny;
}


void MovingItem::update() {
    if (!isOnTopOfAny()) gravityMove();
}


