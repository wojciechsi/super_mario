#ifndef SUPER_MARIO_TURTLE_H
#define SUPER_MARIO_TURTLE_H

#include "Enemy.h"
#include "TexturesStorage.h"

enum class TurtleMode {walking, running};

/**
 * Klasa przechowuje informacje o żółwiu
 */
class Turtle : public Enemy{
private:
    TurtleMode turtlemode = TurtleMode::walking;

public:
    Turtle();
    Turtle(int x, int y);
    void die();
    bool isRunning ();
    void foo() {}
};


#endif //SUPER_MARIO_TURTLE_H
