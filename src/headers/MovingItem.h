#ifndef SUPER_MARIO_MOVINGITEM_H
#define SUPER_MARIO_MOVINGITEM_H

#include "Item.h"

/**
 * Klasa przechowuje informacje o poruszającym się obiekcie
 */
class MovingItem : public Item{
public:
    MovingItem(int, int);
    void move(const float x,const float y);
private:
    int vertitalSpeed, horizontalSpeed;

};


#endif //SUPER_MARIO_MOVINGITEM_H
