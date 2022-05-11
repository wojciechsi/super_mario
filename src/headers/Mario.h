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

    /**
     * Zarządza ruchem gracza
     */
    void update();

    /**
     * Zwraca informację o ewentualnym ruchu w prawo, za połowę ekranu.
     * @return
     */
    bool isGoesRight() const;

    /**
     * Rozpoczyna proces umierania gracza
     */
    void die();

    bool hasRightCollision() {return collisions.right;}

    /**
     * Dodaje punkty dla gracza
     * @param points ilość punktów
     */
    void addPoints (int points);

private:
    int deadProcessCtr = 0;
    bool isBig = false;
    bool goesRight = false;
    int points = 0;
    int jumpCtr = 0;

    void jump() {jumpCtr = MAX_JUMP;}
    void jumpProcess();
    void handleKeyboardInputs();
};


#endif //SUPER_MARIO_MARIO_H
