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
Piece::Piece() : isAlive(false), isKing(false), x(0), y(0), color(sf::Color::White) {}
void Piece::Draw(sf::RenderWindow& window) {
    // Check if the piece is alive (not captured)
    if (isAlive) {
        // Create a circle shape for the piece
        sf::CircleShape shape(30.f); // Radius of 30 pixels
        shape.setFillColor(color);  // Set the fill color of the piece (red or black)

        // If the piece is a king, add a yellow outline
        if (isKing) {
            shape.setOutlineThickness(3.f);   // Outline thickness
            shape.setOutlineColor(sf::Color::Yellow); // Outline color
        }

        // Calculate the position on the board and draw the shape
        shape.setPosition(sf::Vector2f(x * 75 + (75 - 2 * 30) / 2, y * 75 + (75 - 2 * 30) / 2));
        window.draw(shape);
    }
}
