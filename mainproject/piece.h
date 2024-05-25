/**
 * @file piece.h
 * @brief Header file for the Piece class, which represents a checker piece on the board.
 */
#ifndef MAINPROJECT_PIECE_H
#define MAINPROJECT_PIECE_H

#include <SFML/Graphics.hpp>

/**
 * @brief Represents a checker piece on the board.
 *
 * This class stores the state of a checker piece, including its position, color, whether it's a king, and whether it's still in play. It also provides functionality to draw the piece on the screen.
 */
class Piece {
private:
    /**
     * @brief Indicates if the piece is still alive (not captured).
     */
    friend class Board;
    friend class logic;

public:

    /**
     * @brief Default constructor for the Piece class.
     */
    Piece();

    /**
     * @brief Renders the checker piece on the screen.
     *
     * This function draws a circle shape representing the checker piece within the specified SFML RenderWindow.
     * The piece is only drawn if it is alive (isAlive). If the piece is a king, an additional yellow outline is added to distinguish it.
     *
     * @param window Reference to the SFML RenderWindow object where the piece will be drawn.
     */
    void Draw(sf::RenderWindow& window);  // Function to draw the piece
/**
 * @brief Indicates if the piece is a king (can move backwards).
 */
    bool isKing;
    bool isAlive;
/**
 * @brief x-coordinate of the piece on the board.
 */
    int x;
/**
 * @brief y-coordinate of the piece on the board.
 */
    int y;
/**
 * @brief Color of the piece (Red or Black).
 */
    sf::Color color;
};

#endif //MAINPROJECT_PIECE_H
