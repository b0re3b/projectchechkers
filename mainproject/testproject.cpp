#include <gtest/gtest.h>
#include "movenode.h"
#include "player.h"
#include "piece.h"
#include "menu.h"
#include "board.h"
#include "logic.h"

class MoveNodeTest : public ::testing::Test {
protected:
    MoveNode moveNode{Move(0, 0, 0, 0), 0};
};


class PlayerTest : public ::testing::Test {
protected:
    Player humanPlayer{sf::Color::Red, Player::PlayerType::Human};
};

TEST(MoveNodeTest, ConstructorTest) {
    MoveNode moveNode(Move(1, 2, 3, 4), 10);
    EXPECT_EQ(moveNode.getMove().getStartX(), 1);
    EXPECT_EQ(moveNode.getMove().getStartY(), 2);
    EXPECT_EQ(moveNode.getMove().getEndX(), 3);
    EXPECT_EQ(moveNode.getMove().getEndY(), 4);
    EXPECT_EQ(moveNode.getScore(), 10);
}

TEST_F(MoveNodeTest, AddChildTest) {
    MoveNode childNode(Move(2, 3, 4, 5), 5);
    moveNode.addChild(childNode);
    auto children = moveNode.getChildren();
    ASSERT_EQ(children.size(), 1);
    EXPECT_EQ(children[0].getMove().getStartX(), 2);
    EXPECT_EQ(children[0].getMove().getStartY(), 3);
    EXPECT_EQ(children[0].getMove().getEndX(), 4);
    EXPECT_EQ(children[0].getMove().getEndY(), 5);
    EXPECT_EQ(children[0].getScore(), 5);
}

TEST(PlayerTest, ConstructorTest) {
    Player computerPlayer(sf::Color::Black, Player::PlayerType::Computer);
    EXPECT_EQ(computerPlayer.getColor(), sf::Color::Black);
    EXPECT_EQ(computerPlayer.type, Player::PlayerType::Computer);
}

TEST_F(PlayerTest, GetColorTest) {
    EXPECT_EQ(humanPlayer.getColor(), sf::Color::Red);
}

TEST(MenuTest, ChooseColorTest) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test");
    window.setFramerateLimit(60);

    Menu menu(window);
    Player player = menu.chooseColor();

    EXPECT_NE(player.getColor(), sf::Color::White);
}

TEST(BoardTest, MinimaxTest) {

    Player redPlayer(sf::Color::Red, Player::PlayerType::Human);
    Player blackPlayer(sf::Color::Black, Player::PlayerType::Computer);

    Board board(redPlayer, blackPlayer);
    int depth = 3;
    int evaluation = gameLogic.minimax(board, depth, true);
    EXPECT_GE(evaluation, -100);
    EXPECT_LE(evaluation, 100);
}


TEST(BoardTest, EvaluateBoardTest) {
    Player redPlayer(sf::Color::Red, Player::PlayerType::Human);
    Player blackPlayer(sf::Color::Black, Player::PlayerType::Computer);

    Board board(redPlayer, blackPlayer);

    int score = board.evaluateBoard(board);

    EXPECT_EQ(score, 10);
    EXPECT_TRUE(board.isPieceAt(0, 0));
    EXPECT_TRUE(board.isPieceAt(1, 1));
    EXPECT_TRUE(board.isPieceAt(6, 6));
    EXPECT_TRUE(board.isPieceAt(5, 7));
    EXPECT_TRUE(board.isPieceAt(2, 2));
}


class BoardTest : public ::testing::Test {
protected:
    Board board;
};

TEST (BoardTest, ValidarityTest) {
    Player redPlayer(sf::Color::Red, Player::PlayerType::Human);
    Player blackPlayer(sf::Color::Black, Player::PlayerType::Computer);

    Board board(redPlayer, blackPlayer);

    Piece piece;
    piece.isAlive = true;
    piece.isKing = false;
    piece.x = 3;
    piece.y = 4;

    board.pieces[4 * board.size + 3].isAlive = true;


    bool isValid = board.validarity(piece, 3, 3);


    EXPECT_FALSE(isValid);
}
