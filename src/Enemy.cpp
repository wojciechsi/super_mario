//
// Created by wojciech on 21.03.2022.
//

#include "headers/Enemy.h"

void Enemy::update() {
    if (!isOnTopOfAny()) move(0, 1);
    move(velocity, 0);
}


