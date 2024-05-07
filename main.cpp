#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
enum class PlayerColor {
    Red,
    Black
};

class Player {
public:
    sf::Color color;

    Player(sf::Color color) : color(color) {}
};

const int depth = 1;
using namespace std;

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

    void Draw(sf::RenderWindow& window) {

        if (isAlive) {
            sf::CircleShape shape(30.f);
            shape.setFillColor(color);

            if (isKing) {
                shape.setOutlineThickness(3.f);
                shape.setOutlineColor(sf::Color::Yellow);
            }

            shape.setPosition(sf::Vector2f(x * 75 + (75 - 2 * 30) / 2, y * 75 + (75 - 2 * 30) / 2));
            window.draw(shape);
        }
    }
};

class Board {
private:
    const int size = 8;
    Piece pieces[24];
    Player redPlayer;
    Player blackPlayer;
    int selectedPieceIndex = -1;

public:
    Player& getRedPlayer() {
        return redPlayer;
    }
    Player& getBlackPlayer() {
        return blackPlayer;
    }
    Board(Player& red, Player& black) : redPlayer(red), blackPlayer(black) {
        InitializeGame(redPlayer, blackPlayer);
    }

    void InitializeGame(Player& redPlayer, Player& blackPlayer) {
        int redIndex = 0;
        int blackIndex = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if ((i + j) % 2 == 0) {
                    if (i <= 2) {
                        pieces[redIndex].isAlive = true;
                        pieces[redIndex].color = sf::Color::Red;
                        pieces[redIndex].x = j;
                        pieces[redIndex].y = i;
                        redIndex++;
                    } else if (i >= 5) {
                        pieces[blackIndex + 12].isAlive = true;
                        pieces[blackIndex + 12].color = sf::Color::Black;
                        pieces[blackIndex + 12].x = j;
                        pieces[blackIndex + 12].y = i;
                        blackIndex++;
                    }
                }
            }
        }

        redPlayer.color = sf::Color::Red;
        blackPlayer.color = sf::Color::Black;
    }

    bool validarity(const Piece& piece, int x, int y) {
        if (!piece.isAlive) {
            return false;
        }

        if (x < 0 || x >= size || y < 0 || y >= size) {
            return false;
        }

        if (pieces[y * size + x].isAlive) {
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

    void inputdata(sf::RenderWindow& window) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int clickedPieceIndex = MousePosition(mousePos.x, mousePos.y);

                    if (clickedPieceIndex != -1 && pieces[clickedPieceIndex].isAlive &&
                        pieces[clickedPieceIndex].color == sf::Color::Black) {
                        selectedPieceIndex = clickedPieceIndex;
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    int newX = mousePos.x / 75;
                    int newY = mousePos.y / 75;

                    if (selectedPieceIndex != -1 && validarity(pieces[selectedPieceIndex], newX, newY)) {
                        makeMove(*this, Move(pieces[selectedPieceIndex].x, pieces[selectedPieceIndex].y, newX, newY));
                        selectedPieceIndex = -1;

                        if (redPlayer.color == sf::Color::Black || blackPlayer.color == sf::Color::Black) {
                            ComputerMove();
                        }
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    if (blackPlayer.color == sf::Color::Black) {
                        ComputerMove();
                    }
                }
            }
        }
    }

    void highlight(int pieceIndex, sf::RenderWindow& window, Board& board) {
        Piece& selectedPiece = pieces[pieceIndex];

        int selectedX = selectedPiece.x;
        int selectedY = selectedPiece.y;

        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {

                int targetX = selectedX + i;
                int targetY = selectedY + j;

                if (validarity(selectedPiece, targetX, targetY)) {

                    sf::RectangleShape highlight(sf::Vector2f(75.f, 75.f));
                    highlight.setPosition(sf::Vector2f(targetX * 75, targetY * 75));
                    highlight.setFillColor(sf::Color::Green);
                    window.draw(highlight);
                }
            }
        }

        sf::RectangleShape highlight(sf::Vector2f(75.f, 75.f));
        highlight.setPosition(sf::Vector2f(selectedX * 75, selectedY * 75));
        highlight.setFillColor(sf::Color::Yellow);
        window.draw(highlight);
    }

    int numberofmoves(Player* player) {
        int count = 0;

        for (int i = 0; i < 24; i++) {
            if (pieces[i].isAlive && pieces[i].color == player->color) {
                for (int j = 0; j < size; j++) {
                    for (int k = 0; k < size; k++) {
                        if (validarity(pieces[i], j, k)) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
    bool endgame() {
        bool redPiecesLeft = false;
        bool blackPiecesLeft = false;

        for (const Piece& piece : pieces) {
            if (piece.isAlive) {
                if (piece.color == sf::Color::Red) {
                    redPiecesLeft = true;
                } else if (piece.color == sf::Color::Black) {
                    blackPiecesLeft = true;
                }
            }
        }

        return !redPiecesLeft || !blackPiecesLeft;
    }


    void draw(sf::RenderWindow& window) {
        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(75.f, 75.f));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tile.setPosition(sf::Vector2f(75 * i, 75 * j));

                if ((i + j) % 2 == 0) {
                    tile.setFillColor(sf::Color::White);
                } else {
                    tile.setFillColor(sf::Color::Black);
                }

                window.draw(tile);
            }
        }

        for (auto & piece : pieces) {
            if (piece.isAlive) {
                piece.Draw(window);
            }
        }
    }

    int evaluateBoard(Board& board) {
        int redPieces = 0;
        int blackPieces = 0;
        int redKings = 0;
        int blackKings = 0;

        for (const Piece& piece : pieces) {
            if (piece.isAlive) {
                if (piece.color == sf::Color::Red) {
                    redPieces++;
                    if (piece.isKing) {
                        redKings++;
                    }
                } else if (piece.color == sf::Color::Black) {
                    blackPieces++;
                    if (piece.isKing) {
                        blackKings++;
                    }
                }
            }
        }

        int redScore = redPieces + 2 * redKings;
        int blackScore = blackPieces + 2 * blackKings;

        return redScore - blackScore;
    }

    MoveNode MinMaxTree(Board& board, int depth, bool computerPlayer) {
        if (depth == 0 || endgame()) {
            int evaluation = evaluateBoard(board);
            return MoveNode(Move(), evaluation);
        }

        std::vector<Move> possibleMoves = generateMoves(board);

        MoveNode bestMoveNode(Move(), computerPlayer ? INT_MIN : INT_MAX);

        for (Move move : possibleMoves) {
            Board tempBoard = board;
            makeMove(tempBoard, move);

            MoveNode childNode = MinMaxTree(tempBoard, depth - 1, !computerPlayer);
            childNode.move = move;

            if (computerPlayer) {
                if (childNode.score > bestMoveNode.score) {
                    bestMoveNode = childNode;
                }
            } else {
                if (childNode.score < bestMoveNode.score) {
                    bestMoveNode = childNode;
                }
            }
        }

        return bestMoveNode;
    }

    Move BestMove(int depth, bool computerPlayer) {
        MoveNode root = MinMaxTree(*this, depth, computerPlayer);
        return root.move;
    }

    bool opponentPiece(int x, int y, const sf::Color& colorToCheck) {
        Piece& piece = pieces[y * size + x];
        return piece.isAlive && piece.color != colorToCheck && piece.color == sf::Color::Black;
    }

    std::vector<Move> generateMoves(Board& board) {
        std::vector<Move> possibleMoves;

        for (const Piece& piece : pieces) {
            if (piece.isAlive && piece.color == board.redPlayer.color) {
                int x = piece.x;
                int y = piece.y;

                if (piece.color == sf::Color::Red || piece.isKing) {
                    if (opponentPiece(x + 1, y + 1, piece.color) && validarity(piece, x + 2, y + 2)) {
                        possibleMoves.emplace_back(x, y, x + 2, y + 2);
                    }

                    if (opponentPiece(x - 1, y + 1, piece.color) && validarity(piece, x - 2, y + 2)) {
                        possibleMoves.emplace_back(x, y, x - 2, y + 2);
                    }
                }

                if (piece.color == sf::Color::Black || piece.isKing) {
                    if (opponentPiece(x + 1, y - 1, piece.color) && validarity(piece, x + 2, y - 2)) {
                        possibleMoves.emplace_back(x, y, x + 2, y - 2);
                    }

                    if (opponentPiece(x - 1, y - 1, piece.color) && validarity(piece, x - 2, y - 2)) {
                        possibleMoves.emplace_back(x, y, x - 2, y - 2);
                    }
                }
            }
        }

        return possibleMoves;
    }

    int minimax(Board& board, int depth, bool computerPlayer) {
        if (depth == 0 || endgame()) {
            return evaluateBoard(board);
        }

        std::vector<Move> possibleMoves = generateMoves(board);

        if (computerPlayer) {
            int maxEval = INT_MIN;
            for (Move move : possibleMoves) {
                makeMove(board, move);
                int eval = minimax(board, depth - 1, false);
                maxEval = std::max(maxEval, eval);
            }
            return maxEval;
        } else {
            int minEval = INT_MAX;
            for (Move move : possibleMoves) {
                makeMove(board, move);
                int eval = minimax(board, depth - 1, true);
                minEval = std::min(minEval, eval);
            }
            return minEval;
        }
    }

    void ComputerMove() {
        int bestMoveIndex = -1;
        int bestMoveScore = INT_MIN;
        std::vector<Move> possibleMoves = generateMoves(*this);

        for (int i = 0; i < possibleMoves.size(); ++i) {
            Move currentMove = possibleMoves[i];

            Board tempBoard = *this;
            makeMove(tempBoard, currentMove);

            int moveScore = minimax(tempBoard, depth, false);

            if (moveScore > bestMoveScore) {
                bestMoveScore = moveScore;
                bestMoveIndex = i;
            }
        }

        if (bestMoveIndex != -1) {
            makeMove(*this, possibleMoves[bestMoveIndex]);
        }
    }

    int MousePosition(int mouseX, int mouseY) {

        if (mouseX < 0 || mouseX > 600 || mouseY < 0 || mouseY > 600) {
            return -1;
        }

        int col = mouseX / 75;
        int row = mouseY / 75;

        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
            int pieceIndex = row * 8 + col;
            return pieceIndex;
        } else {
            return -1;
        }
    }

    void makeMove(Board& board, const Move& move) {
        int startX = move.startX;
        int startY = move.startY;
        int endX = move.endX;
        int endY = move.endY;

        Piece& startPiece = pieces[startY * size + startX];
        Piece& endPiece = pieces[endY * size + endX];

        if (startPiece.isAlive) {
            endPiece = startPiece;
            endPiece.x = endX;
            endPiece.y = endY;

            startPiece.isAlive = false;

            if (endY == 0 || endY == 7) {
                endPiece.isKing = true;
            }
        }
    }
};

