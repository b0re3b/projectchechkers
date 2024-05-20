#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
const int depth = 1;
enum class PlayerColor {
    Red,
    Black
};

class Player {
public:
    Player(const sf::Color color) {

    }

    enum class PlayerType {
        Human,
        Computer
    };

    sf::Color color;
    PlayerType type;

    Player(sf::Color color, PlayerType type) : color(color), type(type) {}
};

class Move {
public:
    int startX;
    int startY;
    int endX;
    int endY;

    Move() : startX(0), startY(0), endX(0), endY(0) {}

    Move(int startX, int startY, int endX, int endY)
            : startX(startX), startY(startY), endX(endX), endY(endY) {}
};

class MoveNode {
public:
    Move move;
    int score;
    std::vector<MoveNode> children;

    MoveNode(const Move& move, int score) : move(move), score(score) {}
};

class Piece {
public:
    bool isAlive;
    bool isKing;
    sf::Color color;
    int x;
    int y;

    void Draw(sf::RenderWindow& window) const;
};

class Board {
private:
    const int size = 8;
    Player redPlayer;
    Player blackPlayer;
    int selectedPieceIndex = -1;

public:

    Board(Player& red, Player& black);

    void InitializeGame(Player& redPlayer, Player& blackPlayer);
    bool validarity(const Piece& piece, int x, int y);
    void inputdata(sf::RenderWindow& window);
    void highlight(int pieceIndex, sf::RenderWindow& window, Board& board);
    int numberofmoves(Player* player);
    bool endgame();
    void draw(sf::RenderWindow& window);
    int evaluateBoard(Board& board);
    MoveNode MinMaxTree(Board& board, int depth, bool computerPlayer);
    Move BestMove(int depth, bool computerPlayer);
    bool opponentPiece(int x, int y, const sf::Color& colorToCheck);
    std::vector<Move> generateMoves(Board& board);
    int minimax(Board& board, int depth, bool computerPlayer);
    void ComputerMove();
    static int MousePosition(int mouseX, int mouseY);
    void makeMove(Board& board, const Move& move);

    Piece pieces[24];
};

#endif // BOARD_HPP
