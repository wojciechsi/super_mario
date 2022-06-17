#include "headers/OptionsMenu.h"

OptionsMenu::OptionsMenu(float width, float height)
{
    font->loadFromFile("../src/resources/SuperMario256.ttf"); //@todo put this to storage

    background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    background.setTexture(TexturesStorage::getInstance()->getBackgroundTexture().get());

    optionsMenu[0].setFont(*font);
    optionsMenu[0].setFillColor(sf::Color::White);
    optionsMenu[0].setString("Podaj nazwe pliku z mapa");
    optionsMenu[0].setCharacterSize(0.6*SCREEN_WIDTH);
    optionsMenu[0].setScale(0.05, 0.05);
    optionsMenu[0].setPosition(0.4*SCREEN_WIDTH, 0.3*SCREEN_HEIGHT);

    optionsMenu[1].setFont(*font);
    optionsMenu[1].setFillColor(sf::Color::White);
    optionsMenu[1].setString("Powrot");
    optionsMenu[1].setCharacterSize(0.6*SCREEN_WIDTH);
    optionsMenu[1].setScale(0.05, 0.05);
    optionsMenu[1].setPosition(0.4*SCREEN_WIDTH, 0.5*SCREEN_HEIGHT);

    selected = 0;


}

void OptionsMenu::draw(sf::RenderWindow &window) {
    window.draw(background);
    optionsMenu[selected].setFillColor(sf::Color::Red);
    for(const auto & i : optionsMenu)
    {
        window.draw(i);
    }
}

void OptionsMenu::up() {
    if (selected >= 0) {
        optionsMenu[selected].setFillColor(sf::Color::White);
        selected--;
        if (selected == -1) {
            selected = Max_options_menu -1;
        }
    }
}
void OptionsMenu::down()
{
    if(selected + 1 <= Max_options_menu)
    {
        optionsMenu[selected].setFillColor(sf::Color::White);
        selected++;
        if(selected == Max_options_menu)
        {
            selected = 0;
        }
        optionsMenu[selected].setFillColor(sf::Color::Red);
    }
}


void OptionsMenu::handleKeyboardInput(sf::RenderWindow &window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && cooldown == 0.f)
    {
        OptionsMenu::up();
        cooldown = cooldownmax;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && cooldown == 0.f)
    {
        OptionsMenu::down();
        cooldown = cooldownmax;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && cooldown == 0.f)
    {
        optionsMenu[selected].setFillColor(sf::Color::White);
        if(selected == 0)
        {
            ifTextbox();

        }
        else if(selected == 1)
        {
            returnToMenu();
            selected = 0;
        }
        cooldown = cooldownmax;
        Pressed();

    }

    if(cooldown > 0)
    {
        cooldown -= 1.f;
    }
}

void OptionsMenu::returnToMenu() {
    wantReturn = true;

}

bool OptionsMenu::getReturn() {
    return wantReturn;
}

void OptionsMenu::setReturn() {
    wantReturn = false;
}

bool OptionsMenu::ifTextbox() {
    displayTextBox = true;
}

void OptionsMenu::setTextBox()
{
    displayTextBox = false;
}