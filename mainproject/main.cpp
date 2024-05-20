/**
 * @file main.cpp
 * @brief Main entry point for the Checkers game.
 */

#include <SFML/Graphics.hpp>
#include "gameloop.h"
#include "menu.h"

/**
 * @brief Main function to run the Checkers game.
 *
 * This function creates a window, displays a menu to choose the player's color,
 * initializes the human and computer players, and starts the game loop.
 *
 * @return int Returns 0 upon successful completion.
 */
int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Checkers");

    Menu menu(window);
    PlayerColor playerColor = menu.chooseColor();

    // Гравець, який вибрав колір, буде людиною
    Player humanPlayer(sf::Color::Red);
    // Комп'ютер або людина, залежно від обраного кольору
    Player computerPlayer(playerColor == PlayerColor::Red ? sf::Color::Black : sf::Color::Red);

    Game game(window, humanPlayer, computerPlayer);
    game.run();

    return 0;
}
