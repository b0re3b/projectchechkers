/**
 * @file piece.cpp
 * @brief Implementation of the Piece class, which represents a checker piece on the board.
 */

#include "piece.h"

/**
 * @brief Renders the checker piece on the screen.
 *
 * This function draws a circle shape representing the checker piece within the specified SFML RenderWindow. 
 * The piece is only drawn if it is alive (isAlive). If the piece is a king, an additional yellow outline is added to distinguish it.
 *
 * @param window Reference to the SFML RenderWindow object where the piece will be drawn.
 */


Piece::Piece(PieceState* initialState, bool king) : state(initialState), isKing(king), isAlive(true), x(0), y(0), color(sf::Color::White) {}

