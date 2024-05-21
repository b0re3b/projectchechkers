/**
 * @file game.cpp
 * @brief Implementation of the Game class, which manages the core gameplay loop.
 */

#include "gameloop.h"

/**
 * @brief Constructs a Game object.
 *
 * Initializes a Game instance, associating it with a RenderWindow, two Player objects (human and computer), and a Board to manage the game state.
 *
 * @param window The SFML RenderWindow used for rendering the game.
 * @param humanPlayer The Player object representing the human player.
 * @param computerPlayer The Player object representing the computer player.
 */
Game::Game(sf::RenderWindow& window, Player& humanPlayer, Player& computerPlayer)
        : window(window), humanPlayer(humanPlayer), computerPlayer(computerPlayer), board(humanPlayer, computerPlayer) {}

/**
 * @brief Runs the main game loop.
 *
 * This function handles the continuous cycle of the game:
 * 1. Clears the window to prepare for rendering.
 * 2. Draws the current state of the board onto the window.
 * 3. Collects input from the player through the window.
 * 4. Displays the updated window contents on the screen.
 *
 * The loop continues until the window is closed.
 */
void Game::run() {
    while (window.isOpen()) {
        window.clear();
        board.draw(window);
        board.inputdata(window);
        window.display();
    }
}
