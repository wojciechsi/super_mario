#ifndef SUPER_MARIO_MARIO_H
#define SUPER_MARIO_MARIO_H

#include "defs.h"
#include "MovingItem.h"

/**
 * Klasa przechowuje dane o głównej postaci gry
 */
class Mario : virtual public MovingItem{
public:
    Mario();
    void MoveStatus();
    sf::RectangleShape MarioShape;
private:
    bool isBig = false;
};


#endif //SUPER_MARIO_MARIO_H
