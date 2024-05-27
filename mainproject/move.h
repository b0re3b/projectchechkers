#ifndef MAINPROJECT_MOVE_H
#define MAINPROJECT_MOVE_H

/**
 * @brief Class representing a move in the game.
 */
class Move {
public:
    /**
     * @brief Default constructor for Move class.
     */
    Move();

    /**
     * @brief Constructor for Move class.
     * @param startX Starting X coordinate.
     * @param startY Starting Y coordinate.
     * @param endX Ending X coordinate.
     * @param endY Ending Y coordinate.
     */
    Move(int startX, int startY, int endX, int endY);

    /**
     * @brief Get the starting X coordinate of the move.
     * @return Starting X coordinate.
     */
    int getStartX() const;

    /**
     * @brief Get the starting Y coordinate of the move.
     * @return Starting Y coordinate.
     */
    int getStartY() const;

    /**
     * @brief Get the ending X coordinate of the move.
     * @return Ending X coordinate.
     */
    int getEndX() const;

    /**
     * @brief Get the ending Y coordinate of the move.
     * @return Ending Y coordinate.
     */
    int getEndY() const;

private:
    friend class Board;
    friend class logic;
    int startX; /**< Starting X coordinate. */
    int startY; /**< Starting Y coordinate. */
    int endX;   /**< Ending X coordinate. */
    int endY;   /**< Ending Y coordinate. */
};

#endif
