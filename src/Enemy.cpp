#include "headers/Enemy.h"

void Enemy::update() {
    MovingItem::update();
    move(velocity, 0);
}


