#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
#include "defs.h"
#include "Mario.h"
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

private:
    Gumba gumbas [100];
    std::vector<Turtle> turtles;
    Item groundTiles[MAX_LEVEL_SIZE];
    Item lowerTiles[MAX_LEVEL_SIZE];



};


#endif //SUPER_MARIO_LEVEL_H
