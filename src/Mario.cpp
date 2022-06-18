#include "headers/Mario.h"

Mario::Mario() : MovingItem(0.5f * SCREEN_WIDTH,
                            0.5f * SCREEN_HEIGHT) {
    setTexture(TexturesStorage::getInstance()->getMarioTexture());
    if(!jumpSound.loadFromFile("../src/resources/jump.wav"))
    {
        std::cerr << "Jump sound loading error\n";
    }
    if(!deathSound.loadFromFile("../src/resources/death.wav"))
    {
        std::cerr <<"Death sound loading error\n";
    }
}

void Mario::update() {
    MovingItem::update();
    goesRight = false;
    handleKeyboardInputs();
    jumpProcess();
    deadProcess();
}

void Mario::handleKeyboardInputs() {
    if(this->isAlive()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            jump();
        }
    }
}

void Mario::moveRight() {
    if (this->sprite.getScale() != sf::Vector2f (1.0f, 1.0f)) {
        this->sprite.setScale(1.0f, 1.0f);
        this->move(-16.0f, 0.0);
    }
    else if (this->sprite.getPosition().x < SCREEN_WIDTH / 2)
        this->move(1.0f, 0);
    else goesRight = true;
}

void Mario::moveLeft() {
    if (this->sprite.getScale() != sf::Vector2f (-1.0f, 1.0f)) {
        this->sprite.setScale(-1.0f, 1.0f);
        this->move(16.0f, 0.0);
    }
    else if (this->sprite.getPosition().x < (this->size.x) / 2) return;
    else this->move(-1.0f, 0);
}

bool Mario::isGoesRight() const {
    return goesRight;
}

void Mario::die() {
    marioSound.setBuffer(deathSound);
    marioSound.play();
    lostLife = true;
    lives--;
    if (lives == 0) {
        MovingItem::die();
        dead = true;
        deadProcessCtr = DIE_TIME;
        jump();
    }

}

void Mario::addPoints(int addedPoints) {
    points += addedPoints;
}

void Mario::jumpProcess() {
    if (jumpCtr > 0) move(0, JUMP_VELOCITY);
    if (collisions.up) jumpCtr = 0;
    if (jumpCtr > 0) jumpCtr--;
}

void Mario::deadProcess() {
    if (deadProcessCtr > 0) deadProcessCtr--;
    if (this->y > SCREEN_HEIGHT) this->die();
}

int Mario::getPoints()
{
    return points;
}

bool Mario::getDeadStatus() {
    return dead;
}

int Mario::getLives() const {
    return lives;
}

bool Mario::checkLostLife() {
    return lostLife;
}


