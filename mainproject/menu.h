#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "player.h"

/**
 * @brief Class representing the game menu for player color selection.
 */
class Menu {
public:
    /**
     * @brief Constructs a Menu object.
     * @param window Reference to the SFML RenderWindow object.
     */
    Menu(sf::RenderWindow& window);

    /**
     * @brief Displays a menu for the player to choose their color.
     * @return Player object with the chosen color.
     */
    Player chooseColor();

private:
    sf::RenderWindow& window; /**< Reference to the SFML RenderWindow object. */
};

#endif // MENU_H
