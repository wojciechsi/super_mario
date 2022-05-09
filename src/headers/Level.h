#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
#include "defs.h"
#include "Mario.h"
#include <iostream>
/**
 * Klasa zawiera aktualny poziom gry
 */
class Level {
public:
    Level();

    void printLevelContent (sf::RenderWindow &iwindow);

    /**
     * Przemieszcza cały świat w lewo (oprócz Maria)
     */
    void updateLevelPositionsWhileWalk();

    bool isOnTopOfAny (Item);

    bool isSthAtPoint (float x, float y);

    void updateEnemiesPositions();

    /**
     * Ustawia parametry kolizji dla danego obiektu względem pozostałych elementów
     * @param movingItem modyfikowany obiekt
     */
    void generateCollisions (MovingItem& movingItem, sf::RenderWindow & iWindow);

private:
    std::vector<Gumba> gumbas;
    std::vector<Turtle> turtles;
    std::vector<Item> groundTiles;
    std::vector<Item> lowerTiles; //unused in collisions

    bool checkCollisons (const sf::FloatRect& rectangle);

};


#endif //SUPER_MARIO_LEVEL_H
