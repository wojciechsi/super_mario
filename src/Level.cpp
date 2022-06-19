#include "headers/Level.h"

void Level::createTestLevel() {
    for (int i = 0; i < 500; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, TexturesStorage::getInstance()->getSoilTexture()));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, TexturesStorage::getInstance()->getSoilTexture()));
    }
   /* for(int i =2; i<16; i++)
    {
        groundTiles.emplace_back(Item( 16, SCREEN_HEIGHT - i *16, TexturesStorage::getInstance()->getSoilTexture()));
    }*/
   // groundTiles.emplace_back(Item( * 16, SCREEN_HEIGHT - 32, TexturesStorage::getInstance()->getSoilTexture()));

    groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInstance()->getSoilTexture()));
    groundTiles.emplace_back(Item(20 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInstance()->getSoilTexture()));

    groundTiles.emplace_back(Item(30 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInstance()->getSoilTexture()));
    groundTiles.emplace_back(Item(30 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInstance()->getSoilTexture()));

    gumbas.emplace_back(Gumba (22*16,SCREEN_HEIGHT - 50));
    gumbas.emplace_back(Gumba (580,60));

    turtles.emplace_back(Turtle (23*16,SCREEN_HEIGHT - 50));

    bricks.emplace_back(Brick(40 * 16, SCREEN_HEIGHT - 40));
    bricks.emplace_back(Brick(40 * 16, SCREEN_HEIGHT - 56));
    bricks.emplace_back(Brick(18 * 16, SCREEN_HEIGHT - 72));
    bricks.emplace_back(Brick(17 * 16, SCREEN_HEIGHT - 72));

    groundTiles.emplace_back(50 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInstance()->getKominLeft());
    groundTiles.emplace_back(51 * 16, SCREEN_HEIGHT - 40, TexturesStorage::getInstance()->getKominRight());
    groundTiles.emplace_back(50 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInstance()->getKominLeftTop());
    groundTiles.emplace_back(51 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInstance()->getKominRightTop());

    groundTiles.emplace_back(60*16, SCREEN_HEIGHT - 40, TexturesStorage::getInstance() ->getKominLeft());
    groundTiles.emplace_back(61*16, SCREEN_HEIGHT -40, TexturesStorage::getInstance()->getKominRight());
    groundTiles.emplace_back(60 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInstance()->getKominLeft());
    groundTiles.emplace_back(61 * 16, SCREEN_HEIGHT - 56, TexturesStorage::getInstance()->getKominRight());
    groundTiles.emplace_back(60 * 16, SCREEN_HEIGHT - 72, TexturesStorage::getInstance()->getKominLeftTop());
    groundTiles.emplace_back(61 * 16, SCREEN_HEIGHT - 72, TexturesStorage::getInstance()->getKominRightTop());

}

void Level::createFirstLevel()
{
    for (int i = 0; i < 70; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, TexturesStorage::getInstance()->getSoilTexture()));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, TexturesStorage::getInstance()->getSoilTexture()));
    }

    for (int i = 72; i < 87; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, TexturesStorage::getInstance()->getSoilTexture()));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, TexturesStorage::getInstance()->getSoilTexture()));
    }

    for (int i = 91; i < 155; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, TexturesStorage::getInstance()->getSoilTexture()));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, TexturesStorage::getInstance()->getSoilTexture()));
    }

    for (int i = 157; i < 200; i++) {
        groundTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 24, TexturesStorage::getInstance()->getSoilTexture()));
        lowerTiles.emplace_back(Item(i * 16, SCREEN_HEIGHT - 8, TexturesStorage::getInstance()->getSoilTexture()));
    }

    bricks.emplace_back(Brick(21 * 16, SCREEN_HEIGHT - 71));
    bricks.emplace_back(Brick(23 * 16, SCREEN_HEIGHT - 71));
    bricks.emplace_back(Brick(25 * 16, SCREEN_HEIGHT - 71));
}

Level::Level() {
    TexturesStorage::getInstance()->loadTexturesToStorage();
    if(ReadingSystem::getInstance()->ifUserInput() & ReadingSystem::getInstance()->ifFirstInput())
    {
        ReadingSystem::getInstance()->levelReader();

       std::jthread t0([&](){ReadingSystem::getInstance()->findFilePath();}) ;
       std::jthread t1([&]{ReadingSystem::getInstance()->changeFirstInput();});

    }
    if(ReadingSystem::getInstance()->ifFirstRun())
    {
        ReadingSystem::getInstance()->levelReader();
        std::jthread t0([&](){ReadingSystem::getInstance()->findFilePath();}) ;
        std::jthread t1([&]{ReadingSystem::getInstance()->changeFirstRun();});

    }
    std::string filePath = ReadingSystem::getInstance()->getFilePath();
    createLevelFromFile(filePath);
   // LevelReader();
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
        if(turtle.isAlive())
            turtle.draw(iwindow);
    }
    for (auto &gumba : gumbas) {
        if(gumba.isAlive())
            gumba.draw(iwindow);
    }
    for(auto &brick : bricks) {
        brick.draw(iwindow);
    }
    //@todo others in future
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
    for (auto &brick : bricks) {
        brick.moveOneStepLeft();
    }
    //@todo others in future
}

void Level::updateEnemiesPositions() {
     for (auto & gumba : gumbas) {
         if (gumba.isOnScreen()) {
             generateCollisions(gumba);
             checkCollisionsBetweenEnemies(gumba);
             gumba.update();
         }
     }
     for (auto &turtle: turtles)
         if (turtle.isOnScreen()) {
             generateCollisions(turtle);
             checkCollisionsBetweenEnemies(turtle);
             turtle.update();
         }
    processBrickJumps();
}

