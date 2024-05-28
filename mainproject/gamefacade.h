#include <SFML/Graphics.hpp>
#include "gameloop.h"
#include "menu.h"
#include "gameobserver.h"

/**
 * @brief Class representing the main game facade.
 */
class GameFacade {
private:
    sf::RenderWindow window; /**< SFML RenderWindow object for the game window. */
    Menu menu; /**< Menu object for player color selection. */

public:

    /**
     * @brief Constructs a GameFacade object.
     */
    GameFacade() : window(sf::VideoMode(600, 600), "Checkers"), menu(window) {}

    /**
     * @brief Runs the game.
     */
    void runGame() {

        Player playerColor = menu.chooseColor();
        Player humanPlayer(playerColor.getColor(), Player::PlayerType::Human);
        Player opponent(playerColor.getColor() == sf::Color::Red ? sf::Color::Black : sf::Color::Red, Player::PlayerType::Computer);


        GameObserver observer(Board, sf::Window);


        Game game(window,  opponent, humanPlayer);
        game.run();
    }
};


