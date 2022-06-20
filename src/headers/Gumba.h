#ifndef SUPER_MARIO_GUMBA_H
#define SUPER_MARIO_GUMBA_H

#include "Enemy.h"
#include "TexturesStorage.h"

/**
 * Klasa reprezentuje przeciwnika "Gumba"
 */
class Gumba : public Enemy{
public:
    Gumba(const Gumba&) = default;
    Gumba ();
    Gumba (int iX, int iY);

    /**
     * Implementacja interfejsu Enemy "pro forma"
     */
    void foo() override {}
};




#endif //SUPER_MARIO_GUMBA_H
