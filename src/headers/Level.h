#ifndef SUPER_MARIO_LEVEL_H
#define SUPER_MARIO_LEVEL_H

#include <vector>
#include "Gumba.h"
#include "Turtle.h"
#include "defs.h"
#include "Mario.h"
#include <iostream>
#include <thread>
#include <ranges>

struct TexturesStorage {
    std::shared_ptr<sf::Texture> soilTexture = std::make_shared<sf::Texture>();
    std::shared_ptr<sf::Texture> gumbaTexture = std::make_shared<sf::Texture>();
};

/**
 * Klasa zawiera aktualny poziom gry
 */
class Level {
public:
    Level();

    /**
     * Renderuje elementy poziomu na ekranie
     * @param iwindow okno
     */
    void printLevelContent (sf::RenderWindow &iwindow);

    /**
     * Przemieszcza cały świat w lewo (oprócz Maria)
     * ruch odbywa się względem niego
     */
    void updateLevelPositionsWhileWalk();

    /**
     * Kontynuuje ruch wrogich postaci
     */
    void updateEnemiesPositions();

    /**
     * Ustawia parametry kolizji dla danego obiektu względem pozostałych elementów
     * @param movingItem modyfikowany obiekt
     */
    void generateCollisions (MovingItem& movingItem);

    /**
     * Wyzwala akcję zwoiązane z kolizjami Maria z wrogami.
     * Zabija wrogów lub Mario.
     * @param mario Mario
     */
    void generateCollisionsWithEnemies (MovingItem& mario);

private:
    std::vector<Gumba> gumbas;
    std::vector<Turtle> turtles;
    std::vector<Item> groundTiles;
    std::vector<Item> lowerTiles; //unused in collisions

    TexturesStorage texturesStorage;

    bool checkStillCollisons (const sf::FloatRect& rectangle);

    bool chceckEnemiesCollisions (const sf::FloatRect& rectangle, bool killing = false);

    const void createTestLevel ();

    void loadTexturesToStorage ();
};


#endif //SUPER_MARIO_LEVEL_H
