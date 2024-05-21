/**
 * @file menu.cpp
 * @brief Implementation of the Menu class, which handles player color selection.
 */

#include "menu.h"
#include <iostream>

/**
 * @brief Constructs a Menu object.
 *
 * Initializes the Menu object with a reference to the SFML RenderWindow it will use for display.
 *
 * @param window Reference to the SFML RenderWindow object.
 */
Menu::Menu(sf::RenderWindow& window) : window(window) {}

/**
 * @brief Displays a menu for the player to choose their color (Red or Black).
 *
 * This function presents a simple menu with text options for "Red" and "Black." It waits for the user to click on one of the options and returns a Player object with the corresponding color.
 *
 * @return Player object with the chosen color. If the window closes before a choice is made, it defaults to a Player object with color Red.
 */
Player Menu::chooseColor() {
    // Load the font for the text
    sf::Font font;
    if (!font.loadFromFile("/Users/bogdanresetko/Desktop/projects2024/дфддфдф/mainproject/ArialMT.ttf")) {
        std::cerr << "Font file not found!" << std::endl;
    }

    // Create and position text elements
    sf::Text text, redText, blackText;

    text.setFont(font);
    text.setString("Choose your color:");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 150);

    redText.setFont(font);
    redText.setString("Red");
    redText.setCharacterSize(30);
    redText.setFillColor(sf::Color::Red);
    redText.setPosition(100, 250);

    blackText.setFont(font);
    blackText.setString("Black");
    blackText.setCharacterSize(30);
    blackText.setFillColor(sf::Color::Black);
    blackText.setPosition(100, 300);

    // Main menu loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Handle mouse click events
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Check if the click is within the bounds of the "Red" text
                if (redText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red);
                }

                // Check if the click is within the bounds of the "Black" text
                if (blackText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Black);
                }
            }
        }

        // Render the menu
        window.clear(sf::Color::Green);
        window.draw(text);
        window.draw(redText);
        window.draw(blackText);
        window.display();
    }

    // Default return value if the window closes unexpectedly
    return Player(sf::Color::Red);
}
