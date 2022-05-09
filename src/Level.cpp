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
    std::for_each(groundTiles.begin(), groundTiles.end(),
                  [&](Item &i){i.draw(iwindow);});
    //buhahahaha
    //for (auto &tile : groundTiles) {
    //    tile.draw(iwindow);
    //}
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
    //@todo others in future
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
    /*
    for (auto &gumba : gumbas) {
        if(gumba.isOnScreen())
            if(mario.upDownTouch(gumba)) return true;
    }
     */
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
            gumba.setDownCollision(false);
            //if(isOnTopOfAny(gumba))
            //    gumba.setDownCollision(true); // version 0
            generateCollisions(gumba); //version 1
            //@todo gumba nie wychodzi za ekran
            gumba.update(); }
    for (auto &turtle : turtles)
        if (turtle.isOnScreen())
            turtle.update();
}

void Level::generateCollisions(MovingItem& movingItem) {
    Collisons newCollisions;

    sf::FloatRect rectangle = movingItem.getSprite().getGlobalBounds();

    const sf::FloatRect leftBonduary(rectangle.left, rectangle.top,
                                     ITEM_COLL_WIDTH, rectangle.height);
    const sf::FloatRect rightBonduary(rectangle.left + rectangle.width, rectangle.top,
                                      -ITEM_COLL_WIDTH, rectangle.height);
    const sf::FloatRect topBonduary(rectangle.left + ITEM_COLL_OFFSET, rectangle.top,
                                    rectangle.width -2*ITEM_COLL_OFFSET,  ITEM_COLL_WIDTH);
    const sf::FloatRect bottomBonduary(rectangle.left + ITEM_COLL_OFFSET, rectangle.top + rectangle.height,
                                       rectangle.width - 2*ITEM_COLL_OFFSET, ITEM_COLL_WIDTH);

    if(checkCollisons(leftBonduary)) newCollisions.left = true;
    if(checkCollisons(rightBonduary)) newCollisions.right = true;
    if(checkCollisons(topBonduary)) newCollisions.up = true;
    if(checkCollisons(bottomBonduary)) newCollisions.down = true;


    movingItem.setCollisions(newCollisions);
    }

bool Level::checkCollisons(const sf::FloatRect& rectangle) {
    for (auto& item : groundTiles) {
        if(item.isOnScreen())
            if (item.getSprite().getGlobalBounds().intersects(rectangle))
                return true;
    }
    return false;
}

