#include "headers/Enemy.h"

void Enemy::update() {
    MovingItem::update();
    bounceFromOther();
    move(velocity, 0);
}

void Enemy::bounceFromOther() {
    if (collisions.left or collisions.right)
        velocity *= -1;
}
