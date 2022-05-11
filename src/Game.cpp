#include <chrono>
#include "headers/Game.h"

void Game::run() {



    window.setSize(sf::Vector2u(SCREEN_WIDTH*2, SCREEN_HEIGHT*2)); //scale
    while(window.isOpen()) {
        //początek klatki
        auto frameStart = std::chrono::steady_clock::now();

        handleEvents();

        window.clear(sf::Color::Black);
        //mario.MoveStatus();
        updateWindow(window);
        window.display();

        //koniec klatki i ewentualne poczekanie
        auto frameStop = std::chrono::steady_clock::now();
        std::chrono::duration<double> frameDiff = frameStop - frameStart;
        //while ((frameStop-frameStart).count() < FRAME_TIME)
        while (frameDiff.count() < FRAME_TIME) {
            frameStop = std::chrono::steady_clock::now();
            frameDiff = frameStop - frameStart;
        }
    }
    window.close();
}

void Game::updateWindow(sf::RenderWindow & iWindow) {
    if (gameON) {
        level.printLevelContent(iWindow);
        level.generateCollisions(mario);
        //@todo gumba odwala jak wyjdzie za ekran
        mario.update();
        mario.draw(iWindow);
        level.updateEnemiesPositions();
        if(mario.isAlive()) {
            level.generateCollisionsWithEnemies(mario);
               if (mario.isGoesRight())
                   if (!mario.hasRightCollision())
                        level.updateLevelPositionsWhileWalk();
        }
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
