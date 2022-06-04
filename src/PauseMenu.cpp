#include "headers/PauseMenu.h"

PauseMenu::PauseMenu(float width, float height) {
    blurTexture.loadFromFile("../src/resources/blur.png");
    blurSprite.setTexture(blurTexture);
    font->loadFromFile("../src/resources/SuperMario256.ttf");

    pauseMenu[0].setFont(*font);
    pauseMenu[0].setFillColor(sf::Color::White);
    pauseMenu[0].setString("Graj dalej");
    pauseMenu[0].setCharacterSize(0.6*SCREEN_WIDTH);
    pauseMenu[0].setScale(0.1, 0.1);
    pauseMenu[0].setPosition(0.4*SCREEN_WIDTH, 0.4*SCREEN_HEIGHT);

    pauseMenu[1].setFont(*font);
    pauseMenu[1].setFillColor(sf::Color::White);
    pauseMenu[1].setString("Wyjdz do menu");
    pauseMenu[1].setCharacterSize(0.6*SCREEN_WIDTH);
    pauseMenu[1].setScale(0.1, 0.1);
    pauseMenu[1].setPosition(0.4*SCREEN_WIDTH, 0.6*SCREEN_HEIGHT);

    selected = 0;
}

PauseMenu::~PauseMenu() {

}

void PauseMenu::blur(sf::RenderWindow& window)
{
    window.draw(blurSprite);
}

void PauseMenu::draw(sf::RenderWindow& window)
{
    pauseMenu[selected].setFillColor(sf::Color::Red);
    for(int i=0; i< 2; i++)
    {
        window.draw(pauseMenu[i]);
    }
}

void PauseMenu::up()
        {
            if(selected >= 0)
            {
                pauseMenu[selected].setFillColor(sf::Color::White);
                selected--;
                if(selected == -1)
                {
                    selected = 1;
                }
            }
        }
void PauseMenu::down()
{
    if(selected + 1 <= 2)
    {
        pauseMenu[selected].setFillColor(sf::Color::White);
        selected++;
        if(selected == 2)
        {
            selected = 0;
        }
        pauseMenu[selected].setFillColor(sf::Color::Red);
    }
}

void PauseMenu::handleInput() {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && cooldown == 0.f)
        {
            PauseMenu::up();
            cooldown = cooldownmax;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && cooldown == 0.f)
        {
            PauseMenu::down();
            cooldown = cooldownmax;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && cooldown == 0.f) {
            pauseMenu[selected].setFillColor(sf::Color::White);
            if (selected == 0) {
                exit = true;
            }
            else
            {
                back = true;
            }
        }
    if(cooldown > 0)
    {
        cooldown -= 1.f;
    }
}

bool PauseMenu::getexitStatus()
{
    return exit;
}

void PauseMenu::changeExitStatus()
{
    exit = false;
}

bool PauseMenu::getBackStatus() {
    return back;
}
