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
        mario.MoveStatus();
        mario.draw(iWindow);
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
