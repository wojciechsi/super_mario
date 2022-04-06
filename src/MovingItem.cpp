#include "headers/MovingItem.h"

MovingItem::MovingItem(int iX, int iY) : Item(iX, iY) {}

void MovingItem::move(const float x, const float y)
{
    this -> x += x;
    this -> y += y;
}
