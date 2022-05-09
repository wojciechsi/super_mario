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

    bool isGoesRight() const;

    void die();

    void addPoints (int points);
private:

    bool isBig = false;
    bool goesRight = false;
    int points = 0;
    int jumpCtr = 0;
};


#endif //SUPER_MARIO_MARIO_H
