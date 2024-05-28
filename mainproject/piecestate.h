#ifndef MAINPROJECT_PIECESTATE_H
#define MAINPROJECT_PIECESTATE_H

#include "piece.h"
#include "board.h"

/**
 * @brief The RegularState class represents the state and behavior of a regular (non-king) checkers piece.
 */
class RegularState {
public:
    /**
     * @brief Moves the piece to the specified coordinates.
     * @param piece The piece to move.
     * @param newX The new x-coordinate for the piece.
     * @param newY The new y-coordinate for the piece.
     * @param board The game board.
     */
    void move(Piece& piece, int newX, int newY, Board& board);

    /**
     * @brief Attacks another piece at the specified coordinates.
     * @param piece The piece performing the attack.
     * @param targetX The x-coordinate of the target piece.
     * @param targetY The y-coordinate of the target piece.
     * @param board The game board.
     */
    void attack(Piece& piece, int targetX, int targetY, Board& board);
};

/**
 * @brief The KingState class represents the state and behavior of a king checkers piece.
 */
class KingState {
public:
    /**
     * @brief Moves the king piece to the specified coordinates.
     * @param piece The king piece to move.
     * @param newX The new x-coordinate for the piece.
     * @param newY The new y-coordinate for the piece.
     * @param board The game board.
     */
    void move(Piece& piece, int newX, int newY, Board& board);

    /**
     * @brief Attacks another piece at the specified coordinates.
     * @param piece The king piece performing the attack.
     * @param targetX The x-coordinate of the target piece.
     * @param targetY The y-coordinate of the target piece.
     * @param board The game board.
     */
    void attack(Piece& piece, int targetX, int targetY, Board& board);
};

#endif //MAINPROJECT_PIECESTATE_H
