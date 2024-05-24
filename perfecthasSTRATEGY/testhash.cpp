#include <gtest/gtest.h>
#include "ihashstrategy.h"
#include "hashtable.h"


TEST(PerfectHashTableTest, InsertionTest) {
std::vector<Rational> input = {{1, 2}, {3, 4}, {5, 6}};
int a = 3, b = 5, p = 7, m = 10;

std::shared_ptr<IHashFunction> hash_func = std::make_shared<UniversalHashFunction>(input.size(), a, b, p, m);
PerfectHashTable pht(input, hash_func);

EXPECT_TRUE(pht.find({1, 2}));
EXPECT_TRUE(pht.find({3, 4}));
EXPECT_TRUE(pht.find({5, 6}));
}

TEST(PerfectHashTableTest, SearchTest) {
std::vector<Rational> input = {{1, 2}, {3, 4}, {5, 6}};
int a = 3, b = 5, p = 7, m = 10;

std::shared_ptr<IHashFunction> hash_func = std::make_shared<UniversalHashFunction>(input.size(), a, b, p, m);
PerfectHashTable pht(input, hash_func);

EXPECT_TRUE(pht.find({1, 2}));
EXPECT_FALSE(pht.find({7, 8}));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
