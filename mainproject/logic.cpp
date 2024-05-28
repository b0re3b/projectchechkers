#include "logic.h"
#include "board.h"
#include "thread"
#include "paralel.h"

/**
 * @brief Checks the validity of a move for a given piece.
 * @param piece The piece to check the move for.
 * @param x The x-coordinate of the destination.
 * @param y The y-coordinate of the destination.
 * @return True if the move is valid, false otherwise.
 */
bool logic::validarity(const Piece& piece, int x, int y) {
    if (!piece.isAlive || x < 0 || x >= size || y < 0 || y >= size ||
        std::find_if(std::begin(pieces), std::end(pieces), [&](const Piece& p) {
            return p.isAlive && p.x == x && p.y == y;
        }) != std::end(pieces)) {
        return false;
    }

    if (piece.isKing) {
        return true;
    } else {
        int deltaX = x - piece.x;
        int deltaY = y - piece.y;
        return (deltaX == 1 || deltaX == -1) && (deltaY == 1 || deltaY == -1);
    }
}

/**
 * @brief Counts the number of possible moves for a player.
 * @param player The player.
 * @return The number of possible moves.
 */
int logic::numberofmoves(Player* player, Board& board) {
    return std::count_if(std::begin(pieces), std::end(pieces), [&](const Piece& p) {
        return p.isAlive && p.color == player->color && !generateMoves(board).empty();
    });
}

/**
 * @brief Determines the best move for the computer player.
 * @param depth The depth of the Minimax algorithm.
 * @param computerPlayer True if the computer is playing, false otherwise.
 * @return The best move.
 */
Move logic::BestMove(int depth, bool computerPlayer, Board& board) {
    MinimaxThread minm;
    std::vector<Move> moves = generateMoves(board);

    Move bestMove;
    int bestScore = computerPlayer ? INT_MIN : INT_MAX;

    for (const Move& move : moves) {
        Board newBoard = board;
        makeMove(newBoard, move);
        int score = minm.minimax(newBoard, depth, INT_MIN, INT_MAX, !computerPlayer);

        if ((computerPlayer && score > bestScore) || (!computerPlayer && score < bestScore)) {
            bestScore = score;
            bestMove = move;
        }
    }

    return bestMove;
}

/**
 * @brief Generates possible moves for all pieces on the board.
 * @param board The game board.
 * @return A vector of possible moves.
 */
std::vector<Move> logic::generateMoves(Board& board) {
    std::vector<Move> moves;

    for (int i = 0; i < 24; i++) {
        Piece& piece = board.pieces[i];

        if (piece.isAlive) {
            for (int dx = -1; dx <= 1; dx += 2) {
                for (int dy = -1; dy <= 1; dy += 2) {
                    int newX = piece.x + dx;
                    int newY = piece.y + dy;

                    if (validarity(piece, newX, newY)) {
                        moves.emplace_back(piece.x, piece.y, newX, newY);
                    }
                }
            }
        }
    }

    return moves;
}

/**
 * @brief Executes the computer's move.
 */
void logic::ComputerMove(Board& board) {
    Move bestMove = BestMove(EASY_DEPTH, true, board);
    makeMove(board, bestMove);
}