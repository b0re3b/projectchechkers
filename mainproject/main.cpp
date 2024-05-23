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
    Player playerColor = menu.chooseColor();

    // The player who chooses the color will be the human
    Player humanPlayer(playerColor.getColor(), Player::PlayerType::Human);
    // The opponent, either computer or human depending on the chosen color
    Player opponent(playerColor.getColor() == sf::Color::Red ? sf::Color::Black : sf::Color::Red, Player::PlayerType::Computer);

    Game game(window, humanPlayer, opponent);
    game.run();

    return 0;
}

