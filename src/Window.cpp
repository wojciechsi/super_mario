#include "headers/Window.h"

void Window::initialize() {
    renderWindow.setSize(sf::Vector2u(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2));
    renderWindow.setFramerateLimit(FRAMES);
}

void Window::flush() {
    renderWindow.clear(sf::Color::Black);
}