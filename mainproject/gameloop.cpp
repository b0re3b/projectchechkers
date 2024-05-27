/**
 * @file game.cpp
 * @brief Implementation of the Game class, which manages the core gameplay loop.
 */

#include "gameloop.h"

/**
 * @brief Constructs a Game object.
 *
 * Initializes a Game instance, associating it with a RenderWindow, two Player objects (human and computer), and a Board to manage the game state.
 *
 * @param window The SFML RenderWindow used for rendering the game.
 * @param humanPlayer The Player object representing the human player.
 * @param computerPlayer The Player object representing the computer player.
 */
Game::Game(sf::RenderWindow& window, Player& humanPlayer, Player& computerPlayer)
        : window(window), humanPlayer(humanPlayer), computerPlayer(computerPlayer), board(humanPlayer, computerPlayer) {}
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
                    notify();
                    if (redPlayer.color == sf::Color::Black || blackPlayer.color == sf::Color::Black) {
                        gameLogic.ComputerMove(*this);
                        notify();
                    }
                }
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                if (blackPlayer.color == sf::Color::Black) {
                    gameLogic.ComputerMove(*this);
                    notify();
                }
            }
        }
    }
}
/**
 * @brief Runs the main game loop.
 *
 * This function handles the continuous cycle of the game:
 * 1. Clears the window to prepare for rendering.
 * 2. Draws the current state of the board onto the window.
 * 3. Collects input from the player through the window.
 * 4. Displays the updated window contents on the screen.
 *
 * The loop continues until the window is closed.
 */
void Game::run() {
    while (window.isOpen()) {
        window.clear();
        board.draw(window);
        board.inputdata(window);
        window.display();
    }
}
