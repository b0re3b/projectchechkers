#include <gtest/gtest.h>
#include "dpstrategy.h"
class OBSTreeTest : public ::testing::Test {
protected:
    DPStrategy obst;

    void SetUp() override {
        // Ініціалізація перед кожним тестом
    }

    void TearDown() override {
        // Очистка після кожного тесту
    }
};

TEST_F(OBSTreeTest, BasicConstruction) {
std::vector<double> values = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
std::vector<double> probabilities = {0.1, 0.1, 0.2, 0.34, 0.55, 0.123, 0.567, 0.345, 0.765, 0.111};

obst.values = values;
obst.probabilities = probabilities;

std::vector<std::vector<double>> cost(values.size(), std::vector<double>(values.size(), -1));
std::vector<std::vector<int>> root(values.size(), std::vector<int>(values.size(), -1));

obst.constructTreeDP(0, values.size() - 1, cost, root);
obst.rootPtr = obst.constructTree(0, values.size() - 1, root);

EXPECT_NE(obst.rootPtr, nullptr);
EXPECT_EQ(obst.rootPtr->value, 18);
}

TEST_F(OBSTreeTest, EmptyInput) {
obst.values = {};
obst.probabilities = {};

std::vector<std::vector<double>> cost(0, std::vector<double>(0, -1));
std::vector<std::vector<int>> root(0, std::vector<int>(0, -1));

obst.constructTreeDP(0, -1, cost, root);
obst.rootPtr = obst.constructTree(0, -1, root);

EXPECT_EQ(obst.rootPtr, nullptr);
}

TEST_F(OBSTreeTest, SingleElement) {
obst.values = {10};
obst.probabilities = {1.0};

std::vector<std::vector<double>> cost(1, std::vector<double>(1, -1));
std::vector<std::vector<int>> root(1, std::vector<int>(1, -1));

obst.constructTreeDP(0, 0, cost, root);
obst.rootPtr = obst.constructTree(0, 0, root);

ASSERT_NE(obst.rootPtr, nullptr);
EXPECT_EQ(obst.rootPtr->value, 10);
EXPECT_EQ(obst.rootPtr->probability, 1.0);
EXPECT_EQ(obst.rootPtr->left, nullptr);
EXPECT_EQ(obst.rootPtr->right, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
