//
// Created by wojciech on 21.03.2022.
//
#include <chrono>
#include "headers/Game.h"

void Game::run() {

    while(window.isOpen()) {
        //początek klatki
        auto frameStart = std::chrono::steady_clock::now();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

           // mario.MoveStatus();

        }

        window.clear(sf::Color::Red);
        //mario.MoveStatus();
        engine.updateWindow(window);
        window.display();


        //koniec klatki i ewentualne poczekanie
        auto frameStop = std::chrono::steady_clock::now();
        while ((frameStop-frameStart).count() < FRAME_TIME)
            frameStop = std::chrono::steady_clock::now();

    }
}
