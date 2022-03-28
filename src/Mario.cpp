#include "headers/Mario.h"

Mario::Mario() : MovingItem(0.5f * SCREEN_WIDTH,
                            0.5f * SCREEN_HEIGHT) {
    setTexture("../src/resources/smallMario.png");
    MarioShape.setSize(sf::Vector2f(50.f, 50.f));
}

void Mario::MoveStatus()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
      MarioShape.move(sf::Vector2f(-0.5f, 0));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        MarioShape.move(sf::Vector2f(0.5f, 0));
    }
}
