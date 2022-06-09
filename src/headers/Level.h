#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
#include "defs.h"
#include "Brick.h"
#include "Mario.h"
#include <iostream>
#include <thread>
#include <ranges>
#include <fstream>
#include <string>
#include "TexturesStorage.h"


/**
 * Klasa zawiera aktualny poziom gry
 */
class Level {
public:
    Level();

    /**
     * Renderuje elementy poziomu na ekranie
     * @param iwindow okno
     */

    const void createFirstLevel();
    void createLevelFromFile();


    void printLevelContent (sf::RenderWindow &iwindow);

    /**
     * Przemieszcza cały świat w lewo (oprócz Maria)
     * ruch odbywa się względem niego
     */
    void updateLevelPositionsWhileWalk();

    /**
     * Kontynuuje ruch wrogich postaci
     */
    void updateEnemiesPositions();

    /**
     * Ustawia parametry kolizji dla danego obiektu względem pozostałych elementów
     * @param movingItem modyfikowany obiekt
     */
    void generateCollisions (MovingItem& movingItem);

    /**
     * Wyzwala akcję zwoiązane z kolizjami Maria z wrogami.
     * Zabija wrogów lub Mario.
     * @param mario Mario
     */
    void generateCollisionsWithEnemies (MovingItem& mario);

    /**
     * Metoda sprawdzająca, czy Mario powinien być podrzucony do góry.
     */
    bool shouldMarioJump () {return marioJumpOnTurtleFlag;}

    /**
     * Metoda czyszcząca bufor punktów z analizy w obecnej klatce.
     */
    void clearPointsToAdd() {pointsToAdd = 0;}

    /**
     * Metoda zwracająca punkty zdobyte w danej klatce.
     */
    int getPointsToAdd() {return pointsToAdd;}

private:
    std::vector<Brick> bricks;
    std::vector<Gumba> gumbas;
    std::vector<Turtle> turtles;
    std::vector<Item> groundTiles;
    std::vector<Item> lowerTiles; //unused in collisions


    int pointsToAdd = 0;

    bool marioJumpOnTurtleFlag = false;

    /**
     * Metoda sprawdza kolizję z nieruchomymi elementami gry.
     * @param rectangle prostokąt, który jest sprawdzany
     * @return czy jest kolizja
     */


    bool checkStillCollisons (const sf::FloatRect& rectangle, bool canActWithHead = false);

    /**
     * Sprawdza kolizję z wrogami.
     * Jeżeli @param killing == true, to Mario zabija wroga.
     * Należy ustawić ten parametr, jeśli sprawdzana jest kolizja dolnej krawędzi gracza,
     * wrogów zabija się poprzes wskoczenie na nich od góry.
     * @param rectangle badany prostokąt
     * @return czy wystąpiła kolizja
     */
    bool chceckEnemiesCollisions (const sf::FloatRect& rectangle, bool killing = false);

    /**
     * Tworzy testowy poziom.
     */
    const void createTestLevel ();

    /**
     * Sprawdza kolizję pomiędzy wrogami.
     */
    void checkCollisionsBetweenEnemies (Enemy& enemy);

    /**
     * Przetwarza ewentualne podrzucenia cegieł.
     */
    void processBrickJumps();

    /**
     * Dodaje punkty o wartości jednej monety.
     */
    void addCoinPoints() {pointsToAdd += COIN;}

    /**
     * Dodaje punkty o wartości zabicia.
     */
    void addKillingPoints() {pointsToAdd += GUMBA;}
};



#endif //SUPER_MARIO_LEVEL_H
