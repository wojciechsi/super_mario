#include "headers/Game.h"

void Game::run() {
    window.initialize();
    menuMusic.play();
    displayMenu();
    window.flush();
    menuMusic.stop();
    displayGame();
    window.close();
}

void Game::displayGame() {
    if (!menu.doWantToLeave()) {
        while (window.isOpen() and !getBackToMenu and !menu.doWantToLeave()) {
            handleEvents();
            updateGame();
            if(getBackToMenu) {
                processMenu();
            }
        }
    }
}

void Game::processMenu() {
    gameMusic.stop();
    window.flush();
    menu.setEnd();
    menuMusic.play();
    displayMenu();
    getBackToMenu = false;
    menuMusic.stop();
}

void Game::updateGame() {
    window.flush();
    renderContent();
    window.display();
    if (!this->paused) {
        processRelations();
        handleLifeLost();
    }
    if (level.didFinished(mario))
        finishGame();

}

void Game::handleLifeLost() {
    if (mario.checkLostLife()) {
        if (!mario.getTotalDeadStatus())
            restartGame(mario.getLives());
        else
            processGameOver();
    }
}

void Game::processGameOver() {
    gameMusic.stop();
    deathMusic.play();
    window.getRenderWindow().draw(gameOverText);
    window.display();
    sf::sleep(sf::seconds(2.0f));
    getBackToMenu = true;
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
    displayScore();
    displayLives();
}

void Game::displayScore() {
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P) && gameCooldown == 0.f)
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
            if(optionsMenu.getReturn())
            {
                optionsMenu.setReturn();
                menu.setOptions();
            }
            else if(optionsMenu.ifTextbox())
            {
                while(optionsMenu.ifTextbox()) {
                    while(window.getRenderWindow().pollEvent(textEvent)) {
                        if(textEvent.type == sf::Event::TextEntered)
                        {
                            inputTextBox.typed(textEvent);
                        }
                    }
                    optionsMenu.draw(window.getRenderWindow());
                    inputTextBox.draw(window.getRenderWindow());
                    window.display();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                    {
                        if(!inputTextBox.getText().empty() && std::regex_match(inputTextBox.getText(), fileInputRegex))
                        {
                            levelName = inputTextBox.getText();
                            ReadingSystem::getInstance() -> changeUserInputFlag();
                            ReadingSystem::getInstance() -> captureUserInput(levelName);

                        }
                        optionsMenu.setTextBox();
                       break;
                    }
                    window.flush();

                }
            }
            window.display();
            window.flush();

        }
    }
}

Game::Game() {
    loadSoundAndText();
}

void Game::loadSoundAndText() {
    if(!gameMusic.openFromFile("../src/resources/music.ogg"))
    {
        std::cerr<<"Background music load error\n";
    }
    menuMusic.openFromFile("../src/resources/menuMusic.ogg");
    if(!deathMusic.openFromFile("../src/resources/death.ogg"))
    {
        std::cerr<<"Death music load error\n";
    }
    font->loadFromFile("../src/resources/SuperMario256.ttf");
    scoreDisplayText.setFont(*font);
    scoreDisplayText.setCharacterSize(0.6 * SCREEN_WIDTH);
    scoreDisplayText.setScale(0.07, 0.07);
    gameOverText.setFont(*font);
    gameOverText.setCharacterSize(0.6*SCREEN_WIDTH);
    gameOverText.setScale(0.1, 0.1);
    gameOverText.setString("GAME OVER");
    gameOverText.setPosition(0.4*SCREEN_WIDTH, 0.5*SCREEN_HEIGHT);
    gameOverText.setOutlineColor(sf::Color::White);
    inputTextBox.setPosition({0.4*SCREEN_WIDTH, 0.4*SCREEN_HEIGHT});
    fileInputRegex = ".+\\.txt";
}

void Game::displayLives() {
    for (int i = 0; i < mario.getLives(); i++) {
        sf::Sprite heart;
        heart.setTexture(*TexturesStorage::getInstance()->getHeartTexture());
        heart.setPosition(SCREEN_WIDTH - 20*(i+1), 0);
        window.getRenderWindow().draw(heart);
    }
}

void Game::finishGame() {
    sf::Text scoreText, bestScoreText;
    scoreText.setFont(*font);
    scoreText.setCharacterSize(0.6*SCREEN_WIDTH);
    scoreText.setScale(0.1, 0.1);
    scoreText.setString("WYNIK: " + std::to_string(mario.getPoints()));
    scoreText.setPosition(0.4*SCREEN_WIDTH, 0.5*SCREEN_HEIGHT);
    scoreText.setOutlineColor(sf::Color::White);
    bestScoreText = scoreText;
    bestScoreText.setPosition(0.4*SCREEN_WIDTH, 0.7*SCREEN_HEIGHT);
    HighScoreModule::loadHighScore();
    bestScoreText.setString("REKORD: " + std::to_string(HighScoreModule::getHighScore()));
    HighScoreModule::setHighScore(mario.getPoints());
    HighScoreModule::saveHighScore();
    window.flush();
    window.getRenderWindow().draw(scoreText);
    window.getRenderWindow().draw(bestScoreText);
    window.display();
    sf::sleep(sf::seconds(3.0f));
    getBackToMenu = true;
}
