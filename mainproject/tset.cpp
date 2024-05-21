/*#include "gtest/gtest.h"
#include "board.h"

TEST(BoardTest, ValidMove) {
    Player red(sf::Color::Red, Player::PlayerType::Human);
    Player black(sf::Color::Black, Player::PlayerType::Human);
    Board board(red, black);

    Piece piece = board.pieces[13]; // Example black piece
    EXPECT_TRUE(board.validarity(piece, 2, 3));  // Valid move forward
    EXPECT_FALSE(board.validarity(piece, 3, 3)); // Invalid move sideways
}
class BoardTest : public ::testing::Test {
protected:
    void SetUp() override {
        red = new Player(sf::Color::Red, Player::PlayerType::Computer);
        black = new Player(sf::Color::Black, Player::PlayerType::Human);
        board = new Board(*red, *black);
        board->InitializeGame(*red, *black);
    }

    void TearDown() override {
        delete red;
        delete black;
        delete board;
    }

    Player* red;
    Player* black;
    Board* board;
};

TEST_F(BoardTest, ValidarityTest) {
    // Створюємо фішку на координатах (2, 3)
    Piece piece(true, false, sf::Color::Red, 2, 3);

    // Перевіряємо коректні ходи
    EXPECT_TRUE(board->validarity(piece, 3, 4)); // Можливий хід на (3, 4)
    EXPECT_TRUE(board->validarity(piece, 1, 4)); // Можливий хід на (1, 4)

    // Перевіряємо некоректні ходи
    EXPECT_FALSE(board->validarity(piece, 4, 5)); // Недопустимий хід на (4, 5)
    EXPECT_FALSE(board->validarity(piece, 0, 0)); // Недопустимий хід на (0, 0)

    // Перевіряємо ходи на зайняті клітинки
    Piece blockingPiece(true, false, sf::Color::Black, 3, 4);
    board->pieces.push_back(blockingPiece);
    EXPECT_FALSE(board->validarity(piece, 3, 4)); // Клітинка зайнята
}
 */