/**
 * @file game.hpp
 * @brief Header file for the Game class, which manages the core gameplay loop and interactions between the players and the board.
 */
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "board.h"


/**
 * @brief Represents the main game logic and interaction.
 *
 * This class manages the core gameplay loop, including drawing the board, handling input, and facilitating turns between the human and computer players. It holds references to the game window, the board, and the player objects.
 */
class Game {
private:
    /**
     * @brief Reference to the SFML RenderWindow for displaying the game.
     */
    sf::RenderWindow& window;

    /**
     * @brief Instance of the Board class, representing the game board.
     */
    Board board;

    /**
     * @brief Reference to the Player object representing the human player.
     */
    Player& humanPlayer;

    /**
     * @brief Reference to the Player object representing the computer player.
     */
    Player& computerPlayer;

public:
    /**
     * @brief Constructs a Game object.
     *
     * Initializes a Game instance with references to the necessary components:
     * the game window, human player, computer player, and the board (which is created internally).
     *
     * @param window Reference to the SFML RenderWindow used for rendering.
     * @param humanPlayer Reference to the Player object representing the human player.
     * @param computerPlayer Reference to the Player object representing the computer player.
     */
    Game(sf::RenderWindow& window, Player& humanPlayer, Player& computerPlayer);

    /**
     * @brief Runs the main game loop.
     *
     * This function initiates the core game loop. It continuously:
     * 1. Clears the window.
     * 2. Draws the current state of the board.
     * 3. Handles player input (from both human and computer players).
     * 4. Updates the game state accordingly.
     * 5. Displays the updated game state on the screen.
     *
     * The loop continues until the game window is closed.
     */
    void run();
    int difficulty = 1;
};

#endif // GAME_HPP
