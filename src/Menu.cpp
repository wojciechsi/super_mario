#include <iostream>
#include "headers/Menu.h"
#include "headers/Game.h"

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("../src/resources/SuperMario256.ttf"))
    {
        std::cout << "Font error";
    }

    //new game
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setString("Nowa Gra");
    mainMenu[0].setCharacterSize(7);
    mainMenu[0].setPosition(0.5*SCREEN_WIDTH, 0.3*SCREEN_HEIGHT);

    //continue
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(sf::Color::White);
    mainMenu[1].setString("Kontynuuj");
    mainMenu[1].setCharacterSize(7);
    mainMenu[1].setPosition(0.5*SCREEN_WIDTH, 0.4*SCREEN_HEIGHT);

    //options
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(sf::Color::White);
    mainMenu[2].setString("Opcje");
    mainMenu[2].setCharacterSize(7);
    mainMenu[2].setPosition(0.5*SCREEN_WIDTH, 0.5*SCREEN_HEIGHT);

    //Creators
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(sf::Color::White);
    mainMenu[3].setString("Tworcy");
    mainMenu[3].setCharacterSize(7);
    mainMenu[3].setPosition(0.5*SCREEN_WIDTH, 0.6*SCREEN_HEIGHT);

    //exit game
    mainMenu[4].setFont(font);
    mainMenu[4].setFillColor(sf::Color::White);
    mainMenu[4].setString("Wyjdz z gry");
    mainMenu[4].setCharacterSize(7);
    mainMenu[4].setPosition(0.5*SCREEN_WIDTH, 0.7*SCREEN_HEIGHT);

    selected = -1;
}
Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
    for(int i=0; i< Max_main_menu; i++)
    {
        window.draw(mainMenu[i]);
    }
}

void Menu::Up() {
    if(selected >= 0)
    {
        mainMenu[selected].setFillColor(sf::Color::White);
        selected--;
        if(selected == -1)
        {
        selected = Max_main_menu -1;
        }
        mainMenu[selected].setFillColor(sf::Color::Red);
    }
}

void Menu::Down()
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && cooldown == 0.f)
    {
        Menu::Up();
        cooldown = cooldownmax;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && cooldown == 0.f)
    {
        Menu::Down();
        cooldown = cooldownmax;

    }
    if(cooldown > 0)
    {
        cooldown -= 1.f;
    }


}