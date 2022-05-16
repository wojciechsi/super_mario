#ifndef SUPER_MARIO_WINDOW_H
#define SUPER_MARIO_WINDOW_H

#include <SFML/Graphics.hpp>
#include "defs.h"
#include "Menu.h"
/**
 * Klasa wyzwalająca i obsługująca okno
 */
class Window {
private:
    sf::RenderWindow renderWindow = sf::RenderWindow(
            sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
            "Super Mario Bros");
public:
    Window() = default;

    /**
     * Nadaje parametry nowemu oknu.
     */
    void initialize();

    /**
     * Oczyszcza okno z zawartości.
     */
    void flush();

    /**
     * Getter okna.
     * @return referencja do sf::RenderWindow
     */
    sf::RenderWindow& getRenderWindow () {return renderWindow;}

    /**
     * Getter informacji o otwarciu okna.
     * @return czy okno jest otwarte
     */
    bool isOpen() {return this->renderWindow.isOpen();}

    /**
     * Zamyka okno.
     */
    void close() {this->renderWindow.close();}

    /**
     * Wyświetla zawartość okna na ekranie urządzenia.
     */
    void display() {this->renderWindow.display();}
};


#endif //SUPER_MARIO_WINDOW_H
