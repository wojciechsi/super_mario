#include "headers/Brick.h"

void Brick::kickUp() {
    if (jumpCtr == 0)
        jumpCtr += 10;
    hasCoin = false;
    this->sprite.setTexture(*TexturesStorage::getInstance()->getEmptyBrickTexture());
}

void Brick::jumpProcess() {
    if (jumpCtr > 0) {
        this->y--;
        jumpCtr--;
        landCtr++;
    }
    if (jumpCtr == 0 and landCtr > 0) {
        this->y++;
        landCtr--;
    }
}