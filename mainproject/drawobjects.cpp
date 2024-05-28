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

    sf::Text text, redText, blackText, easyText, mediumText, hardText; // Додамо текстові об'єкти для вибору рівня складності

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

    easyText.setFont(font); // Текст для легкого рівня складності
    easyText.setString("Easy");
    easyText.setCharacterSize(30);
    easyText.setFillColor(sf::Color::White);
    easyText.setPosition(100, 300);

    mediumText.setFont(font); // Текст для середнього рівня складності
    mediumText.setString("Medium");
    mediumText.setCharacterSize(30);
    mediumText.setFillColor(sf::Color::White);
    mediumText.setPosition(100, 350);

    hardText.setFont(font); // Текст для важкого рівня складності
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

                // Перевірка, чи обрано червоний колір
                if (redText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red);
                }

                // Перевірка, чи обрано чорний колір
                if (blackText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Black);
                }

                // Перевірка, чи обрано легкий рівень складності
                if (easyText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red, 1); // Повертаємо об'єкт гравця з обраним кольором і рівнем складності
                }

                // Перевірка, чи обрано середній рівень складності
                if (mediumText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red, 5); // Повертаємо об'єкт гравця з обраним кольором і рівнем складності
                }

                // Перевірка, чи обрано важкий рівень складності
                if (hardText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    return Player(sf::Color::Red, 10); // Повертаємо об'єкт гравця з обраним кольором і рівнем складності
                }
            }
        }

        window.clear(sf::Color::Green);
        window.draw(text);
        window.draw(redText);
        window.draw(blackText);
        window.draw(easyText); // Виводимо текст для легкого рівня складності
        window.draw(mediumText); // Виводимо текст для середнього рівня складності
        window.draw(hardText); // Виводимо текст для важкого рівня складності
        window.display();
    }

    return Player(sf::Color::Red); // Повертаємо об'єкт гравця з червоним кольором за замовчуванням
}

