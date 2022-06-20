#include "headers/TexturesStorage.h"

std::shared_ptr<TexturesStorage> TexturesStorage::instance = nullptr;
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
        patyk->loadFromFile("../src/resources/patyk.png");
        patykTop->loadFromFile("../src/resources/patykTop.png");
        boxTexture->loadFromFile("../src/resources/box.png");
        krzakLeft->loadFromFile("../src/resources/krzakLeft.png");
        krzak->loadFromFile("../src/resources/krzak.png");
        krzakRight->loadFromFile("../src/resources/krzakRight.png");
        chmuraTopLeft->loadFromFile("../src/resources/chmuraTopLeft.png");
        chmuraTop->loadFromFile("../src/resources/chmuraTop.png");
        chmuraTopRight->loadFromFile("../src/resources/chmuraTopRight.png");
        chmuraBottomLeft->loadFromFile("../src/resources/chmuraBottomLeft.png");
        chmuraBottom->loadFromFile("../src/resources/chmuraBottom.png");
        chmuraBottomRight->loadFromFile("../src/resources/chmuraBottomRight.png");
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
    if (instance == nullptr) {
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

const std::shared_ptr<sf::Texture> &TexturesStorage::getPatyk() const {
    return patyk;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getPatykTop() const {
    return patykTop;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKrzakLeft() const {
    return krzakLeft;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKrzak() const {
    return krzak;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getKrzakRight() const {
    return krzakRight;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getChmuraTopLeft() const {
    return chmuraTopLeft;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getChmuraTop() const {
    return chmuraTop;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getChmuraTopRight() const {
    return chmuraTopRight;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getChmuraBottomLeft() const {
    return chmuraBottomLeft;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getChmuraBottom() const {
    return chmuraBottom;
}

const std::shared_ptr<sf::Texture> &TexturesStorage::getChmuraBottomRight() const {
    return chmuraBottomRight;
}


