#ifndef SUPER_MARIO_MARIO_H
#define SUPER_MARIO_MARIO_H

#include "defs.h"
#include "SFML/Audio.hpp"
#include "MovingItem.h"
#include "TexturesStorage.h"
#include <iostream>

/**
 * Klasa przechowuje dane o głównej postaci gry
 */
class Mario : virtual public MovingItem{
public:
    Mario();

    explicit Mario(int prevLives) : Mario() {lives = prevLives;}

    /**
     * Aktualizuje stan - metoda najwyższego poziomu abstrakcji dla klasy.
     */
    void update() override;

    /**
     * Zwraca informację o ewentualnym ruchu w prawo, za połowę ekranu.
     * @return
     */
    bool isGoesRight() const;

    /**
     * Rozpoczyna proces umierania gracza
     */
    void die() override;

    bool getTotalDeadStatus();

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

    void jumpWithinConditions () {this->move(0.0f, -50.0f);}

    int getLives() const;

    bool checkLostLife ();
private:
    int deadProcessCtr = 0;
    bool isBig = false;
    bool goesRight = false;
    int points = 0;
    int lives = 3;
    bool lostLife = false;
    bool dead = false;
    sf::Sound marioSound;
    sf::SoundBuffer jumpSound;
    sf::SoundBuffer deathSound;
    int jumpCtr = 0;

    /**
     * Wyzwala skok
     */
    void jump() {
        if (this->hasDownCollision()) {
            if(!dead) {
                marioSound.setBuffer(jumpSound);
                marioSound.play();
            }
            jumpCtr = MAX_JUMP;
        }
    }

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
