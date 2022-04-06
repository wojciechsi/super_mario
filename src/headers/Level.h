#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
/**
 * Klasa zawiera aktualny poziom gry
 */
class Level {
public:
    Level();
private:
    std::vector<Gumba> gumbas;
    std::vector<Turtle> turtles;
    std::vector<Object> groundTiles;

};


#endif //SUPER_MARIO_LEVEL_H
