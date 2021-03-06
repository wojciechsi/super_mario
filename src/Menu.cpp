#include "headers/Menu.h"

Menu::Menu(float width, float height)
{
    font->loadFromFile("../src/resources/SuperMario256.ttf"); //@todo put this to storage

    background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    background.setTexture(TexturesStorage::getInstance()->getBackgroundTexture().get());

    //new game
    mainMenu[0].setFont(*font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("Nowa Gra");
    mainMenu[0].setCharacterSize(0.6*SCREEN_WIDTH);
    mainMenu[0].setScale(0.1, 0.1);
    mainMenu[0].setPosition(0.5*SCREEN_WIDTH, 0.3*SCREEN_HEIGHT);

    //continue
    mainMenu[1].setFont(*font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Kontynuuj");
    mainMenu[1].setCharacterSize(0.6*SCREEN_WIDTH);
    mainMenu[1].setScale(0.1, 0.1);
    mainMenu[1].setPosition(0.5*SCREEN_WIDTH, 0.4*SCREEN_HEIGHT);

    //options
    mainMenu[2].setFont(*font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("Opcje");
    mainMenu[2].setCharacterSize(0.6*SCREEN_WIDTH);
    mainMenu[2].setScale(0.1, 0.1);
    mainMenu[2].setPosition(0.5*SCREEN_WIDTH, 0.5*SCREEN_HEIGHT);

    //Creators
    mainMenu[3].setFont(*font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Wyjdz z gry");
    mainMenu[3].setCharacterSize(0.6*SCREEN_WIDTH);
    mainMenu[3].setScale(0.1, 0.1);
    mainMenu[3].setPosition(0.5*SCREEN_WIDTH, 0.6*SCREEN_HEIGHT);

    //exit game
   /* mainMenu[4].setFont(*font);
    mainMenu[4].setFillColor(sf::Color::White);
    mainMenu[4].setString("Wyjdz z gry");
    mainMenu[4].setCharacterSize(0.6*SCREEN_WIDTH);
    mainMenu[4].setScale(0.1, 0.1);
    mainMenu[4].setPosition(0.5*SCREEN_WIDTH, 0.7*SCREEN_HEIGHT);
    */

    optionsMenu[0].setFont(*font);
    optionsMenu[0].setFillColor(sf::Color::White);
    optionsMenu[0].setString("Podaj nazwę pliku z mapą: ");
    optionsMenu[0].setCharacterSize(0.6*SCREEN_WIDTH);
    optionsMenu[0].setScale(0.1, 0.1);
    optionsMenu[0].setPosition(0.4*SCREEN_WIDTH, 0.3*SCREEN_HEIGHT);

    optionsMenu[1].setFont(*font);
    optionsMenu[1].setFillColor(sf::Color::White);
    optionsMenu[1].setString("Powrót");
    optionsMenu[1].setCharacterSize(0.6*SCREEN_WIDTH);
    optionsMenu[1].setScale(0.1, 0.1);
    optionsMenu[1].setPosition(0.4*SCREEN_WIDTH, 0.5*SCREEN_HEIGHT);

    selected = 0;
}


bool Menu::getEnd()
{
    return end;
}

void Menu::draw(sf::RenderWindow &window) {
    window.draw(background);
    mainMenu[selected].setFillColor(sf::Color::Red);
    for(const auto & i : mainMenu)
    {
        window.draw(i);
    }
}



void Menu::up() {
    if(selected >= 0)
    {
        mainMenu[selected].setFillColor(sf::Color::White);
        selected--;
        if(selected == -1)
        {
        selected = Max_main_menu -1;
        }
    }
}

void Menu::down()
{
    if(selected + 1 <= Max_main_menu)
    {
        mainMenu[selected].setFillColor(sf::Color::White);
        selected++;
        if(selected == Max_main_menu)
        {
            selected = 0;
        }
        mainMenu[selected].setFillColor(sf::Color::Red);
    }
}



void Menu::handleKeyboardInput(sf::RenderWindow &window)
{
    newGame = false;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && cooldown == 0.f)
    {
        Menu::up();
        cooldown = cooldownmax;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && cooldown == 0.f)
    {
        Menu::down();
        cooldown = cooldownmax;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && cooldown == 0.f)
    {
        mainMenu[selected].setFillColor(sf::Color::White);
        if(selected == 0)
        {
            newGame = true;
            end = true;
        }
        else if(selected == 1)
        {
            end = true;
        }
        else if(selected == 2)
        {
            options = true;
        }

        else if(selected == 3)
        {
            wantLeave = true;
            end = true;
        }
       /* else if(selected == 4)
        {
            wantLeave = true;
            end = true;
        }*/
        cooldown = cooldownmax;
        Pressed();

    }

    if(cooldown > 0)
    {
        cooldown -= 1.f;
    }
}

bool Menu::doWantToLeave() const {
    return wantLeave;
}

void Menu::setEnd() {
    end = false;
}

bool Menu::isNewGame() const {
    return newGame;
}

bool Menu::getOptions() {
    return options;
}

void Menu::setOptions() {
    options = false;
}
