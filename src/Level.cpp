#include "headers/Level.h"

const void Level::createTestLevel() {
    for (int i = 0; i < 500; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, texturesStorage.soilTexture));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, texturesStorage.soilTexture));

    }
    groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 40, texturesStorage.soilTexture));
    groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 56, texturesStorage.soilTexture));

    groundTiles.emplace_back(Item(25 * 16, SCREEN_HEIGHT - 40, texturesStorage.soilTexture));
    groundTiles.emplace_back(Item(25 * 16, SCREEN_HEIGHT - 56, texturesStorage.soilTexture));
    groundTiles.emplace_back(Item(18 * 16, SCREEN_HEIGHT - 72, texturesStorage.soilTexture));

    gumbas.emplace_back(Gumba (450,40));
    gumbas.emplace_back(Gumba (580,60));
    gumbas[0].setTexture(texturesStorage.gumbaTexture);
    gumbas[1].setTexture(texturesStorage.gumbaTexture);
}

Level::Level() {
    loadTexturesToStorage();
    createTestLevel();
    }

void Level::printLevelContent(sf::RenderWindow &iwindow) {
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
        tile.moveOneStepLeft();
    }
    for(auto &tile1 : lowerTiles)
    {
        tile1.moveOneStepLeft();
    }
    for (auto &turtle : turtles) {
        turtle.moveOneStepLeft();
    }
    for (auto &gumba : gumbas) {
        gumba.moveOneStepLeft();
    }
    //@todo others in future
}

void Level::updateEnemiesPositions() {
    std::jthread gumbaThread ([&]() {
        for (auto &gumba: gumbas)
            if (gumba.isOnScreen()) {
                generateCollisions(gumba);
                gumba.update();
            }

    });
    std::jthread turtleThread ([&](){
        for (auto &turtle: turtles)
            if (turtle.isOnScreen())
                turtle.update();
    });
}

void Level::generateCollisions(MovingItem& movingItem) {
    Collisons newCollisions;
    Bonduaries b = movingItem.getBonduariesBoxes();

    std::jthread leftThread([&](){
        if(checkStillCollisons(b.leftBonduary)) newCollisions.left = true;
    });
    std::jthread rightThread([&](){
        if(checkStillCollisons(b.rightBonduary)) newCollisions.right = true;
    });
    std::jthread topThread ([&](){
        if(checkStillCollisons(b.topBonduary)) newCollisions.up = true;
    });
    std::jthread bottomThread ([&](){
        if(checkStillCollisons(b.bottomBonduary)) newCollisions.down = true;
    });

    leftThread.join();
    rightThread.join();
    topThread.join();
    bottomThread.join();

    movingItem.setCollisions(newCollisions);
    }

bool Level::checkStillCollisons(const sf::FloatRect& rectangle) {
    for (auto& item : groundTiles) {
        if(item.isOnScreen())
            if (item.getSprite().getGlobalBounds().intersects(rectangle))
                return true;
    }
    return false;
}

bool Level::chceckEnemiesCollisions(const sf::FloatRect &rectangle, bool killing) {
    for(auto it=gumbas.begin(); it!= gumbas.end(); it++) {
        if ((*it).isOnScreen()){
            if ((*it).getSprite().getGlobalBounds().intersects(rectangle)) {
                if(killing) {
                    (*it).die();
                    gumbas.erase(it);
                }
                return true; //todo this a Item class method
            }

        }
    }
    for(auto& turtle : turtles) {

    }
    return false;
}

void Level::generateCollisionsWithEnemies(MovingItem &mario) {
    Bonduaries b = mario.getBonduariesBoxes();
    chceckEnemiesCollisions(b.bottomBonduary, true);
    if (chceckEnemiesCollisions(b.leftBonduary) or chceckEnemiesCollisions(b.rightBonduary))
        mario.die();
}

void Level::loadTexturesToStorage() {
    texturesStorage.gumbaTexture.get()->loadFromFile("../src/resources/gumba.png");
    texturesStorage.soilTexture->loadFromFile("../src/resources/soil.png");
}
