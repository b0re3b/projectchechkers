/**
 * @file piece.h
 * @brief Header file for the Piece class, which represents a checker piece on the board.
 */

#ifndef MAINPROJECT_PIECE_H
#define MAINPROJECT_PIECE_H

#include <SFML/Graphics.hpp>
#include "piecestate.h"

class PieceState;
class Board;

/**
 * @brief Represents a checker piece on the board.
 *
 * This class stores the state of a checker piece, including its position, color, whether it's a king, and whether it's still in play. It also provides functionality to draw the piece on the screen.
 */
class Piece {
private:
    PieceState* state;

public:
    /**
     * @brief Constructor for the Piece class.
     * @param initialState The initial state of the piece.
     * @param king Flag indicating whether the piece is a king.
     */
    Piece(PieceState* initialState = nullptr, bool king = false);

    /**
     * @brief Draws the piece on the given SFML window.
     * @param window The SFML window on which to draw the piece.
     */
    void Draw(sf::RenderWindow& window);

    /**
     * @brief Destructor for the Piece class.
     */
    ~Piece() {
        delete state;
    }

    /**
     * @brief Sets the state of the piece.
     * @param newState The new state of the piece.
     */
    void setState(PieceState* newState) {
        delete state;
        state = newState;
    }

    /**
     * @brief Moves the piece to the specified position on the board.
     * @param newX The x-coordinate of the new position.
     * @param newY The y-coordinate of the new position.
     * @param board Reference to the game board.
     */
    void move(int newX, int newY, Board& board);

    /**
     * @brief Attacks the piece at the specified position on the board.
     * @param targetX The x-coordinate of the target position.
     * @param targetY The y-coordinate of the target position.
     * @param board Reference to the game board.
     */
    void attack(int targetX, int targetY, Board& board);

    bool isKing;    /**< Flag indicating whether the piece is a king. */
    bool isAlive;   /**< Flag indicating whether the piece is still in play. */
    int x;          /**< The x-coordinate of the piece on the board. */
    int y;          /**< The y-coordinate of the piece on the board. */
    sf::Color color; /**< The color of the piece. */
};

#endif // MAINPROJECT_PIECE_H
