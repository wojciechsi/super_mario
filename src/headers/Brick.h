#ifndef SUPER_MARIO_BRICK_H
#define SUPER_MARIO_BRICK_H

#include "Item.h"
#include "TexturesStorage.h"

class Brick : public Item{
private:
    int jumpCtr = 0, landCtr = 0;
    bool hasCoin = true;
public:
    Brick(float x, float y) : Item(x,y) {this->setTexture(TexturesStorage::getInstance()->getBrickTexture());}

    /**
     * Przetwarza ewentualne podrzucenie.
     */
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

    /**
     * Wyzwala podrzucenie po uderzeniu weń głową gracza.
     */
    void kickUp() {
        if (jumpCtr == 0)
            jumpCtr += 10;
        hasCoin = false;
        this->sprite.setTexture(*TexturesStorage::getInstance()->getEmptyBrickTexture());
    }

    /**
     * Zwraca informacje o przechowywaniu monety.
     * @todo animacja
     */
    bool ifHasCoin() {return hasCoin;}
};


#endif //SUPER_MARIO_BRICK_H
