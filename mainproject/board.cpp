#include "board.h"

/**
 * @brief Constructor for the Board class.
 * @param red The red player.
 * @param black The black player.
 */
Board::Board(Player& red, Player& black) : redPlayer(red), blackPlayer(black) {
    InitializeGame(redPlayer, blackPlayer);
}

/**
 * @brief Initializes the game board with pieces.
 * @param redPlayer The red player.
 * @param blackPlayer The black player.
 */
void Board::InitializeGame(Player& redPlayer, Player& blackPlayer) {
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

/**
 * @brief Checks if there is a piece at the given coordinates.
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
 * @brief Checks the validity of a move for a given piece.
 * @param piece The piece to check the move for.
 * @param x The x-coordinate of the destination.
 * @param y The y-coordinate of the destination.
 * @return True if the move is valid, false otherwise.
 */
bool Board::validarity(const Piece& piece, int x, int y) {
    if (!piece.isAlive || x < 0 || x >= size || y < 0 || y >= size || pieces[y * size + x].isAlive) {
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
 * @brief Handles player input for moving pieces.
 * @param window The SFML window.
 */
void Board::inputdata(sf::RenderWindow& window) {
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
                    highlight(selectedPieceIndex, window, *this); // Highlight the selected piece
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

/**
 * @brief Highlights the possible moves for a selected piece.
 * @param pieceIndex The index of the selected piece.
 * @param window The SFML window.
 * @param board The game board.
 */
void Board::highlight(int pieceIndex, sf::RenderWindow& window, Board& board) {
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

/**
 * @brief Counts the number of possible moves for a player.
 * @param player The player.
 * @return The number of possible moves.
 */
int Board::numberofmoves(Player* player) {
    int count = 0;

    for (int i = 0; i < 24; i++) {
        if (pieces[i].isAlive && pieces[i].color == player->color) {
            count += generateMoves(*this).size();
        }
    }

    return count;
}

/**
 * @brief Checks if the game has ended.
 * @return True if the game has ended, false otherwise.
 */
bool Board::endgame() {
    return numberofmoves(&redPlayer) == 0 || numberofmoves(&blackPlayer) == 0;
}

/**
 * @brief Draws the board and pieces on the SFML window.
 * @param window The SFML window.
 */
void Board::draw(sf::RenderWindow& window) {
    window.clear();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sf::RectangleShape square(sf::Vector2f(75.f, 75.f));
            square.setPosition(j * 75, i * 75);

            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color::White);
            } else {
                square.setFillColor(sf::Color::Black);
            }

            window.draw(square);
        }
    }

    for (int i = 0; i < 24; i++) {
        pieces[i].Draw(window);
    }

    window.display();
}

/**
 * @brief Evaluates the board for the Minimax algorithm.
 * @param board The game board.
 * @return The evaluated score.
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
 * @brief Generates the Minimax tree and returns the best move.
 * @param board The game board.
 * @param depth The depth of the tree.
 * @param computerPlayer True if the computer is playing, false otherwise.
 * @return The best move.
 */
MoveNode Board::MinMaxTree(Board& board, int depth, bool computerPlayer) {
    if (depth == 0 || board.endgame()) {
        return MoveNode(Move(), evaluateBoard(board));
    }

    std::vector<Move> moves = generateMoves(board);

    if (moves.empty()) {
        return MoveNode(Move(), computerPlayer ? INT_MIN : INT_MAX);
    }

    Move bestMove;
    int bestScore = computerPlayer ? INT_MIN : INT_MAX;

    for (const Move& move : moves) {
        Board newBoard = board;
        makeMove(newBoard, move);
        int score = MinMaxTree(newBoard, depth - 1, !computerPlayer).score;

        if (computerPlayer) {
            if (score > bestScore) {
                bestScore = score;
                bestMove = move;
            }
        } else {
            if (score < bestScore) {
                bestScore = score;
                bestMove = move;
            }
        }
    }

    return MoveNode(bestMove, bestScore);
}

/**
 * @brief Determines the best move for the computer player.
 * @param depth The depth of the Minimax algorithm.
 * @param computerPlayer True if the computer is playing, false otherwise.
 * @return The best move.
 */
Move Board::BestMove(int depth, bool computerPlayer) {
    return MinMaxTree(*this, depth, computerPlayer).move;
}

/**
 * @brief Checks if there is an opponent piece at the given coordinates.
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
 * @brief Generates possible moves for all pieces on the board.
 * @param board The game board.
 * @return A vector of possible moves.
 */
std::vector<Move> Board::generateMoves(Board& board) {
    std::vector<Move> moves;

    for (int i = 0; i < 24; i++) {
        Piece& piece = board.pieces[i];

        if (piece.isAlive) {
            for (int dx = -1; dx <= 1; dx += 2) {
                for (int dy = -1; dy <= 1; dy += 2) {
                    int newX = piece.x + dx;
                    int newY = piece.y + dy;

                    if (validarity(piece, newX, newY)) {
                        moves.push_back(Move(piece.x, piece.y, newX, newY));
                    }
                }
            }
        }
    }

    return moves;
}

/**
 * @brief Implements the Minimax algorithm for move selection.
 * @param board The game board.
 * @param depth The depth of the Minimax algorithm.
 * @param computerPlayer True if the computer is playing, false otherwise.
 * @return The score of the board state.
 */
int Board::minimax(Board& board, int depth, bool computerPlayer) {
    if (depth == 0 || board.endgame()) {
        return evaluateBoard(board);
    }

    std::vector<Move> moves = generateMoves(board);

    if (computerPlayer) {
        int maxEval = INT_MIN;
        for (const Move& move : moves) {
            Board newBoard = board;
            makeMove(newBoard, move);
            int eval = minimax(newBoard, depth - 1, false);
            maxEval = std::max(maxEval, eval);
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (const Move& move : moves) {
            Board newBoard = board;
            makeMove(newBoard, move);
            int eval = minimax(newBoard, depth - 1, true);
            minEval = std::min(minEval, eval);
        }
        return minEval;
    }
}

/**
 * @brief Executes the computer's move.
 */
void Board::ComputerMove() {
    Move bestMove = BestMove(depth, true);
    makeMove(*this, bestMove);
}

/**
 * @brief Gets the index of the piece at the given mouse coordinates.
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

/**
 * @brief Makes a move on the board.
 * @param board The game board.
 * @param move The move to make.
 */
void Board::makeMove(Board& board, const Move& move) {
    Piece& piece = board.pieces[move.startY * size + move.startX];
    piece.x = move.endX;
    piece.y = move.endY;

    if ((piece.color == sf::Color::Red && piece.y == size - 1) ||
        (piece.color == sf::Color::Black && piece.y == 0)) {
        piece.isKing = true;
    }

    board.pieces[move.startY * size + move.startX].isAlive = false;
    board.pieces[move.endY * size + move.endX] = piece;
}
