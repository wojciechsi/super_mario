#include "headers/TexturesStorage.h"

std::shared_ptr<TexturesStorage> TexturesStorage::instance = 0;
std::mutex TexturesStorage::mutex;

void TexturesStorage::loadTexturesToStorage() {
        marioTexture->loadFromFile("../src/resources/smallMario.png");
        gumbaTexture->loadFromFile("../src/resources/gumba.png");
        soilTexture->loadFromFile("../src/resources/soil.png");
        turtleWalkingTexture->loadFromFile("../src/resources/turtleWalking.png");
        turtleRunningTexture->loadFromFile("../src/resources/turtleRunning.png");
        brickTexture->loadFromFile("../src/resources/brick.png");
        backgroundTexture->loadFromFile("../src/resources/background.png");
        kominLeft->loadFromFile("../src/resources/kominLeft.png");
        kominLeftTop->loadFromFile("../src/resources/kominLeftTop.png");
        kominRight->loadFromFile("../src/resources/kominRight.png");
        kominRightTop->loadFromFile("../src/resources/kominRightTop.png");
        heartTexture->loadFromFile("../src/resources/heart.png");
        emptyBrickTexture->loadFromFile("../src/resources/emptyBrick.png");
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getSoilTexture() const {
    return soilTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getGumbaTexture() const {
    return gumbaTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getTurtleWalkingTexture() const {
    return turtleWalkingTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getTurtleRunningTexture() const {
    return turtleRunningTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getBrickTexture() const {
    return brickTexture;
}

std::shared_ptr<TexturesStorage> TexturesStorage::getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == 0) {
        instance = std::make_shared<TexturesStorage>();
    }
    return instance;

}

const std::shared_ptr<sf::Texture> &TexturesStorage::getBackgroundTexture() const {
    return backgroundTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getMarioTexture() const {
    return marioTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKominLeft() const {
    return kominLeft;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKominLeftTop() const {
    return kominLeftTop;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKominRight() const {
    return kominRight;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKominRightTop() const {
    return kominRightTop;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getHeartTexture() const {
    return heartTexture;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getEmptyBrickTexture() const {
    return emptyBrickTexture;
}


