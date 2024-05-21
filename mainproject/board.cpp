#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
const int depth = 1;
/**
 * @brief Enumeration representing the possible colors of players.
 */
enum class PlayerColor {
    Red,    /**< Red player */
    Black   /**< Black player */
};

/**
 * @brief Class representing a player in the game.
 */
class Player {
public:
    /**
     * @brief Constructor for Player class.
     * @param color The color of the player.
     */
    Player(const sf::Color color) {}

    /**
     * @brief Enumeration representing the type of player.
     */
    enum class PlayerType {
        Human,      /**< Human player */
        Computer    /**< Computer player */
    };

    sf::Color color;    /**< The color of the player. */
    PlayerType type;    /**< The type of the player. */

    /**
     * @brief Constructor for Player class.
     * @param color The color of the player.
     * @param type The type of the player.
     */
    Player(sf::Color color, PlayerType type) : color(color), type(type) {}
};

/**
 * @brief Structure representing a move in the game.
 */
class Move {
public:
    int startX; /**< The starting X-coordinate of the move. */
    int startY; /**< The starting Y-coordinate of the move. */
    int endX;   /**< The ending X-coordinate of the move. */
    int endY;   /**< The ending Y-coordinate of the move. */

    /**
     * @brief Default constructor for Move class.
     */
    Move() : startX(0), startY(0), endX(0), endY(0) {}

    /**
     * @brief Constructor for Move class.
     * @param startX The starting X-coordinate of the move.
     * @param startY The starting Y-coordinate of the move.
     * @param endX The ending X-coordinate of the move.
     * @param endY The ending Y-coordinate of the move.
     */
    Move(int startX, int startY, int endX, int endY)
            : startX(startX), startY(startY), endX(endX), endY(endY) {}
};

/**
 * @brief Node representing a move in the move tree.
 */
class MoveNode {
public:
    Move move;      /**< The move. */
    int score;      /**< The score associated with the move. */
    std::vector<MoveNode> children; /**< The children of the move node. */

    /**
     * @brief Constructor for MoveNode class.
     * @param move The move.
     * @param score The score associated with the move.
     */
    MoveNode(const Move& move, int score) : move(move), score(score) {}
};

/**
 * @brief Class representing a piece on the board.
 */
class Piece {
public:
    bool isAlive;   /**< Indicates if the piece is alive. */
    bool isKing;    /**< Indicates if the piece is a king. */
    sf::Color color;    /**< The color of the piece. */
    int x;  /**< The X-coordinate of the piece. */
    int y;  /**< The Y-coordinate of the piece. */

    /**
     * @brief Method to draw the piece on the window.
     * @param window The SFML window to draw the piece on.
     */
    void Draw(sf::RenderWindow& window) const;
};

/**
 * @brief Class representing the game board.
 */
class Board {
private:
    const int size = 8; /**< The size of the board. */
    /**< The black player. */
    int selectedPieceIndex = -1;    /**< The index of the selected piece on the board. */

public:

    /**
     * @brief Constructor for Board class.
     * @param red The red player.
     * @param black The black player.
     */
    Board(Player &red, Player &black);

    /**
     * @brief Initializes the game.
     * @param redPlayer The red player.
     * @param blackPlayer The black player.
     */
    void InitializeGame(Player &redPlayer, Player &blackPlayer);

    /**
     * @brief Checks the validity of a move.
     * @param piece The piece to be moved.
     * @param x The target X-coordinate.
     * @param y The target Y-coordinate.
     * @return True if the move is valid, false otherwise.
     */
    bool validarity(const Piece &piece, int x, int y);

    /**
     * @brief Handles user input during the game.
     * @param window The SFML window.
     */
    void inputdata(sf::RenderWindow &window);

/**
 * @brief Highlights valid moves for a selected piece.
 * @param pieceIndex The index of the selected piece.
 * @param window The SFML window.
 * @param board The game board instance.
*/
    void highlight(int pieceIndex, sf::RenderWindow &window, Board &board);

    /**
 * @brief Calculates the number of possible moves for a player.
 * @param player The player for whom to calculate the moves.
 * @return The number of possible moves.
 */
    int numberofmoves(Player *player);

/**
 * @brief Checks if the game has ended.
 * @return True if the game has ended, false otherwise.
 */
    bool endgame();

/**
 * @brief Draws the game board on the SFML window.
 * @param window The SFML window.
 */
    void draw(sf::RenderWindow &window);

/**
 * @brief Evaluates the current state of the board.
 * @param board The game board.
 * @return The evaluation score of the board.
 */
    int evaluateBoard(Board &board);

/**
 * @brief Constructs the minimax tree for the game board.
 * @param board The game board.
 * @param depth The depth of the tree.
 * @param computerPlayer Indicates if the current player is the computer.
 * @return The root node of the minimax tree.
 */
    MoveNode MinMaxTree(Board &board, int depth, bool computerPlayer);

/**
 * @brief Finds the best move for the current player using minimax algorithm.
 * @param depth The depth of the minimax search.
 * @param computerPlayer Indicates if the current player is the computer.
 * @return The best move.
 */
    Move BestMove(int depth, bool computerPlayer);

/**
 * @brief Checks if a piece of the opponent exists at a given position.
 * @param x The X-coordinate of the position.
 * @param y The Y-coordinate of the position.
 * @param colorToCheck The color of the current player.
 * @return True if an opponent's piece exists at the position, false otherwise.
 */
    bool opponentPiece(int x, int y, const sf::Color &colorToCheck);

/**
 * @brief Generates all possible moves for the current player.
 * @param board The game board.
 * @return A vector containing all possible moves.
 */
    std::vector<Move> generateMoves(Board &board);

/**
 * @brief Implements the minimax algorithm to find the optimal move.
 * @param board The game board.
 * @param depth The depth of the minimax search.
 * @param computerPlayer Indicates if the current player is the computer.
 * @return The evaluation score of the current board state.
 */
    int minimax(Board &board, int depth, bool computerPlayer);

/**
 * @brief Executes the computer's move.
 */
    void ComputerMove();

/**
 * @brief Converts mouse coordinates to board indices.
 * @param mouseX The X-coordinate of the mouse.
 * @param mouseY The Y-coordinate of the mouse.
 * @return The index of the piece on the board.
 */
    static int MousePosition(int mouseX, int mouseY);

/**
 * @brief Makes a move on the game board.
 * @param board The game board.
 * @param move The move to be made.
 */
    void makeMove(Board &board, const Move &move);

    Piece pieces[24];  /**< Array containing all pieces on the board. */

    Player redPlayer;
/**< The red player. */
Player blackPlayer;
};
#endif
