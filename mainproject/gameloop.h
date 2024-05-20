#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "board.h"

class Game {
private:
    sf::RenderWindow& window;
    Board board;
    Player& humanPlayer;
    Player& computerPlayer;

public:
    Game(sf::RenderWindow& window, Player& humanPlayer, Player& computerPlayer);
    void run();
};

#endif // GAME_HPP
