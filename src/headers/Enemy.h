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
    /**
     * Rozszerza metodę klasy MovingItem o automatyczny ruch i odbicia
     */
    void update ();

    bool operator==(const Enemy& rEnemy);

    /**
    * Ustawia lewą i prawą kolizję
    * @param left lewa kolizja
    * @param right prawa kolizja
    */
    void setLeftAndRightCollisons (bool left, bool right);
private:
    /**
     * Odbija od ewentualnych przeszkód
     */
    void bounceFromOther();

    /**
     * Ustawia teksturę względem kierunku ruchu.
     */
    void flipTextureToMoveDirection ();


};


#endif //SUPER_MARIO_ENEMY_H
