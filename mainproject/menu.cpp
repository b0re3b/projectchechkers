#include "menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window) : window(window) {}

PlayerColor Menu::chooseColor() {
    sf::Font font;
    if (!font.loadFromFile("/Users/bogdanresetko/Desktop/projects2024/дфддфдф/mainproject/ArialMT.ttf")) {
        std::cerr << "Font file not found!" << std::endl;
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Choose your color:");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 150);

    sf::Text redText;
    redText.setFont(font);
    redText.setString("Red");
    redText.setCharacterSize(30);
    redText.setFillColor(sf::Color::Red);
    redText.setPosition(100, 250);

    sf::Text blackText;
    blackText.setFont(font);
    blackText.setString("Black");
    blackText.setCharacterSize(30);
    blackText.setFillColor(sf::Color::Black);
    blackText.setPosition(100, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (redText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    return PlayerColor::Red;
                }
                if (blackText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    return PlayerColor::Black;
                }
            }
        }
        window.clear(sf::Color::Green);
        window.draw(text);
        window.draw(redText);
        window.draw(blackText);
        window.display();
    }
    return PlayerColor::Red;
}
