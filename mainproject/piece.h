
#ifndef MAINPROJECT_PIECE_H
#define MAINPROJECT_PIECE_H
#include <SFML/Graphics.hpp>

class Piece {
private:
    bool isAlive;
    bool isKing;
    sf::Color color;
    int x;
    int y;

public:
    Piece(); // Constructor
    void Draw(sf::RenderWindow& window);
};
#endif //MAINPROJECT_PIECE_H
