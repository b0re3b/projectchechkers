#ifndef MAINPROJECT_PARALEL_H
#define MAINPROJECT_PARALEL_H
#include "logic.h"
#include "board.h"
#include <thread>
#include <functional>

class MinimaxThread {
public:
    MinimaxThread(Board& board, int depth, int alpha, int beta, bool computerPlayer)
            : board(board), depth(depth), alpha(alpha), beta(beta), computerPlayer(computerPlayer) {}

    // Метод, який починає виконання алгоритму Мінімакса в окремому потоці
    void start() {
        thread = std::thread(&MinimaxThread::minimaxThreadFunc, this);
    }

    // Метод, який чекає на завершення виконання потоку
    void join() {
        if (thread.joinable()) {
            thread.join();
        }
    }

    // Метод, який відповідає за виконання алгоритму Мінімакса
    void minimaxThreadFunc() {

        result = minimax(board, depth, alpha, beta, computerPlayer);
    }

    // Метод, який повертає результат виконання алгоритму Мінімакса
    int getResult() const {
        return result;
    }
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
    std::thread thread; // Потік
    Board& board; // Графічне поле
    int depth; // Глибина алгоритму Мінімакса
    int alpha; // Початкове значення альфа
    int beta; // Початкове значення бета
    bool computerPlayer; // Пошук кращого ходу для комп'ютера
    int result; // Результат алгоритму Мінімакса
};

#endif
