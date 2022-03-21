#include <SFML/Graphics.hpp>

    int main() {
        sf::RenderWindow window(sf::VideoMode(600, 600), "SFML jest łatwiejszy niż SDL2");
        sf::CircleShape shape (300);
        shape.setFillColor(sf::Color::Green);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }

        return 0;
    }
