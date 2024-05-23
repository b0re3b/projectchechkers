#include "move.h"

/**
 * @brief Default constructor for Move class.
 */
Move::Move() : startX(0), startY(0), endX(0), endY(0) {}

/**
 * @brief Constructor for Move class.
 * @param startX Starting X coordinate.
 * @param startY Starting Y coordinate.
 * @param endX Ending X coordinate.
 * @param endY Ending Y coordinate.
 */
Move::Move(int startX, int startY, int endX, int endY)
        : startX(startX), startY(startY), endX(endX), endY(endY) {}

/**
 * @brief Get the starting X coordinate of the move.
 * @return Starting X coordinate.
 */
int Move::getStartX() const {
    return startX;
}

/**
 * @brief Get the starting Y coordinate of the move.
 * @return Starting Y coordinate.
 */
int Move::getStartY() const {
    return startY;
}

/**
 * @brief Get the ending X coordinate of the move.
 * @return Ending X coordinate.
 */
int Move::getEndX() const {
    return endX;
}

/**
 * @brief Get the ending Y coordinate of the move.
 * @return Ending Y coordinate.
 */
int Move::getEndY() const {
    return endY;
}