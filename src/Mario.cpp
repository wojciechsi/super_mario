#include "headers/Mario.h"

Mario::Mario() : MovingItem(0.5f * SCREEN_WIDTH,
                            0.5f * SCREEN_HEIGHT) {
    setTexture("../src/resources/smallMario.png");
}

void Mario::update()
{
    MovingItem::update();
    goesRight = false;
    handleKeyboardInputs();
    jumpProcess();
    deadProcess();
}

void Mario::handleKeyboardInputs() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        //nie wypuść ne lewo od ekran
        this->sprite.setScale(-1.0f, 1.0f);
        if (this->sprite.getPosition().x < (this->size.x) / 2) return;
        else this->move(-1.0f, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        this->sprite.setScale(1.0f, 1.0f);
        if (this->sprite.getPosition().x < SCREEN_WIDTH / 2)
            this->move(1.0f, 0);
        else goesRight = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        if (this->hasDownCollision()) jump();
    }
}

bool Mario::isGoesRight() const {
    return goesRight;
}

void Mario::die() {
    MovingItem::die();
    deadProcessCtr = DIE_TIME;
    jump();

}

void Mario::addPoints(int addedPoints) {
    points += addedPoints;
}

void Mario::jumpProcess() {
    if (jumpCtr > 0) move(0, JUMP_VELOCITY);
    if (collisions.up) jumpCtr = 0; //BUXFIX 5454841
    if (jumpCtr > 0) jumpCtr--;
}

void Mario::deadProcess() {
    if (deadProcessCtr > 0) deadProcessCtr--;
}