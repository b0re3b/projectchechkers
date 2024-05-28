#ifndef MAINPROJECT_PARALEL_H
#define MAINPROJECT_PARALEL_H

#include "logic.h"
#include "board.h"
#include <thread>
#include <functional>

/**
 * @brief The MinimaxThread class encapsulates the execution of the Minimax algorithm in a separate thread.
 */
class MinimaxThread {
public:
    /**
     * @brief Constructor for MinimaxThread.
     * @param board The game board.
     * @param depth The depth of the Minimax algorithm.
     * @param alpha The alpha value for alpha-beta pruning.
     * @param beta The beta value for alpha-beta pruning.
     * @param computerPlayer True if it's the computer's turn, false otherwise.
     */
    MinimaxThread(Board& board, int depth, int alpha, int beta, bool computerPlayer)
            : board(board), depth(depth), alpha(alpha), beta(beta), computerPlayer(computerPlayer) {}

    /**
     * @brief Starts the execution of the Minimax algorithm in a separate thread.
     */
    void start() {
        thread = std::thread(&MinimaxThread::minimaxThreadFunc, this);
    }

    /**
     * @brief Waits for the Minimax thread to finish execution.
     */
    void join() {
        if (thread.joinable()) {
            thread.join();
        }
    }

    /**
     * @brief Executes the Minimax algorithm.
     */
    void minimaxThreadFunc() {
        result = minimax(board, depth, alpha, beta, computerPlayer);
    }

    /**
     * @brief Gets the result of the Minimax algorithm.
     * @return The result of the Minimax algorithm.
     */
    int getResult() const {
        return result;
    }

/**
 * @brief Executes the Minimax algorithm.
 * @param board The game board.
 * @param depth The depth of the Minimax algorithm.
 * @param alpha The alpha value for alpha-beta pruning.
 * @param beta The beta value for alpha-beta pruning.
 * @param computerPlayer True if it's the computer's turn, false otherwise.
 * @return The score of the board state.
 */
int minimax(Board& board, int depth, int alpha, int beta, bool computerPlayer) {
    logic loogic;
    if (depth == 0 || board.endgame()) {
        return board.evaluateBoard(board);
    }

    std::vector<Move> moves = loogic.generateMoves(board);

    if (computerPlayer) {
        int maxEval = INT_MIN;
        for (const Move& move : moves) {
            Board newBoard = board;
            loogic.makeMove(newBoard, move);
            int eval = minimax(newBoard, depth - 1, alpha, beta, false);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (const Move& move : moves) {
            Board newBoard = board;
            loogic.makeMove(newBoard, move);
            int eval = minimax(newBoard, depth - 1, alpha, beta, true);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return minEval;
    }
}

private:
    std::thread thread; ///< The Minimax thread.
    Board& board;       ///< The game board.
    int depth;          ///< The depth of the Minimax algorithm.
    int alpha;          ///< The alpha value for alpha-beta pruning.
    int beta;           ///< The beta value for alpha-beta pruning.
    bool computerPlayer; ///< Indicates whether it's the computer's turn.
    int result;         ///< The result of the Minimax algorithm.

};

#endif