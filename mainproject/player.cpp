#include "player.h"

/**
 * @brief Constructor for Player class with default type as Human.
 * @param color The color of the player.
 */
Player::Player(const sf::Color color, int difficulty)
        : color(color), type(PlayerType::Human), difficulty(difficulty) {}

/**
 * @brief Constructor for Player class.
 * @param color The color of the player.
 * @param type The type of the player.
 */
Player::Player(sf::Color color, PlayerType type, int difficulty)
        : color(color), type(type), difficulty(difficulty) {}
