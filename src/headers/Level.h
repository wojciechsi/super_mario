#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
#include "defs.h"
#include "Mario.h"
#include <memory>
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
    std::vector<Gumba> gumbas;
    std::vector<Turtle> turtles;
    std::vector<Item> groundTiles;
    std::vector<Item> lowerTiles;



};


#endif //SUPER_MARIO_LEVEL_H
