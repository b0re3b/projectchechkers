#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <limits.h>
#include "player.h"
#include "piece.h"
#include "move.h"
#include "movenode.h"

/**
 * @file board.h
 * @brief Declaration of the Board class and related structures.
 */

/**
 * @class Board
 * @brief Represents the game board and its functionality.
 */
class Board {
public:
    /**
     * @brief Constructor for the Board class.
     * @param red The red player.
     * @param black The black player.
     */
    Board(Player& red, Player& black);

    /**
     * @brief Getter for the red player.
     * @return Reference to the red player.
     */
    Player& getRedPlayer();

    /**
     * @brief Getter for the black player.
     * @return Reference to the black player.
     */
    Player& getBlackPlayer();

    /**
     * @brief Initializes the game board with pieces.
     * @param redPlayer The red player.
     * @param blackPlayer The black player.
     */
    void InitializeGame(Player& redPlayer, Player& blackPlayer);

    /**
     * @brief Checks the validity of a move for a given piece.
     * @param piece The piece to check the move for.
     * @param x The x-coordinate of the destination.
     * @param y The y-coordinate of the destination.
     * @return True if the move is valid, false otherwise.
     */
    bool validarity(const Piece& piece, int x, int y);

    /**
     * @brief Handles player input for moving pieces.
     * @param window The SFML window.
     */
    void inputdata(sf::RenderWindow& window);

    /**
     * @brief Highlights the possible moves for a selected piece.
     * @param pieceIndex The index of the selected piece.
     * @param window The SFML window.
     * @param board The game board.
     */
    void highlight(int pieceIndex, sf::RenderWindow& window, Board& board);

    /**
     * @brief Counts the number of possible moves for a player.
     * @param player The player.
     * @return The number of possible moves.
     */
    int numberofmoves(Player* player);

    /**
     * @brief Checks if the game has ended.
     * @return True if the game has ended, false otherwise.
     */
    bool endgame();

    /**
     * @brief Draws the game board and pieces on the SFML window.
     * @param window The SFML window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Evaluates the current state of the board.
     * @param board The current board.
     * @return The evaluation score of the board.
     */
    int evaluateBoard(Board& board);

    /**
     * @brief Implements the Minimax algorithm to search for the best move.
     * @param board The current board state.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @return The MoveNode representing the best move found.
     */
    MoveNode MinMaxTree(Board& board, int depth, bool computerPlayer);

    /**
     * @brief Finds the best move using the Minimax algorithm.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @return The best move found.
     */
    Move BestMove(int depth, bool computerPlayer);

    /**
     * @brief Checks if a piece at a certain position belongs to the opponent.
     * @param x The x-coordinate of the piece.
     * @param y The y-coordinate of the piece.
     * @param colorToCheck The color of the opponent.
     * @return True if the piece belongs to the opponent, false otherwise.
     */
    bool opponentPiece(int x, int y, const sf::Color& colorToCheck);

    /**
     * @brief Generates all possible moves for the current board state.
     * @param board The current board.
     * @return A vector containing all possible moves.
     */
    std::vector<Move> generateMoves(Board& board);

    /**
     * @brief Minimax algorithm to evaluate the board and choose the best move.
     * @param board The current board state.
     * @param depth The depth of the search tree.
     * @param computerPlayer Boolean indicating if it's the computer's turn.
     * @return The evaluation score of the board.
     */
    int minimax(Board& board, int depth, bool computerPlayer);

    /**
     * @brief Executes the computer's move.
     */
    void ComputerMove();

    /**
     * @brief Generates the index of the piece that was clicked by the mouse.
     * @param mouseX The x-coordinate of the mouse.
     * @param mouseY The y-coordinate of the mouse.
     * @return The index of the clicked piece.
     */
    int MousePosition(int mouseX, int mouseY);

    /**
     * @brief Makes a move on the board.
     * @param board The current board state.
     * @param move The move to make.
     */
    void makeMove(Board& board, const Move& move);

private:
    static const int size = 8;  ///< The size of the board.
    Piece pieces[24];           ///< Array of pieces on the board.
    Player& redPlayer;          ///< Reference to the red player.
    Player& blackPlayer;        ///< Reference to the black player.
    int selectedPieceIndex = -1; ///< Index of the currently selected piece.
    const int depth = 5;        ///< Depth for the minimax algorithm.
};

#endif // BOARD_HPP
