#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <limits>
#include "player.h"
#include "piece.h"
#include "move.h"
#include "movenode.h"
#include "logic.h"
#include "observer.h"

/**
 * @file board.h
 * @brief Declaration of the Board class and related structures.
 */

class logic;

/**
 * @class Board
 * @brief Represents the game board and its functionality.
 */
class Board: public Subject {
public:
    /**
     * @brief Constructor for the Board class.
     * @param red The red player.
     * @param black The black player.
     */
    Board(Player& red, Player& black);

    /**
     * @brief Getter for the red player.
     * @return Reference to the red player.
     */
    Player& getRedPlayer();

    /**
     * @brief Getter for the black player.
     * @return Reference to the black player.
     */
    Player& getBlackPlayer();

    /**
     * @brief Initializes the game board with pieces.
     * @param redPlayer The red player.
     * @param blackPlayer The black player.
     */
    void InitializeGame(Player& redPlayer, Player& blackPlayer);

    /**
     * @brief Handles player input for moving pieces.
     * @param window The SFML window.
     */
    void inputdata(sf::RenderWindow& window);

    /**
    * @brief Checks if the game has ended.
    * @return True if the game has ended, false otherwise.
    */
    bool endgame();

    /**
     * @brief Checks if there is a piece at the given coordinates.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return True if there is a piece, false otherwise.
     */
    bool isPieceAt(int x, int y) const;

    /**
     * @brief Highlights the possible moves for a selected piece.
     * @param pieceIndex The index of the selected piece.
     * @param window The SFML window.
     * @param board The game board.
     */
    void highlight(int pieceIndex, sf::RenderWindow& window, Board& board);

    /**
     * @brief Draws the game board and pieces on the SFML window.
     * @param window The SFML window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Checks if a piece at a certain position belongs to the opponent.
     * @param x The x-coordinate of the piece.
     * @param y The y-coordinate of the piece.
     * @param colorToCheck The color of the opponent.
     * @return True if the piece belongs to the opponent, false otherwise.
     */
    bool opponentPiece(int x, int y, const sf::Color& colorToCheck);

    /**
     * @brief Evaluates the board for the Minimax algorithm.
     * @param board The game board.
     * @return The evaluated score.
     */
    int evaluateBoard(Board& board);

    /**
     * @brief Generates the index of the piece that was clicked by the mouse.
     * @param mouseX The x-coordinate of the mouse.
     * @param mouseY The y-coordinate of the mouse.
     * @return The index of the clicked piece.
     */
    int MousePosition(int mouseX, int mouseY);

    Player& redPlayer;  ///< Reference to the red player.
    Player& blackPlayer;///< Reference to the black player.
    Piece pieces[24];   ///< Array storing the pieces on the board.
    static constexpr int size = 8; ///< Size of the game board.

private:
    int selectedPieceIndex = -1;    ///< Index of the currently selected piece.
    logic gameLogic;                ///< Logic object to handle game rules and logic.
};

#endif // BOARD_HPP
