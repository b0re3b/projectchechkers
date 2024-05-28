#ifndef BINOMIAL_HEAP_NODE_H
#define BINOMIAL_HEAP_NODE_H
#include <vector>

/**
 * @class Node
 * @brief Class representing a node in the binomial heap.
 */
class Node {
public:
    double value; ///< The value of the node
    Node* parent; ///< Pointer to the parent node
    std::vector<Node*> children; ///< List of children nodes
    int degree; ///< Degree of the node

    /**
     * @brief Constructor to initialize a node with a given value.
     * @param val The value to be assigned to the node.
     */
    Node(double val);
};

/**
 * @class NodeFactory
 * @brief Factory class for creating Node objects.
 */
class NodeFactory {
public:
    /**
     * @brief Static method to create a new Node object.
     * @param value The value to be assigned to the node.
     * @return Pointer to the created Node object.
     */
    static Node* createNode(double value);
};
#endif
