#ifndef SUPER_MARIO_GUMBA_H
#define SUPER_MARIO_GUMBA_H

#include "Enemy.h"

/**
 * Klasa reprezentuje przeciwnika "Gumba"
 */
class Gumba : public Enemy{
public:
    Gumba(const Gumba&) = default;
    Gumba ();
    Gumba (int iX, int iY);
};


#endif //SUPER_MARIO_GUMBA_H
