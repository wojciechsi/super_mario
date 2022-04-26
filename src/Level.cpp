//
// Created by wojciech on 21.03.2022.
//

#include "headers/Level.h"


Level::Level() {

    sf::Texture gumbaTexture;
    gumbaTexture.loadFromFile("../src/resources/gumba.png");
    sf::Texture soilTexture;
    soilTexture.loadFromFile("../src/resources/soil.png");


        for (int i = 0; i < 500; i++) {
            groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, soilTexture));
            lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8 , soilTexture));

        }
        //below for tests
        groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 40, soilTexture));
        groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 56, soilTexture));

        gumbas.emplace_back(Gumba (450,40));
        gumbas.emplace_back(Gumba (580,60));
        gumbas[0].setTexture(gumbaTexture);
    gumbas[1].setTexture(gumbaTexture);
    for(auto & tile : groundTiles)
        tile.setTexture(soilTexture);
    for(auto & tile : lowerTiles)
        tile.setTexture(soilTexture);


    }


void Level::printLevelContent(sf::RenderWindow &iwindow) {
    //std::for_each(groundTiles.begin(), groundTiles.end(),
    //              [&](Item &i){i.draw(iwindow);});
    for (auto &tile : groundTiles) {
        tile.draw(iwindow);
    }
    for(auto &tile1 : lowerTiles)
    {
        tile1.draw(iwindow);
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
    for(auto &tile1 : lowerTiles)
    {
        tile1.walkMove();
    }
    for (auto &turtle : turtles) {
        turtle.walkMove();
    }
    for (auto &gumba : gumbas) {
        gumba.walkMove();
    }
}

bool Level::isOnTopOfAny(Item mario) {
    for (auto &tile : groundTiles) {
        if (tile.isOnScreen()) {
            if (mario.upDownTouch(tile)){
                return true;
            }
        }
    }
    for (auto &turtle : turtles) {

    }
    for (auto &gumba : gumbas) {

    }
    return false;
}

bool Level::isSthAtPoint(float x, float y) {
    for (auto &tile : groundTiles) {
        if (tile.isOnScreen()) {
            if (tile.getSprite().getGlobalBounds().contains(x, y))
                return true;
        }
    }
    return false;
}

void Level::updateEnemiesPositions() {
    for (auto &gumba : gumbas)
        if (gumba.isOnScreen()) {
            gumba.setOnTopOfAny(false);
            if(isOnTopOfAny(gumba))
                gumba.setOnTopOfAny(true);
            gumba.update(); }
    for (auto &turtle : turtles)
        if (turtle.isOnScreen())
            turtle.update();
}