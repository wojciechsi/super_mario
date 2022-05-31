#ifndef SUPER_MARIO_BRICK_H
#define SUPER_MARIO_BRICK_H

#include "Item.h"
#include "TexturesStorage.h"

class Brick : public Item{
private:
    int jumpCtr = 0, landCtr = 0;
public:
    Brick(float x, float y) : Item(x,y) {this->setTexture(TexturesStorage::getInstance()->getBrickTexture());}

    void jumpProcess() {
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

    void kickUp() {
        jumpCtr += 10;
    }
};


#endif //SUPER_MARIO_BRICK_H
