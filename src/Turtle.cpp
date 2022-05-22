#include "headers/Turtle.h"

Turtle::Turtle() : Enemy(0, 0) {
    velocity = BASIC_ENEMY_SPEED * 0.7;
}

Turtle::Turtle(int x, int y) : Turtle() {
    move(x,y);
}


void Turtle::die() {
    if (turtlemode == TurtleMode::walking) {
        turtlemode = TurtleMode::running;
        this->setTexture(TexturesStorage::getInsatnce()->getTurtleRunningTexture());
        velocity = BASIC_ENEMY_SPEED * 2;
        move(velocity, 16.0f);
    }
    else {
        MovingItem::die();
    }
}

bool Turtle::isRunning() {
    if (this->turtlemode == TurtleMode::running)
        return false;
    else
        return true;
}


