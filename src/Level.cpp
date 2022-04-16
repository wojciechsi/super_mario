//
// Created by wojciech on 21.03.2022.
//

#include "headers/Level.h"


Level::Level() {
    for (int i = 0; i < 500; i++) {
        groundTiles[i] = (Item(i*16, SCREEN_HEIGHT/2 + 50));
        groundTiles[i].setTexture("../src/resources/soil.png");
    }
    groundTiles[500] = Item(16*40, SCREEN_HEIGHT/2 + 20);
    groundTiles[500].setTexture("../src/resources/soil.png");
    groundTiles[501] = Item(16*41, SCREEN_HEIGHT/2 + 20);
    groundTiles[501].setTexture("../src/resources/soil.png");
}

void Level::printLevelContent(sf::RenderWindow &iwindow) {
    //std::for_each(groundTiles.begin(), groundTiles.end(),
    //              [&](Item &i){i.draw(iwindow);});
    for (auto &tile : groundTiles) {
        tile.draw(iwindow);
    }
    for (auto &turtle : turtles) {
        turtle.draw(iwindow);
    }
    for (auto &gumba : gumbas) {
        gumba.draw(iwindow);
    }


}

void Level::updateLevelPositionsWhileWalk() {
    for (auto &tile : groundTiles) {
        tile.walkMove();
    }
    for (auto &turtle : turtles) {
        turtle.walkMove();
    }
    for (auto &gumba : gumbas) {
        gumba.walkMove();
    }
}

bool Level::isOnTopOfAny(Mario mario) {
    for (auto &tile : groundTiles) {
        if (tile.isOnScreen())
            if (mario.upDownTouch(tile)) return true;
    }
    for (auto &turtle : turtles) {

    }
    for (auto &gumba : gumbas) {

    }
    return false;
}
