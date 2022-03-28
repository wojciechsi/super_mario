#include <iostream>
#include "headers/Mario.h"

Mario::Mario() : MovingItem( SCREEN_WIDTH,
                             SCREEN_HEIGHT) {
    setTexture("../src/resources/smallMario.png");
}

void Mario::MoveStatus()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        std::cout << "L";
        this->move(-0.5, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        std::cout << "R";
        this->move(0.5, 0);
    }
}
