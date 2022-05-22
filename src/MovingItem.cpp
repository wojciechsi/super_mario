#include "headers/MovingItem.h"

MovingItem::MovingItem(int iX, int iY) : Item(iX, iY) {}

void MovingItem::move(const float x, const float y)
{
    if (x > 0 and collisions.right == false)
        this -> x += x;
    else if (x < 0 and collisions.left == false)
        this -> x += x;
    if (y > 0){
        if(collisions.down == false or !alive)
        this -> y += y;}
    else if (y < 0 and collisions.up == false)
        this -> y += y;
}

bool MovingItem::hasDownCollision() const {
    return collisions.down;
}

void MovingItem::update() {
    gravityMove();
    //they also get updated from level instance
}

void MovingItem::die() {
    alive = false;
}


