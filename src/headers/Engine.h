//
// Created by wojciech on 21.03.2022.
//

#ifndef SUPER_MARIO_ENGINE_H
#define SUPER_MARIO_ENGINE_H

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Mario.h"


class Engine {
public:
    Engine() = default;
    void updateWindow (sf::RenderWindow&);
private:
    Mario mario;
};


#endif //SUPER_MARIO_ENGINE_H
