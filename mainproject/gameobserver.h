#ifndef MAINPROJECT_GAMEOBSERVER_H
#define MAINPROJECT_GAMEOBSERVER_H

#include "observer.h"
#include "board.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Class representing a game observer.
 *
 * This class observes changes in the game board and updates the window accordingly.
 */
class GameObserver : public Observer {
private:
    Board& board; /**< Reference to the game board. */
    sf::RenderWindow& window; /**< Reference to the SFML RenderWindow object. */

public:
    /**
     * @brief Constructs a GameObserver object.
     *
     * @param board Reference to the game board.
     * @param window Reference to the SFML RenderWindow object.
     */
    GameObserver(Board& board, sf::RenderWindow& window) : board(board), window(window) {
        board.attach(this);
    }

    /**
     * @brief Destroys the GameObserver object.
     */
    ~GameObserver() {
        board.detach(this);
    }

    /**
     * @brief Updates the window when changes occur in the game board.
     */
    void update() override {
        window.clear();
        board.draw(window);
        window.display();
    }
};

#endif // MAINPROJECT_GAMEOBSERVER_H
