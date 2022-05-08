#ifndef SUPER_MARIO_MOVINGITEM_H
#define SUPER_MARIO_MOVINGITEM_H

#include "Item.h"

/**
 * Klasa przechowuje informacje o poruszającym się obiekcie
 */
class MovingItem : public Item{
public:
    MovingItem() = default;
    MovingItem(const MovingItem& other) = default;
    MovingItem(int iX, int iY);
    void move(const float x, const float y);
private:
    bool onTopOfAny = false;

    void gravityMove() {move(0, GRAVITY_FACTOR);};
public:
    bool isOnTopOfAny() const;

    void setOnTopOfAny(bool onTopOfAny);



    /**
    * Aktualizuje położenie i stan
    */
    void update();
};


#endif //SUPER_MARIO_MOVINGITEM_H
