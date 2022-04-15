#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
#include "defs.h"
/**
 * Klasa zawiera aktualny poziom gry
 */
class Level {
public:
    Level();

    void printLevelContent (sf::RenderWindow &iwindow);
    void updateLevelPositionsWhileWalk();
private:
    std::vector<Gumba> gumbas;
    std::vector<Turtle> turtles;
    Item groundTiles [1000];


};


#endif //SUPER_MARIO_LEVEL_H