class Menu {
private:
    sf::RenderWindow& window;

public:
    Menu(sf::RenderWindow& window) : window(window) {}

    PlayerColor chooseColor() {
        sf::Font font;
        if (!font.loadFromFile("ArialMT.ttf")) {
            std::cerr << "Font file not found!" << std::endl;
        }

        sf::Text text;
        text.setFont(font);
        text.setString("Choose your color:");
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::White);
        text.setPosition(100, 150);

        sf::Text redText;
        redText.setFont(font);
        redText.setString("Red");
        redText.setCharacterSize(30);
        redText.setFillColor(sf::Color::Red);
        redText.setPosition(100, 250);

        sf::Text blackText;
        blackText.setFont(font);
        blackText.setString("Black");
        blackText.setCharacterSize(30);
        blackText.setFillColor(sf::Color::Black);
        blackText.setPosition(100, 300);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (redText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        return PlayerColor::Red;
                    }
                    if (blackText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        return PlayerColor::Black;
                    }
                }
            }
            window.clear();
            window.draw(text);
            window.draw(redText);
            window.draw(blackText);
            window.display();
        }
        return PlayerColor::Red;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Checkers");

    Menu menu(window);
    PlayerColor playerColor = menu.chooseColor();

    Player humanPlayer(playerColor == PlayerColor::Red ? sf::Color::Red : sf::Color::Black);
    Player computerPlayer(playerColor == PlayerColor::Red ? sf::Color::Black : sf::Color::Red);

    Board board(humanPlayer, computerPlayer);

    while (window.isOpen()) {
        window.clear();
        board.draw(window);
        board.inputdata(window);
        window.display();
    }

    return 0;
}