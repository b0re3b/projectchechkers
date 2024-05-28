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
    Player(const sf::Color color, int difficulty = 1);

    /**
     * @brief Constructor for Player class.
     * @param color The color of the player.
     * @param type The type of the player.
     */
    Player(sf::Color color, PlayerType type, int difficulty = 1);

    /**
     * @brief Getter function for the color of the player.
     * @return The color of the player.
     */
    sf::Color getColor() const { return color; }

    /**
     * @brief Getter function for the type of the player.
     * @return The type of the player.
     */
    PlayerType getType() const { return type; }

    /**
     * @brief Setter function for the type of the player.
     * @param newType The new type of the player.
     */
    void setType(PlayerType newType) { type = newType; }

    PlayerType type;
private:
    int difficulty; /**< The difficulty level of the computer player. */
    sf::Color color; /**< The color of the player. */
    /**< The type of the player. */

    friend class Board;
    friend class logic;
};

#endif // MAINPROJECT_PLAYER_H
