#include "headers/Mario.h"

Mario::Mario() : MovingItem(0.5f * SCREEN_WIDTH,
                            0.5f * SCREEN_HEIGHT) {
    setTexture("../src/resources/smallMario.png");
}

void Mario::MoveStatus()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        //nie wypuść ne lewo od ekranu
        if(this->sprite.getPosition().x < (this->size.x)/2) return;
        else this-> move(-1.0f, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        this-> move(1.0f, 0);
    }
}
