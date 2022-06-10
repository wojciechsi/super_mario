#include "headers/Enemy.h"

void Enemy::update() {
    MovingItem::update();
    bounceFromOther();
    move(velocity, 0);
    flipTextureToMoveDirection();
}

void Enemy::bounceFromOther() {
    if (collisions.left or collisions.right) {
        velocity *= -1;
    }
}

void Enemy::flipTextureToMoveDirection() {
    if (velocity < 0) {
        this->sprite.setScale(-1.0f, 1.0f);
        this->move(this->size.x, 0.0);
    }
    else {
        this->sprite.setScale(1.0f, 1.0f);
        this->move(this->size.x, 0.0);
    }
}

void Enemy::setLeftAndRightCollisons(bool left, bool right) {
    if (left) this->collisions.left = left;
    if (right) this->collisions.right = right;
}

bool Enemy::operator==(const Enemy &rEnemy) {
    if (this->x == rEnemy.x and this->y == rEnemy.y)
        return true;
    else return false;
}



