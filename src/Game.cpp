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
        //if(level.isOnTopOfAny(mario)) mario.setDownCollision(true); //VERSION 0
        level.generateCollisions(mario);    //VERSION 1 with 2d collisions
        //@todo rozpędzony mario przechodzi przez ścianę
        //@todo gumba odwala jak wyjdzie za ekran
        mario.MoveStatus(); //this calls for moves from keyboard and much more...
        mario.update();
        //mario.setDownCollision(false); // part of VERSION 0
        mario.draw(iWindow);
        level.updateEnemiesPositions();
        level.generateCollisionsWithEnemies(mario);
        if(mario.isGoesRight())
            level.updateLevelPositionsWhileWalk();
        if(!mario.isAlive()) {
            gameON = false;
        }
        /**
         * @todo za dużo się tu dzieje
         * konieczna refaktoryzacja!
         */
        level.printLevelContent(iWindow);
    }


}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

bool Game::ifMarioShouldDie() {

    return false;
}