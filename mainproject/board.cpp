#include "board.h"
#include "logic.h"
/**
 * @brief Constructor for the Board class.
 * @param red The red player.
 * @param black The black player.
 */
Board::Board(Player& red, Player& black) : redPlayer(red), blackPlayer(black), gameLogic() {
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
bool Board::endgame() {
    return gameLogic.numberofmoves(&redPlayer, *this) == 0 || gameLogic.numberofmoves(&blackPlayer, *this) == 0;
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

                if (selectedPieceIndex != -1 && gameLogic.validarity(pieces[selectedPieceIndex], newX, newY)) {
                    logic::makeMove(*this, Move(pieces[selectedPieceIndex].x, pieces[selectedPieceIndex].y, newX, newY));
                    selectedPieceIndex = -1;

                    if (redPlayer.color == sf::Color::Black || blackPlayer.color == sf::Color::Black) {
                        gameLogic.ComputerMove(*this);
                    }
                }
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                if (blackPlayer.color == sf::Color::Black) {
                    gameLogic.ComputerMove(*this);
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

            if (gameLogic.validarity(selectedPiece, targetX, targetY)) {

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
