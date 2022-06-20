#ifndef SUPER_MARIO_TEXTURESSTORAGE_H
#define SUPER_MARIO_TEXTURESSTORAGE_H

#include <memory>
#include <SFML/Graphics.hpp>

class TexturesStorage {
private:
    std::shared_ptr<sf::Texture> marioTexture = std::make_shared<sf::Texture>();
public:
    const std::shared_ptr<sf::Texture> &getMarioTexture() const;

private:
    std::shared_ptr<sf::Texture> soilTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> gumbaTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> turtleWalkingTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> turtleRunningTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> brickTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> backgroundTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> emptyBrickTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> boxTexture = std::make_shared<sf::Texture>();

    std::shared_ptr<sf::Texture> kominLeft = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> kominLeftTop = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> kominRight = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> kominRightTop = std::make_shared<sf::Texture>();

    std::shared_ptr<sf::Texture> patykTop = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> patyk = std::make_shared<sf::Texture>();

    std::shared_ptr<sf::Texture> krzakLeft = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> krzak = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> krzakRight = std::make_shared<sf::Texture>();

    std::shared_ptr<sf::Texture> chmuraTopLeft = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> chmuraTop = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> chmuraTopRight = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> chmuraBottomLeft = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> chmuraBottom = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> chmuraBottomRight = std::make_shared<sf::Texture>();


    std::shared_ptr<sf::Shader> blurShader = std::make_shared<sf::Shader>();

    std::shared_ptr<sf::Texture> heartTexture = std::make_shared<sf::Texture>();
public:
    const std::shared_ptr<sf::Texture> &getHeartTexture() const;

public:
    const std::shared_ptr<sf::Texture> &getKominLeft() const;

    const std::shared_ptr<sf::Texture> &getKominLeftTop() const;

    const std::shared_ptr<sf::Texture> &getKominRight() const;

    const std::shared_ptr<sf::Texture> &getKominRightTop() const;

    const std::shared_ptr<sf::Texture> &getEmptyBrickTexture() const;

public:
    const std::shared_ptr<sf::Texture> &getBackgroundTexture() const;

private:

    static std::mutex mutex;
    static std::shared_ptr<TexturesStorage> instance;
public:
    TexturesStorage() {};

    ~TexturesStorage() {};

    /**
    * Wczytuje tekstury z dysku
    */
    void loadTexturesToStorage();

    const std::shared_ptr<sf::Texture> &getBrickTexture() const;

    TexturesStorage(TexturesStorage& other) = delete;

    void operator=(const TexturesStorage&) = delete;

    static std::shared_ptr<TexturesStorage> getInstance();

    const std::shared_ptr<sf::Texture> &getSoilTexture() const;

    const std::shared_ptr<sf::Texture> &getGumbaTexture() const;

    const std::shared_ptr<sf::Texture> &getTurtleWalkingTexture() const;

    const std::shared_ptr<sf::Texture> &getTurtleRunningTexture() const;

    const std::shared_ptr<sf::Texture> &getPatykTop() const;

    const std::shared_ptr<sf::Texture> &getPatyk() const;

    const std::shared_ptr<sf::Texture> &getKrzakLeft() const;

    const std::shared_ptr<sf::Texture> &getKrzak() const;

    const std::shared_ptr<sf::Texture> &getKrzakRight() const;

    const std::shared_ptr<sf::Texture> &getChmuraTopLeft() const;

    const std::shared_ptr<sf::Texture> &getChmuraTop() const;

    const std::shared_ptr<sf::Texture> &getChmuraTopRight() const;

    const std::shared_ptr<sf::Texture> &getChmuraBottomLeft() const;

    const std::shared_ptr<sf::Texture> &getChmuraBottom() const;

    const std::shared_ptr<sf::Texture> &getChmuraBottomRight() const;
};


#endif //SUPER_MARIO_TEXTURESSTORAGE_H
