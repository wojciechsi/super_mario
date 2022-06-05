#ifndef SUPER_MARIO_MARIO_H
#define SUPER_MARIO_MARIO_H

#include "defs.h"
#include "MovingItem.h"
#include "TexturesStorage.h"

/**
 * Klasa przechowuje dane o głównej postaci gry
 */
class Mario : virtual public MovingItem{
public:
    Mario();

    /**
     * Aktualizuje stan - metoda najwyższego poziomu abstrakcji dla klasy.
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

    bool getDeadStatus();

    /**
     * Wykrywanie kolizji po prawej stronie
     * @return
     */
    bool hasRightCollision() {return collisions.right;}

    /**
     * Dodaje punkty dla gracza
     * @param points ilość punktów
     */
    void addPoints (int points);

    int getPoints();

    void jumpWithinConditions () {this->move(0.0f, -50.0f); /*jumpCtr = MAX_JUMP*/;}
private:
    int deadProcessCtr = 0;
    bool isBig = false;
    bool goesRight = false;
    int points = 0;
    bool dead = false;
public:
    int getPoints() const {
        return points;
    }

private:
    int jumpCtr = 0;

    /**
     * Wyzwala skok
     */
    void jump() {if (this->hasDownCollision()) jumpCtr = MAX_JUMP;}

    /**
     * Przetwarza skok, jeśli jest
     */
    void jumpProcess();

    /**
     * Przetwarza proces umierania, jeśli jest.
     */
    void deadProcess();

    /**
     * Przyjmuje i przetwarza dane wprowadzane z klawiatury.
     */
    void handleKeyboardInputs();

    /**
     * Wyzwala ruch w lewo.
     */
    void moveLeft();

    /**
     * Wyzwala ruch w prawo.
     */
    void moveRight();
};


#endif //SUPER_MARIO_MARIO_H
