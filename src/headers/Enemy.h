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
    //virtual void die() = 0; //pure virtual methods are allowed by compiler as long
    //as you provide it's declaration in ALL child classes
    /**
     * Rozszerza metodę klasy MovingItem o automatyczny ruch i odbicia
     */
    void update ();
private:
    /**
     * Odbija od ewentualnych przeszkód
     */
    void bounceFromOther();
};


#endif //SUPER_MARIO_ENEMY_H
