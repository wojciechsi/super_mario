#include "headers/TexturesStorage.h"
#include <iostream>
//std::shared_ptr<TexturesStorage> TexturesStorage::instance = std::make_shared<TexturesStorage>();
std::shared_ptr<TexturesStorage> TexturesStorage::instance = 0;
std::mutex TexturesStorage::mutex;


void TexturesStorage::loadTexturesToStorage() {
        gumbaTexture->loadFromFile("../src/resources/gumba.png");
        soilTexture->loadFromFile("../src/resources/soil.png");
        turtleWalkingTexture->loadFromFile("../src/resources/turtleWalking.png");
        turtleRunningTexture->loadFromFile("../src/resources/turtleRunning.png");
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

std::shared_ptr<TexturesStorage> TexturesStorage::getInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == 0) {
        instance = std::make_shared<TexturesStorage>();
    }
    return instance;

}
