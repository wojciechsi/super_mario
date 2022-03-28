#include "headers/Mario.h"

Mario::Mario() : MovingItem(0.5f * SCREEN_WIDTH,
                            0.5f * SCREEN_HEIGHT) {
    setTexture("../src/resources/smallMario.png");
}

void Mario::MoveStatus()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        shape.move(sf::Vector2f(-0.5f, 0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        shape.move(sf::Vector2f(0.5f, 0));
    }
}
