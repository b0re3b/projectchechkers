#include "board.h"
#include "logic.h"

/**
 * @brief Constructor for the Board class.
 *
 * @param red The red player.
 * @param black The black player.
 */
Board::Board(Player& red, Player& black) : redPlayer(red), blackPlayer(black) {
    InitializeGame(redPlayer, blackPlayer);
}

/**
 * @brief Evaluates the current state of the board.
 *
 * @param board The board for which to compute the evaluation.
 * @return The board's evaluation score.
 */
int Board::evaluateBoard(Board& board) {
    int score = 0;

    for (int i = 0; i < 24; i++) {
        if (board.pieces[i].isAlive) {
            if (board.pieces[i].color == redPlayer.color) {
                score -= 10;
            } else if (board.pieces[i].color == blackPlayer.color) {
                score += 10;
            }
        }
    }

    return score;
}

/**
 * @brief Checks if there is a piece at the given coordinates.
 *
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 * @return True if a piece is found at the coordinates, false otherwise.
 */
bool Board::isPieceAt(int x, int y) const {
    for (const auto& piece : pieces) {
        if (piece.isAlive && piece.x == x && piece.y == y) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if the game is at its end.
 *
 * @return True if the game has ended, false otherwise.
 */
bool Board::endgame() {
    logic gameLogic;
    return gameLogic.numberofmoves(&redPlayer, *this) == 0 || gameLogic.numberofmoves(&blackPlayer, *this) == 0;
}

/**
 * @brief Checks if there is an opponent piece at the given coordinates.
 *
 * @param x The x-coordinate.
 * @param y The y-coordinate.
 * @param colorToCheck The color to check against.
 * @return True if there is an opponent piece, false otherwise.
 */
bool Board::opponentPiece(int x, int y, const sf::Color& colorToCheck) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        return false;
    }

    return pieces[y * size + x].isAlive && pieces[y * size + x].color != colorToCheck;
}

/**
 * @brief Gets the index of the piece at the given mouse coordinates.
 *
 * @param mouseX The x-coordinate of the mouse.
 * @param mouseY The y-coordinate of the mouse.
 * @return The index of the piece.
 */
int Board::MousePosition(int mouseX, int mouseY) {
    int x = mouseX / 75;
    int y = mouseY / 75;

    for (int i = 0; i < 24; i++) {
        if (pieces[i].isAlive && pieces[i].x == x && pieces[i].y == y) {
            return i;
        }
    }

    return -1;
}
