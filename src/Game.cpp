#include <chrono>
#include "headers/Game.h"

void Game::run() {


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
        if(level.isOnTopOfAny(mario)) mario.setOnTopOfAny(true);
        mario.MoveStatus();
        if (!level.isOnTopOfAny(mario)) mario.move(0, 2.0f);
        mario.setOnTopOfAny(false);
        mario.draw(iWindow);
        if(mario.isGoesRight())
            level.updateLevelPositionsWhileWalk();
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
