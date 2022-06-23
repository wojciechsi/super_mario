#ifndef SUPER_MARIO_MENU_H
#define SUPER_MARIO_MENU_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Window.h"
#include "defs.h"
#include "TexturesStorage.h"

#define Max_main_menu 4
/**
 * Klasa zapewniająca opcje wyboru
 */
class Menu {
public:
    Menu() : Menu(SCREEN_WIDTH, SCREEN_HEIGHT) {}
    Menu(float width, float height);

    /**
     * Metoda wyświetla menu na ekranie.
     */
    void draw(sf::RenderWindow& window);

    /**
     * Metoda pozwala na wybranie opcji powyżej.
     */
    void up();
    /**
     *Metoda pozwala na wybór opcji poniżej.
     */
    void down();

    /**
     *Metoda informuje, czy chcemy wyjść z menu.
     * @return Informacja, czy użytkownik chce wyjść z menu.
     */
    bool getEnd();

    /**
     * Metoda informuje, czy użytkownik chce przejść do menu opcji.
     * @return Informacja, czy program ma wyświetlić menu opcji.
     */
    bool getOptions();
    /**
     * Metoda ustawia flagę opcji na false. Pozwala to na ponowne wyświetlenie menu opcji.
     */
    void setOptions();

    /**
     * Metoda odpowiadająca za przyjomowanie danych wejściowych od użytkownika.
     * @param window Metoda jako parametr przyjmuje wyświetlane okno.
     */
    void handleKeyboardInput(sf::RenderWindow &window);

    /**
     * Metoda wywoływana w momencie zatwierdzenia w menu.
     * @return Która opcja została wybrana.
     */
    int Pressed()
    {
        return selected;
    }
    /**
     * Metoda ustawia flagę końca na false. Pozwala to na ponowne wyświetlenie menu.
     */
    void setEnd();
private:
    sf::RectangleShape background;
    int selected;
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    sf::Text mainMenu[Max_main_menu];
    sf::Text optionsMenu[2];
    float cooldown = 15.f;
    float cooldownmin = 0.f;
    float cooldownmax = 15.f;
    bool end = false;
    bool wantLeave = false;
    bool newGame = false;
    bool options = false;
public:
    /**
     * Metoda odpowiadająca za przekazanie informacji, czy użytkownik chce rozpocząć nową grę.
     * @return Flaga nowej gry.
     */
    bool isNewGame() const;

public:
    /**
     * Informacja czy użytkownik chce wyjść z gry.
     * @return Flaga końca gry.
     */
    bool doWantToLeave() const;
};


#endif //SUPER_MARIO_MENU_H
