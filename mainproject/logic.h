#ifndef MAINPROJECT_LOGIC_H
#define MAINPROJECT_LOGIC_H
#include "piece.h"
#include <vector>
#include "move.h"
#include "movenode.h"
#include "player.h"
#include <climits>
#include <algorithm>

class Board;
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
     * @brief Implements the Minimax algorithm to search for the best move.
     * @param board The current board state.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @return The MoveNode representing the best move found.
     */
    MoveNode MinMaxTree(Board board, int depth, bool computerPlayer);

    /**
     * @brief Finds the best move using the Minimax algorithm.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @return The best move found.
     */
    Move BestMove(int depth, bool computerPlayer,Board& board);
    /**
    * @brief Generates all possible moves for the current board state.
    * @param board The current board.
    * @return A vector containing all possible moves.
    */
    std::vector<Move> generateMoves(Board& board);

    /**
     * @brief Minimax algorithm to evaluate the board and choose the best move.
     * @param board The current board state.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @return The evaluation score of the board.
     */
    int minimax(Board& board, int depth, bool computerPlayer);

    /**
     * @brief Executes the computer's move.
     */
    void ComputerMove(Board& board);
    /**
   * @brief Makes a move on the board.
   * @param board The current board state.
   * @param move The move to make.
   */
    static void makeMove(Board& board, const Move& move);


    Piece pieces[24];
    static constexpr int size = 8;


/**
* @brief Counts the number of possible moves for a player.
* @param player The player.
* @return The number of possible moves.
*/
    int numberofmoves(Player* player,  Board& board);

private:
    static const int depth = 5;///< Depth for the minimax algorithm.

};


#endif
