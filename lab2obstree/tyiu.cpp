/*
#include "gtest/gtest.h"
#include "obstree.h"
#include "RecursiveStrategy.h"

TEST(OBSTreeTest, SingleNodeTreeConstruction) {
    std::vector<double> values = {1};
    std::vector<double> probabilities = {1};
    RecursiveStrategy strategy;
    OBSTree tree(values, probabilities, strategy);

    auto root = tree.constructTree(0, values.size() - 1, std::vector<std::vector<int>>{});
    ASSERT_NE(root, nullptr);
}

TEST(OBSTreeTest, EmptyInputData) {
    std::vector<double> values;
    std::vector<double> probabilities;
    RecursiveStrategy strategy;
    OBSTree tree(values, probabilities, strategy);

    auto root = tree.constructTree(0, values.size() - 1, std::vector<std::vector<int>>{});
    ASSERT_EQ(root, nullptr);
}

TEST(OBSTreeTest, LargeInputData) {
    std::vector<double> values = {1, 2, 3, 4, 5};
    std::vector<double> probabilities = {0.1, 0.2, 0.3, 0.2, 0.2};
    RecursiveStrategy strategy;
    OBSTree tree(values, probabilities, strategy);

    auto root = tree.constructTree(0, values.size() - 1, std::vector<std::vector<int>>{});
    ASSERT_NE(root, nullptr);
}

TEST(OBSTreeTest, StrategyComparison) {
    std::vector<double> values = {1, 2, 3};
    std::vector<double> probabilities = {0.2, 0.3, 0.5};
    RecursiveStrategy strategy;
    OBSTree tree(values, probabilities, strategy);

    auto recursiveRoot = tree.constructTree(0, values.size() - 1, std::vector<std::vector<int>>{});
    ASSERT_NE(recursiveRoot, nullptr);
}
*/