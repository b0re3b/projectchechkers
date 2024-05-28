#ifndef BINOMIAL_HEAP_HEAPREALIZATION_H
#define BINOMIAL_HEAP_HEAPREALIZATION_H

#include "Node.h"
#include <vector>
#include <iostream>
#include <limits>

/**
 * @class BinomialHeap
 * @brief Class representing a binomial heap.
 *
 * This class represents a binomial heap data structure. It provides methods for
 * inserting elements, merging heaps, extracting the minimum element, decreasing
 * the key of a node, deleting a node, getting the size, and printing the heap.
 */
class BinomialHeap {
private:
    Node* min_node; ///< Pointer to the node with the minimum value
    int count; ///< Number of elements in the heap

    static void _link(Node* y, Node* z); ///< Link two binomial trees
    static void _bubble_up(Node* node); ///< Bubble up the node to maintain heap property
    void _consolidate(); ///< Consolidate binomial trees to maintain heap property

public:
    /**
     * @brief Constructor to initialize an empty binomial heap.
     */
    BinomialHeap();

    bool is_empty() const; ///< Check if the heap is empty
    void insert(double value); ///< Insert a new element into the heap
    void merge(BinomialHeap& other); ///< Merge this heap with another heap
    double get_min() const; ///< Get the minimum element from the heap
    double extract_min(); ///< Extract the minimum element from the heap
    void decrease_key(Node* node, double new_value); ///< Decrease the key of a node
    void delete_node(Node* node); ///< Delete a node from the heap
    int size() const; ///< Get the number of elements in the heap
    void print() const; ///< Print the heap
    void print_tree(Node* node, int indent) const; ///< Print a binomial tree

    std::vector<Node*> trees; ///< List of binomial trees in the heap
};

/**
 * @class BinomialHeapSingleton
 * @brief Singleton class for managing a single instance of BinomialHeap.
 *
 * This class implements the Singleton pattern to ensure that only one instance
 * of BinomialHeap is created and accessed throughout the program.
 */
class BinomialHeapSingleton {
private:
    static BinomialHeap* instance; ///< Pointer to the singleton instance

    BinomialHeapSingleton() = delete; // Забороняємо конструктор за замовчуванням
    BinomialHeapSingleton(const BinomialHeapSingleton&) = delete; // Забороняємо конструктор копіювання
    BinomialHeapSingleton& operator=(const BinomialHeapSingleton&) = delete; // Забороняємо оператор присвоєння


public:
    /**
     * @brief Get the singleton instance of BinomialHeap.
     * @return Pointer to the singleton instance.
     */
    static BinomialHeap* getInstance();
};

#endif
