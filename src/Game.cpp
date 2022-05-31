#include "headers/Game.h"

void Game::run() {
    window.initialize();

    bool cos = false;
    while(window.isOpen()) {
        handleEvents();
        menu.handleKeyboardInput(window.getRenderWindow());
        menu.draw(window.getRenderWindow());
        window.display();
        window.flush();
    }

    window.flush();
    while(window.isOpen()) {
        handleEvents();
        updateGame();
    }
    window.close();
}

void Game::updateGame() {
    if (gameON) {
        window.flush();
        processRelations();
        renderContent();
        window.display();
    }
}

void Game::processRelations() {
    level.generateCollisions(mario);
    mario.update();
    level.updateEnemiesPositions();
    updateWhatMarioWithEnemiesDo();
}

void Game::updateWhatMarioWithEnemiesDo() {
    if(mario.isAlive()) {
        level.generateCollisionsWithEnemies(mario);
        if (mario.isGoesRight())
            if (!mario.hasRightCollision())
                level.updateLevelPositionsWhileWalk();
    }
    if (level.shouldMarioJump())
        mario.jumpWithinConditions();
}

void Game::renderContent() {
    level.printLevelContent(window.getRenderWindow());
    mario.draw(window.getRenderWindow());
}

void Game::handleEvents() {
    sf::Event event;
    while (window.getRenderWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.getRenderWindow().close();
    }
}
