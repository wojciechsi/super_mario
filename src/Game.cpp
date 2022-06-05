#include "headers/Game.h"

void Game::run() {
    window.initialize();
    //MENU
    font->loadFromFile("../src/resources/SuperMario256.ttf");
    scoreDisplayText.setFont(*font);
    scoreDisplayText.setCharacterSize(0.6*SCREEN_WIDTH);
    scoreDisplayText.setScale(0.07, 0.07);

    displayMenu();
        //GAME
        window.flush();
        if (!menu.doWantToLeave()) {

            while (window.isOpen() && !getBackToMenu && !menu.doWantToLeave()) {
                handleEvents();
                updateGame();
                if(getBackToMenu)
                {
                    window.flush();
                    menu.setEnd();
                    displayMenu();
                    getBackToMenu = false;
                }
            }
        }

    window.close();
}

void Game::updateGame() {
        if (gameON) {
            //window.flush();
            window.getRenderWindow().clear(sf::Color(92, 148, 252));
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
    if (paused) {
        pauseMenu.blur(window.getRenderWindow());
        pauseMenu.draw(window.getRenderWindow());
    }
    window.getRenderWindow().draw(scoreDisplayText);
    scoreDisplayText.setString("Score: " + std::to_string(mario.getPoints()));
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

    if(paused)
    {
        pauseMenu.handleInput();
        if(pauseMenu.getexitStatus())
        {
            unpause();
            pauseMenu.changeExitStatus();
        }
        else if(pauseMenu.getBackStatus())
        {
            unpause();
            getBackToMenu = true;
            pauseMenu.changeBackStatus();
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

void Game::displayMenu() {
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
}
