#include "headers/Game.h"

void Game::run() {
    window.initialize();
    //MENU
    bool proceed = false;
    while (window.isOpen() and proceed == false) {
        handleEvents();
        menu.handleKeyboardInput(window.getRenderWindow());
        menu.draw(window.getRenderWindow());
        window.display();
        window.flush();
        if (menu.getEnd() == true)
            proceed = true;
    }
    //GAME
    window.flush();
    if(!menu.doWantToLeave()) {
        while (window.isOpen()) {
                handleEvents();
                updateGame();
        }
    }
    window.close();
}

void Game::updateGame() {
        if (gameON) {
            window.flush();
            if(!this->paused) {
                processRelations();
            }
            renderContent();
            window.display();
        }
    }


void Game::processRelations() {
    level.generateCollisions(mario);
    mario.update();
    level.updateEnemiesPositions();
    updateWhatMarioWithEnemiesDo();
    mario.addPoints(level.getPointsToAdd());
    level.clearPointsToAdd();
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && gameCooldown == 0.f)
    {
        if(!this->paused)
        {
            pause();
            gameCooldown = gameCooldownmax;
        }
        else
        {
            unpause();
            gameCooldown = gameCooldownmax;
        }
    }

    if(gameCooldown > 0)
    {
        gameCooldown -= 1.f;
    }
}

void Game::pause() {
    this->paused = true;
}

void Game::unpause() {
    this->paused = false;
}
