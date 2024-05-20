#include "gameloop.h"

Game::Game(sf::RenderWindow& window, Player& humanPlayer, Player& computerPlayer)
        : window(window), humanPlayer(humanPlayer), computerPlayer(computerPlayer), board(humanPlayer, computerPlayer) {}

void Game::run() {
    while (window.isOpen()) {
        window.clear();
        board.draw(window);
        board.inputdata(window);
        window.display();
    }
}
