#include "Node.h"

/**
 * @brief Constructor to initialize a node with a given value.
 * @param val The value to be assigned to the node.
 */
Node::Node(double val) : value(val), parent(nullptr), degree(0) {}

/**
 * @brief Static method to create a new Node object.
 * @param value The value to be assigned to the node.
 * @return Pointer to the created Node object.
 */
Node* NodeFactory::createNode(double value) {
    return new Node(value);
}
