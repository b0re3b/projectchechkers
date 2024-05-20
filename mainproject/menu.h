#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "board.h"

class Menu {
private:
    sf::RenderWindow& window;

public:
    Menu(sf::RenderWindow& window);
    PlayerColor chooseColor();
};

#endif // MENU_HPP
