#include "headers/Game.h"

void Game::run() {
    window.initialize();
    displayMenu();
    window.flush();
    gameMusic.play();
    displayGame();
    window.close();
}

void Game::displayGame() {
    if (!menu.doWantToLeave()) {
        while (window.isOpen() and !getBackToMenu and !menu.doWantToLeave()) {
            handleEvents();
            updateGame();
            if(getBackToMenu)
            {
                gameMusic.stop();
                window.flush();
                menu.setEnd();
                displayMenu();
                getBackToMenu = false;
            }
        }
    }
}

void Game::updateGame() {
    if (gameON) {
        window.getRenderWindow().clear(sf::Color(92, 148, 252));
        if(!this->paused) {
            processRelations();
        }
        renderContent();
        window.display();

    }
}


void Game::processRelations() {
    level.generateCollisions(mario, true);
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
    handleWindowExit();
    handlePauseEvent();
}

void Game::handleWindowExit() {
    sf::Event event;
    while (window.getRenderWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.getRenderWindow().close();
    }
}

void Game::handlePauseEvent() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && gameCooldown == 0.f)
    {
        if(!paused)
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
        if(!menu.getOptions()) {
            menu.handleKeyboardInput(window.getRenderWindow());
            menu.draw(window.getRenderWindow());
            window.display();
            window.flush();
            if (menu.getEnd())
                proceed = true;
            if (menu.isNewGame())
                this->restartGame();
        }
        else
        {
            optionsMenu.handleKeyboardInput(window.getRenderWindow());
            optionsMenu.draw(window.getRenderWindow());
            window.display();
            if(optionsMenu.getReturn())
            {
                optionsMenu.setReturn();
                menu.setOptions();
            }
            window.flush();

        }
    }
}

Game::Game() {
    font->loadFromFile("../src/resources/SuperMario256.ttf");
    if(gameMusic.openFromFile("../src/resources/music.ogg"))
    {
        std::cerr<<"Background music load error\n";
    }
    scoreDisplayText.setFont(*font);
    scoreDisplayText.setCharacterSize(0.6*SCREEN_WIDTH);
    scoreDisplayText.setScale(0.07, 0.07);
}
