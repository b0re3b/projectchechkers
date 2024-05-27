/**
 * @file menu.cpp
 * @brief Implementation of the Menu class, which handles player color selection.
 */

#include "menu.h"
#include <iostream>

/**
 * @brief Constructs a Menu object.
 *
 * Initializes the Menu object with a reference to the SFML RenderWindow it will use for display.
 *
 * @param window Reference to the SFML RenderWindow object.
 */
Menu::Menu(sf::RenderWindow& window) : window(window) {}


