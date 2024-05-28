#include "board.h"
#include "menu.h"
#include "iostream"

/**
 * @brief Draws the game board on the SFML window.
 *
 * @param window The SFML window to draw on.
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
 * @brief Highlights the possible moves for a selected piece.
 *
 * @param pieceIndex The index of the selected piece.
 * @param window The SFML window.
 * @param board The game board.
 */
void Board::highlight(int pieceIndex, sf::RenderWindow& window, Board& board) {
        logic gameLogic;
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
 * @brief Draws the piece on the SFML window.
 *
 * @param window The SFML window to draw on.
 */
void Piece::Draw(sf::RenderWindow& window) {
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

/**
 * @brief Allows the player to choose their color and difficulty level.
 *
 * @return The player's chosen color and difficulty level.
 */
Player Menu::chooseColor() {
    sf::Font font;
    if (!font.loadFromFile("/Users/bogdanresetko/Desktop/projects2024/дфддфдф/mainproject/ArialMT.ttf")) {
        std::cerr << "Font file not found!" << std::endl;
    }

    sf::Text text, redText, blackText, easyText, mediumText, hardText;

    text.setFont(font);
    text.setString("Choose your color and difficulty:");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 100);

    redText.setFont(font);
    redText.setString("Red");
    redText.setCharacterSize(30);
    redText.setFillColor(sf::Color::Red);
    redText.setPosition(100, 200);

    blackText.setFont(font);
    blackText.setString("Black");
    blackText.setCharacterSize(30);
    blackText.setFillColor(sf::Color::Black);
    blackText.setPosition(100, 250);

    easyText.setFont(font);
    easyText.setString("Easy");
    easyText.setCharacterSize(30);
    easyText.setFillColor(sf::Color::White);
    easyText.setPosition(100, 300);

    mediumText.setFont(font);
    mediumText.setString("Medium");
    mediumText.setCharacterSize(30);
    mediumText.setFillColor(sf::Color::White);
    mediumText.setPosition(100, 350);

    hardText.setFont(font);
    hardText.setString("Hard");
    hardText.setCharacterSize(30);
    hardText.setFillColor(sf::Color::White);
    hardText.setPosition(100, 400);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (redText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red);
                }

                if (blackText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Black);
                }

                if (easyText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red, 1);
                }

                if (mediumText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red, 5);
                }

                if (hardText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red, 10);
                }
            }
        }

        window.clear(sf::Color::Green);
        window.draw(text);
        window.draw(redText);
        window.draw(blackText);
        window.draw(easyText);
        window.draw(mediumText);
        window.draw(hardText);
        window.display();
    }

    return Player(sf::Color::Red);
}
