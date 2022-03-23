#ifndef SUPER_MARIO_ENGINE_H
#define SUPER_MARIO_ENGINE_H

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Mario.h"

/**
 * Klasa zapewnia logikę działania gry
 */
class Engine {
public:
    Engine() = default;
    void updateWindow (sf::RenderWindow&);
private:
    Mario mario;
};


#endif //SUPER_MARIO_ENGINE_H
