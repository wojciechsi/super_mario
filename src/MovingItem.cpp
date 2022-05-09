#include "headers/MovingItem.h"

MovingItem::MovingItem(int iX, int iY) : Item(iX, iY) {}

void MovingItem::move(const float x, const float y)
{
    if (x > 0 and collisions.right == false)
        this -> x += x;
    else if (x < 0 and collisions.left == false)
        this -> x += x;
    //to nie duplikacja tylko rozwinięcie pętli
    if (y > 0 and collisions.up == false)
        this -> y += y;
    else if (y < 0 and collisions.down == false)
        this -> y += y;
}

bool MovingItem::isOnTopOfAny() const {
    return collisions.up;
}

void MovingItem::setOnTopOfAny(bool rvalue) {
    collisions.up = rvalue;
}

void MovingItem::update() {
    gravityMove();
    //they also get updated from level instance
}


