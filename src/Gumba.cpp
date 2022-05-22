#include "headers/Gumba.h"

Gumba::Gumba() : Enemy(0, 0) {
    velocity = BASIC_ENEMY_SPEED;
}

Gumba::Gumba(int iX, int iY) : Gumba() {
    move(iX, iY);
}

void Gumba::die() {
    MovingItem::die();
    std::cout << "GUMBA";
}