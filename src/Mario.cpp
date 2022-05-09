#include "headers/Mario.h"

Mario::Mario() : MovingItem(0.5f * SCREEN_WIDTH,
                            0.5f * SCREEN_HEIGHT) {
    setTexture("../src/resources/smallMario.png");
}

void Mario::MoveStatus()
{

    {//@todo this method should provide keyboard inputs XOR updating stuff
        goesRight = false;
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
            if (this->hasDownCollision()) jumpCtr = MAX_JUMP;
        }

        if (jumpCtr > 0) move(0, -5.0f);
        if (collisions.up) jumpCtr = 0; //BUXFIX 5454841
        if (jumpCtr > 0) jumpCtr--;
    }

}

bool Mario::isGoesRight() const {
    return goesRight;
}

void Mario::die() {
    MovingItem::die();
    std::cout<<"MARIO ";
    jumpCtr = MAX_JUMP;
    //change texture
}

void Mario::addPoints(int addedPoints) {
    points += addedPoints;
}
