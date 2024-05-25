#ifndef MAINPROJECT_PLAYER_H
#define MAINPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>

/**
 * @brief Class representing a player in the game.
 */
class Player {
public:
    /**
     * @brief Enumeration representing the type of player.
     */
    enum class PlayerType {
        Human,      /**< Human player */
        Computer    /**< Computer player */
    };

    /**
     * @brief Constructor for Player class with default type as Human.
     * @param color The color of the player.
     */
    Player(const sf::Color color);

    /**
     * @brief Constructor for Player class.
     * @param color The color of the player.
     * @param type The type of the player.
     */
    Player(sf::Color color, PlayerType type);

    /**
     * @brief Getter function for the color of the player.
     * @return The color of the player.
     */
    sf::Color getColor() const { return color; }

    PlayerType type;
private:
    friend class Board;
    friend class logic;
    sf::Color color;    /**< The color of the player. */
    /**< The type of the player. */
};

#endif // MAINPROJECT_PLAYER_H
