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
    void jumpProcess();

    /**
     * Wyzwala podrzucenie po uderzeniu weń głową gracza.
     */
    void kickUp();

    /**
     * Zwraca informacje o przechowywaniu monety.
     */
    bool ifHasCoin() {return hasCoin;}
};


#endif //SUPER_MARIO_BRICK_H