void Level::generateCollisions(MovingItem& movingItem, bool headFlag) {
    Collisons newCollisions;
    Bonduaries b = movingItem.getBonduariesBoxes();

    std::thread leftThread([&](){
        if(checkStillCollisons(b.leftBonduary)) newCollisions.left = true;
    });
    std::thread rightThread([&](){
        if(checkStillCollisons(b.rightBonduary)) newCollisions.right = true;
    });
    std::thread topThread ([&](){
        if(checkStillCollisons(b.topBonduary, headFlag)) newCollisions.up = true;
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

bool Level::checkStillCollisons(const sf::FloatRect& rectangle, bool canActWithHead) {
    for (auto& item : groundTiles) {
        if(item.isAround(rectangle.left))
            if (item.getSprite().getGlobalBounds().intersects(rectangle))
                return true;
    }
    for (auto& item : bricks) {
        if(item.isAround(rectangle.left))
            if (item.getSprite().getGlobalBounds().intersects(rectangle)) {
                if(canActWithHead) {
                    if (item.ifHasCoin()) addCoinPoints();
                    item.kickUp();
                }
                return true;
            }
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
                    addKillingPoints();
                }
                return true;
            }
        }
    }
    for(auto it=turtles.begin(); it!= turtles.end(); it++) {
        if ((*it).isOnScreen()){
            if ((*it).getSprite().getGlobalBounds().intersects(rectangle)) {
                if(killing) {
                    if((*it).isRunning()) {
                        addKillingPoints();
                        turtles.erase(it);
                    }
                    else {
                        marioJumpOnTurtleFlag = true;
                        (*it).die();
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
    if (marioJumpOnTurtleFlag) return;
    if (chceckEnemiesCollisions(b.leftBonduary) or chceckEnemiesCollisions(b.rightBonduary))
        mario.die();
}

void Level::checkCollisionsBetweenEnemies(Enemy& enemy) {
    Bonduaries b = enemy.getBonduariesBoxes();
    bool newLeft = false, newRight = false;
    bool enemyIsGumba = true;
    if (typeid(enemy) == typeid(Turtle))
        enemyIsGumba = false; //ASSUMING ELSE: is a Turtle
        for (auto & gumba : gumbas) {
            if (gumba.isNearbyX(enemy)) {
                if (!enemyIsGumba or gumba != enemy) {
                    if (gumba.getSprite().getGlobalBounds().intersects(b.leftBonduary))
                        newLeft = true;
                    if (gumba.getSprite().getGlobalBounds().intersects(b.rightBonduary))
                        newRight = true;
                    if(!enemyIsGumba) //A TURTLE
                        if(newLeft or newRight) { //WHO COLLIDED WITH GUMBA
                            if(dynamic_cast<Turtle*>(&enemy)->isRunning()) { //AND IS RUNNING
                                gumba.die();
                                //gumbas.erase(it); //KILLS IT
                                addKillingPoints();
                                addKillingPoints();
                            }
                        }
                }
            }
        }
        for (auto& turtle: turtles) {
            if (turtle.isNearbyX(enemy)) {
                if (enemyIsGumba or turtle != enemy) {
                    if (turtle.getSprite().getGlobalBounds().intersects(b.leftBonduary))
                        newLeft = true;
                    if (turtle.getSprite().getGlobalBounds().intersects(b.rightBonduary))
                        newRight = true;
                }
            }
        }

    enemy.setLeftAndRightCollisons(newLeft, newRight);
}

void Level::processBrickJumps() {
    for (auto &brick : bricks) {
        brick.jumpProcess();
    }
}

void Level::createLevelFromFile(std::string& path) {
std::fstream file;
std::vector<std::string> lineVector;
std::string line;
file.open(path);
if(!file.is_open())
{
    std::cerr<<"Open file failure\n";
    return;
}
else {
    while (std::getline(file, line)) {
        lineVector.push_back(line);
    }
    file.close();

    for (int i = 0; i < lineVector.size(); i++) {
        for (int j = 0; j < lineVector[i].size(); j++) {
            if (lineVector[i][j] == 'p') {
                groundTiles.emplace_back(
                        Item(j * TILE, i * TILE, TexturesStorage::getInstance()->getSoilTexture()));
            } else if (lineVector[i][j] == 'b') {
                bricks.emplace_back(Brick(j * TILE, i * TILE));
            } else if (lineVector[i][j] == '1') {
                groundTiles.emplace_back(j * TILE, i * TILE, TexturesStorage::getInstance()->getKominLeft());
            } else if (lineVector[i][j] == '2') {
                groundTiles.emplace_back(j * TILE, i * TILE, TexturesStorage::getInstance()->getKominRight());

            } else if (lineVector[i][j] == '3') {
                groundTiles.emplace_back(j * TILE, i * TILE, TexturesStorage::getInstance()->getKominLeftTop());
            } else if (lineVector[i][j] == '4') {
                groundTiles.emplace_back(j * TILE, i * TILE, TexturesStorage::getInstance()->getKominRightTop());
            } else if (lineVector[i][j] == 'g') {
                gumbas.emplace_back(Gumba(j * TILE, i * TILE - TILE / 2));
            } else if (lineVector[i][j] == 't') {
                turtles.emplace_back(Turtle(j * TILE, i * TILE - TILE / 2));
            }
        }

    }
}
}

void Level::clearLevel() {
    bricks.clear();
    gumbas.clear();
    turtles.clear();
    groundTiles.clear();
    lowerTiles.clear();
    pointsToAdd = 0;
    marioJumpOnTurtleFlag = false;
}



