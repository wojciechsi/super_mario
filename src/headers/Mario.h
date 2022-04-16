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
    //sf::RectangleShape MarioShape;

    bool isGoesRight() const;

    void jump();

private:
    bool isBig = false;
    bool goesRight = false;

    int jumpCtr = 0;
};


#endif //SUPER_MARIO_MARIO_H
