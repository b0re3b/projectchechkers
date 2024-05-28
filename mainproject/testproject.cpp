/**
 * @file test.cpp
 * @brief Contains unit tests for various classes and functionalities.
 */

#include <gtest/gtest.h>
#include "movenode.h"
#include "player.h"
#include "piece.h"
#include "menu.h"
#include "board.h"
#include "logic.h"
#include "paralel.h"

/**
 * @brief Test fixture for testing the Board class.
 */
class BoardTest : public ::testing::Test {
protected:
    Board board; ///< The board object for testing.
};

/**
 * @brief Test fixture for testing the MinimaxThread class.
 */
class MinimaxThreadTest : public ::testing::Test {
protected:
    /**
     * @brief Sets up the test fixture.
     * Initializes parameters for testing.
     */
    void SetUp() override {
        depth = 4;
        alpha = INT_MIN;
        beta = INT_MAX;
        computerPlayer = true;
    }

    /**
     * @brief Tears down the test fixture.
     * Cleans up resources if needed.
     */
    void TearDown() override {}

    Board testBoard; ///< The test board.
    int depth; ///< Depth parameter for Minimax.
    int alpha; ///< Alpha parameter for alpha-beta pruning.
    int beta; ///< Beta parameter for alpha-beta pruning.
    bool computerPlayer; ///< Flag indicating the current player.
};

/**
 * @brief Test fixture for testing the MoveNode class.
 */
class MoveNodeTest : public ::testing::Test {
protected:
    MoveNode moveNode{Move(0, 0, 0, 0), 0}; ///< The move node object for testing.
};

/**
 * @brief Test fixture for testing the Player class.
 */
class PlayerTest : public ::testing::Test {
protected:
    Player humanPlayer{sf::Color::Red, Player::PlayerType::Human}; ///< Human player object for testing.
};

/**
 * @brief Tests the Minimax execution.
 */
TEST(MinimaxThreadTest, ВиконанняMinimax) {
    Board board; // Creating a board object
    int depth = 4;
    int alpha = INT_MIN;
    int beta = INT_MAX;
    bool computerPlayer = true;

    MinimaxThread minimaxThread(board, depth, alpha, beta, computerPlayer); // Creating a MinimaxThread object

    minimaxThread.start(); // Starting the algorithm in a thread

    minimaxThread.join(); // Waiting for the algorithm to finish execution

    int result = minimaxThread.getResult(); // Getting the result

    // Checking the result of the algorithm
    ASSERT_GE(result, -100);
    ASSERT_LE(result, 100);
}

/**
 * @brief Tests the constructor of the MoveNode class.
 */
TEST(MoveNodeTest, ConstructorTest) {
    MoveNode moveNode(Move(1, 2, 3, 4), 10); // Creating a MoveNode object with a move and a score
    // Checking the parameters of the object
    EXPECT_EQ(moveNode.getMove().getStartX(), 1);
    EXPECT_EQ(moveNode.getMove().getStartY(), 2);
    EXPECT_EQ(moveNode.getMove().getEndX(), 3);
    EXPECT_EQ(moveNode.getMove().getEndY(), 4);
    EXPECT_EQ(moveNode.getScore(), 10);
}

/**
 * @brief Tests adding a child node to MoveNode.
 */
TEST_F(MoveNodeTest, AddChildTest) {
    MoveNode childNode(Move(2, 3, 4, 5), 5); // Creating a child node with a move and a score
    moveNode.addChild(childNode); // Adding the child node
    auto children = moveNode.getChildren(); // Getting all child nodes
    // Checking the parameters of the child node
    ASSERT_EQ(children.size(), 1);
    EXPECT_EQ(children[0].getMove().getStartX(), 2);
    EXPECT_EQ(children[0].getMove().getStartY(), 3);
    EXPECT_EQ(children[0].getMove().getEndX(), 4);
    EXPECT_EQ(children[0].getMove().getEndY(), 5);
    EXPECT_EQ(children[0].getScore(), 5);
}

/**
 * @brief Tests the constructor of the Player class.
 */
TEST(PlayerTest, ConstructorTest) {
    Player computerPlayer(sf::Color::Black, Player::PlayerType::Computer); // Creating a computer player object
    // Checking the parameters of the object
    EXPECT_EQ(computerPlayer.getColor(), sf::Color::Black);
    EXPECT_EQ(computerPlayer.type, Player::PlayerType::Computer);
}

/**
 * @brief Tests the getColor method of the Player class.
 */
TEST_F(PlayerTest, GetColorTest) {
    EXPECT_EQ(humanPlayer.getColor(), sf::Color::Red); // Checking the color of the player
}

/**
 * @brief Tests the ChooseColor method of the Menu class.
 */
TEST(MenuTest, ChooseColorTest) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test"); // Creating a window for menu testing
    window.setFramerateLimit(60);

    Menu menu(window); // Creating a menu object
    Player player = menu.chooseColor(); // Choosing the player color

    EXPECT_NE(player.getColor(), sf::Color::White); // Checking that the player color is not white
}

/**
 * @brief Tests the evaluateBoard method of the Board class.
 */
TEST(BoardTest, EvaluateBoardTest) {
    Player redPlayer(sf::Color::Red, Player::PlayerType::Human); // Creating a red player
    Player blackPlayer(sf::Color::Black, Player::PlayerType::Computer); // Creating a black player

    Board board(redPlayer, blackPlayer); // Creating a board with players

    int score = board.evaluateBoard(board); // Evaluating the state of the board

    // Checking the result
    EXPECT_EQ(score, 10);
    EXPECT_TRUE(board.isPieceAt(0, 0));
    EXPECT_TRUE(board.isPieceAt(1, 1));
    EXPECT_TRUE(board.isPieceAt(6, 6));
    EXPECT_TRUE(board.isPieceAt(5, 7));
    EXPECT_TRUE(board.isPieceAt(2, 2));
}

/**
 * @brief Tests the validarity method of the Board class.
 */
TEST(BoardTest, ValidarityTest) {
    logic loogic; // Creating a logic object
    Player redPlayer(sf::Color::Red, Player::PlayerType::Human); // Creating a red player
    Player blackPlayer(sf::Color::Black, Player::PlayerType::Computer); // Creating a black player

    Board board(redPlayer, blackPlayer); // Creating a board with players

    Piece piece;
    piece.isAlive = true;
    piece.isKing = false;
    piece.x = 3;
    piece.y = 4;

    board.pieces[4 * board.size + 3].isAlive = true;

    bool isValid = loogic.validarity(piece, 3, 3); // Checking the validity of a move

    EXPECT_FALSE(isValid); // Ensuring the move is invalid
}