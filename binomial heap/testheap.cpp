#include "gtest/gtest.h"
#include "heaprealization.h"


TEST(BinomialHeapTest, Insertion) {
    BinomialHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(2);

    ASSERT_EQ(heap.size(), 4);
}


TEST(BinomialHeapTest, Extraction) {
    BinomialHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(2);

    ASSERT_EQ(heap.extract_min(), 2);
    ASSERT_EQ(heap.size(), 3);
}


TEST(BinomialHeapTest, DecreaseKey) {
    BinomialHeap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(2);

    Node* node = heap.trees[1]->children[0];
    heap.decrease_key(node, 1);

    ASSERT_EQ(heap.get_min(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}