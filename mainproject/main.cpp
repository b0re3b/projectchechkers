#include <SFML/Graphics.hpp>
#include "gameloop.h"
#include "menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Checkers");

    Menu menu(window);
    PlayerColor playerColor = menu.chooseColor();

    Player humanPlayer(sf::Color::Red); // Гравець, який вибрав колір, буде людиною
    Player computerPlayer(playerColor == PlayerColor::Red ? sf::Color::Black : sf::Color::Red); // Комп'ютер або людина, залежно від обраного кольору

    Game game(window, humanPlayer, computerPlayer);
    game.run();

    return 0;
}
