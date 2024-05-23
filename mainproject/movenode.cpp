#include "movenode.h"
/**
 * @brief Constructor for MoveNode class.
 * @param move The move associated with this node.
 * @param score The score of this node.
 */
MoveNode::MoveNode(const Move& move, int score) : move(move), score(score) {}

/**
 * @brief Get the move associated with this node.
 * @return The move associated with this node.
 */
Move MoveNode::getMove() const {
    return move;
}

/**
 * @brief Get the score of this node.
 * @return The score of this node.
 */
int MoveNode::getScore() const {
    return score;
}

/**
 * @brief Get the children of this node.
 * @return A vector of MoveNode representing the children.
 */
std::vector<MoveNode> MoveNode::getChildren() const {
    return children;
}

/**
 * @brief Add a child to this node.
 * @param child The child node to be added.
 */
void MoveNode::addChild(const MoveNode& child) {
    children.push_back(child);
}