#include "headers/Turtle.h"

Turtle::Turtle() : Enemy(0, 0) {
    velocity = BASIC_ENEMY_SPEED * 0.7;
    this->setTexture(TexturesStorage::getInstance()->getTurtleWalkingTexture());
}

Turtle::Turtle(int x, int y) : Turtle() {
    move(x,y);
}


void Turtle::die() {
    if (!this->isRunning()) {
        turtlemode = TurtleMode::running;
        this->setTexture(TexturesStorage::getInstance()->getTurtleRunningTexture());
        velocity = BASIC_ENEMY_SPEED * 2;
        move(velocity, 0.0f);
    }
    else {
        Enemy::die();
    }
}

bool Turtle::isRunning() {
    if (this->turtlemode == TurtleMode::running)
        return true;
    else
        return false;
}


