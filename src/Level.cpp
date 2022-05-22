#include "headers/Level.h"

const void Level::createTestLevel() {
    for (int i = 0; i < 500; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, TexturesStorage::getInsatnce()->getSoilTexture()));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, TexturesStorage::getInsatnce()->getSoilTexture()));
    }

    groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInsatnce()->getSoilTexture()));
    groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInsatnce()->getSoilTexture()));

    groundTiles.emplace_back(Item(40 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInsatnce()->getSoilTexture()));
    groundTiles.emplace_back(Item(40 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInsatnce()->getSoilTexture()));

    //groundTiles.emplace_back(Item(25 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInsatnce()->getSoilTexture()));
    //groundTiles.emplace_back(Item(25 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInsatnce()->getSoilTexture()));

    groundTiles.emplace_back(Item(30 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInsatnce()->getSoilTexture()));
    groundTiles.emplace_back(Item(30 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInsatnce()->getSoilTexture()));

    groundTiles.emplace_back(Item(18 * 16, SCREEN_HEIGHT - 72, TexturesStorage::getInsatnce()->getSoilTexture()));

    //gumbas.emplace_back(Gumba (22*16,SCREEN_HEIGHT - 50));
    gumbas.emplace_back(Gumba (580,60));
    gumbas[0].setTexture(TexturesStorage::getInsatnce()->getGumbaTexture());
    //gumbas[1].setTexture(texturesStorage.gumbaTexture);
    turtles.emplace_back(Turtle (23*16,SCREEN_HEIGHT - 50));
    turtles[0].setTexture(TexturesStorage::getInsatnce()->getTurtleWalkingTexture());

}

Level::Level() {
    TexturesStorage::getInsatnce()->loadTexturesToStorage();
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
                checkCollisionsBetweenEnemies(gumba);
                gumba.update();
            }

    });
    std::jthread turtleThread ([&](){
        for (auto &turtle: turtles)
            if (turtle.isOnScreen()) {
                generateCollisions(turtle);
                checkCollisionsBetweenEnemies(turtle);
                turtle.update();
            }
    });
}

void Level::generateCollisions(MovingItem& movingItem) {
    Collisons newCollisions;
    Bonduaries b = movingItem.getBonduariesBoxes();

    std::thread leftThread([&](){
        if(checkStillCollisons(b.leftBonduary)) newCollisions.left = true;
    });
    std::thread rightThread([&](){
        if(checkStillCollisons(b.rightBonduary)) newCollisions.right = true;
    });
    std::thread topThread ([&](){
        if(checkStillCollisons(b.topBonduary)) newCollisions.up = true;
    });
    std::thread bottomThread ([&](){
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
    marioJumpOnTurtleFlag = false;
    for(auto it=gumbas.begin(); it!= gumbas.end(); it++) {
        if ((*it).isOnScreen()){
            if ((*it).getSprite().getGlobalBounds().intersects(rectangle)) {
                if(killing) {
                    (*it).die();
                    gumbas.erase(it);
                }
                return true; //todo this a TURTLE and GUMBA method
            }

        }
    }
    for(auto it=turtles.begin(); it!= turtles.end(); it++) {
        if ((*it).isOnScreen()){
            if ((*it).getSprite().getGlobalBounds().intersects(rectangle)) {
                if(killing) {
                    (*it).die();
                    if((*it).isRunning())
                        turtles.erase(it);
                    else {
                        marioJumpOnTurtleFlag = true;
                        return false;
                    }
                }
                return true;
            }

        }
    }
    return false;
}

void Level::generateCollisionsWithEnemies(MovingItem &mario) {
    Bonduaries b = mario.getBonduariesBoxes();
    chceckEnemiesCollisions(b.bottomBonduary, true);
    if (marioJumpOnTurtleFlag == true) return;
    if (chceckEnemiesCollisions(b.leftBonduary) or chceckEnemiesCollisions(b.rightBonduary))
        mario.die();
}

void Level::checkCollisionsBetweenEnemies(Enemy& enemy) {
    Bonduaries b = enemy.getBonduariesBoxes();
    bool newLeft = false, newRight = false;
    bool enemyIsGumba = true; //ASSUMING ELSE: is a Turtle
    if (typeid(enemy) == typeid(Turtle))
        enemyIsGumba = false;
    std::thread gumbasThread ([&](){
        for (auto& gumba: gumbas) {
            if (gumba.isOnScreen()) {
                if (!enemyIsGumba or gumba != enemy) {
                    if (gumba.getSprite().getGlobalBounds().intersects(b.leftBonduary))
                        newLeft = true;
                    if (gumba.getSprite().getGlobalBounds().intersects(b.rightBonduary))
                        newRight = true;
                }
            }
        }
    });
    std::thread turtlesThread ([&](){
        for (auto& turtle: turtles) {
            if (turtle.isOnScreen()) {
                if (enemyIsGumba or turtle != enemy) {
                    if (turtle.getSprite().getGlobalBounds().intersects(b.leftBonduary))
                        newLeft = true;
                    if (turtle.getSprite().getGlobalBounds().intersects(b.rightBonduary))
                        newRight = true;
                }
            }
        }
    });

    gumbasThread.join();
    turtlesThread.join();

    enemy.setLeftAndRightCollisons(newLeft, newRight);
}
