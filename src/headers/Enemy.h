#ifndef SUPER_MARIO_ENEMY_H
#define SUPER_MARIO_ENEMY_H

#include "MovingItem.h"

/**
 * Klasa reprezentuje wroga
 */
class Enemy : public MovingItem {
protected:
    float velocity;
public:
    Enemy () = default;

    Enemy (const Enemy& other) = default;

    Enemy (int iX, int iY) : MovingItem(iX, iY) {};
    //virtual void die() = 0;
    void update ();
};


#endif //SUPER_MARIO_ENEMY_H
