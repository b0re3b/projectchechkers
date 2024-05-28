#ifndef MAINPROJECT_LOGIC_H
#define MAINPROJECT_LOGIC_H

#include "piece.h"
#include "move.h"
#include "movenode.h"
#include "player.h"
#include "board.h"
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

/**
 * @brief The logic class encapsulates game logic operations.
 */
class logic {
public:
    /**
     * @brief Checks the validity of a move for a given piece.
     * @param piece The piece to check the move for.
     * @param x The x-coordinate of the destination.
     * @param y The y-coordinate of the destination.
     * @return True if the move is valid, false otherwise.
     */
    bool validarity(const Piece& piece, int x, int y);

    /**
     * @brief Finds the best move using the Minimax algorithm.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @param board The current game board.
     * @return The best move found.
     */
    Move BestMove(int depth, bool computerPlayer, Board& board);

    /**
     * @brief Generates all possible moves for the current board state.
     * @param board The current board.
     * @return A vector containing all possible moves.
     */
    std::vector<Move> generateMoves(Board& board);

    /**
     * @brief Executes the computer's move.
     * @param board The game board.
     */
    void ComputerMove(Board& board);

    /**
     * @brief Makes a move on the board.
     * @param board The current board state.
     * @param move The move to make.
     */
    static void makeMove(Board& board, const Move& move);

    /**
     * @brief Counts the number of possible moves for a player.
     * @param player The player.
     * @param board The game board.
     * @return The number of possible moves.
     */
    int numberofmoves(Player* player, Board& board);
    Piece pieces[24];
    static constexpr int EASY_DEPTH = 1;   ///< Depth for the minimax algorithm in easy mode.
    static constexpr int MEDIUM_DEPTH = 5; ///< Depth for the minimax algorithm in medium mode.
    static constexpr int HARD_DEPTH = 10;  ///< Depth for the minimax algorithm in hard mode.
    static constexpr int size = 8;         ///< Size of the game board.
};

#endif