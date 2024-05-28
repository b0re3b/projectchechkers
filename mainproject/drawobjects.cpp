#include "board.h"
#include "menu.h"
#include "iostream"

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

void Piece::Draw(sf::RenderWindow& window) {
    /// Check if the piece is alive (not captured)
    if (isAlive) {
        /// Create a circle shape for the piece
        sf::CircleShape shape(30.f); /// Radius of 30 pixels
        shape.setFillColor(color);  /// Set the fill color of the piece (red or black)

        /// If the piece is a king, add a yellow outline
        if (isKing) {
            shape.setOutlineThickness(3.f);   /// Outline thickness
            shape.setOutlineColor(sf::Color::Yellow); /// Outline color
        }

        /// Calculate the position on the board and draw the shape
        shape.setPosition(sf::Vector2f(x * 75 + (75 - 2 * 30) / 2, y * 75 + (75 - 2 * 30) / 2));
        window.draw(shape);
    }
}

Player Menu::chooseColor() {

    sf::Font font;
    if (!font.loadFromFile("/Users/bogdanresetko/Desktop/projects2024/дфддфдф/mainproject/ArialMT.ttf")) {
        std::cerr << "Font file not found!" << std::endl;
    }


    sf::Text text, redText, blackText;

    text.setFont(font);
    text.setString("Choose your color:");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 150);

    redText.setFont(font);
    redText.setString("Red");
    redText.setCharacterSize(30);
    redText.setFillColor(sf::Color::Red);
    redText.setPosition(100, 250);

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


                if (redText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red);
                }


                if (blackText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Black);
                }
            }
        }


        window.clear(sf::Color::Green);
        window.draw(text);
        window.draw(redText);
        window.draw(blackText);
        window.display();
    }


    return Player(sf::Color::Red);
}