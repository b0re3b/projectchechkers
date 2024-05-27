#include "piecestate.h"
#include "board.h"

// Реалізація для RegularState
void RegularState::move(Piece& piece, int newX, int newY, Board& board) {
    // Логіка руху для звичайної шашки
    // Перевірка допустимості руху
    if (newX < 0 || newX >= Board::size || newY < 0 || newY >= Board::size) {
        return;
    }

    int deltaX = newX - piece.x;
    int deltaY = newY - piece.y;

    // Звичайні шашки можуть рухатися тільки на одну діагональну клітинку вперед
    if (std::abs(deltaX) == 1 && deltaY == 1 && !piece.isKing) {
        piece.x = newX;
        piece.y = newY;
    }
}

void RegularState::attack(Piece& piece, int targetX, int targetY, Board& board) {
    // Логіка атаки для звичайної шашки
    // Перевірка допустимості атаки
    if (targetX < 0 || targetX >= Board::size || targetY < 0 || targetY >= Board::size) {
        return;
    }

    int deltaX = targetX - piece.x;
    int deltaY = targetY - piece.y;

    // Звичайні шашки можуть атакувати тільки на дві діагональні клітинки вперед
    if (std::abs(deltaX) == 2 && deltaY == 2) {
        int enemyX = piece.x + deltaX / 2;
        int enemyY = piece.y + deltaY / 2;

        if (board.pieces[enemyY * Board::size + enemyX].isAlive) {
            board.pieces[enemyY * Board::size + enemyX].isAlive = false;

            piece.x = targetX;
            piece.y = targetY;
        }
    }
}

// Реалізація для KingState
void KingState::move(Piece& piece, int newX, int newY, Board& board) {
    // Логіка руху для королівської шашки
    if (newX < 0 || newX >= Board::size || newY < 0 || newY >= Board::size) {
        return;
    }

    int deltaX = newX - piece.x;
    int deltaY = newY - piece.y;

    if (std::abs(deltaX) == std::abs(deltaY)) {
        piece.x = newX;
        piece.y = newY;
    }
}

void KingState::attack(Piece& piece, int targetX, int targetY, Board& board) {
    // Логіка атаки для королівської шашки
    if (targetX < 0 || targetX >= Board::size || targetY < 0 || targetY >= Board::size) {
        return;
    }

    int deltaX = targetX - piece.x;
    int deltaY = targetY - piece.y;

    if (std::abs(deltaX) == 2 && std::abs(deltaY) == 2) {
        int enemyX = piece.x + deltaX / 2;
        int enemyY = piece.y + deltaY / 2;

        if (board.pieces[enemyY * Board::size + enemyX].isAlive) {
            board.pieces[enemyY * Board::size + enemyX].isAlive = false;

            piece.x = targetX;
            piece.y = targetY;
        }
    }
}
