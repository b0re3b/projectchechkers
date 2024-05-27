/**
 * @file piecestate.h
 * @brief Header file for the PieceState class and its derived classes.
 */

#ifndef MAINPROJECT_PIECESTATE_H
#define MAINPROJECT_PIECESTATE_H

#include "piece.h"

class Board;
class Piece;

/**
 * @brief Abstract base class for defining the state of a piece.
 */
class PieceState {
public:
    /**
     * @brief Virtual method to handle moving the piece.
     * @param piece The piece to be moved.
     * @param newX The new x-coordinate of the piece.
     * @param newY The new y-coordinate of the piece.
     * @param board The game board.
     */
    virtual void move(Piece& piece, int newX, int newY, Board& board) = 0;

    /**
     * @brief Virtual method to handle attacking with the piece.
     * @param piece The piece to perform the attack.
     * @param targetX The x-coordinate of the target piece.
     * @param targetY The y-coordinate of the target piece.
     * @param board The game board.
     */
    virtual void attack(Piece& piece, int targetX, int targetY, Board& board) = 0;

    /**
     * @brief Virtual destructor for PieceState class.
     */
    virtual ~PieceState() = default;
};

/**
 * @brief Concrete class representing the state of a regular piece.
 */
class RegularState : public PieceState {
public:
    /**
     * @brief Method to handle moving a regular piece.
     * @param piece The regular piece to be moved.
     * @param newX The new x-coordinate of the piece.
     * @param newY The new y-coordinate of the piece.
     * @param board The game board.
     */
    virtual void move(Piece& piece, int newX, int newY, Board& board) override;

    /**
     * @brief Method to handle attacking with a regular piece.
     * @param piece The regular piece to perform the attack.
     * @param targetX The x-coordinate of the target piece.
     * @param targetY The y-coordinate of the target piece.
     * @param board The game board.
     */
    virtual void attack(Piece& piece, int targetX, int targetY, Board& board) override;
};

/**
 * @brief Concrete class representing the state of a king piece.
 */
class KingState : public PieceState {
public:
    /**
     * @brief Method to handle moving a king piece.
     * @param piece The king piece to be moved.
     * @param newX The new x-coordinate of the piece.
     * @param newY The new y-coordinate of the piece.
     * @param board The game board.
     */
    virtual void move(Piece& piece, int newX, int newY, Board& board) override;

    /**
     * @brief Method to handle attacking with a king piece.
     * @param piece The king piece to perform the attack.
     * @param targetX The x-coordinate of the target piece.
     * @param targetY The y-coordinate of the target piece.
     * @param board The game board.
     */
    virtual void attack(Piece& piece, int targetX, int targetY, Board& board) override;
};

#endif // MAINPROJECT_PIECESTATE_H
