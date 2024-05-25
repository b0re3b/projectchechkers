
#ifndef MAINPROJECT_MOVENODE_H
#define MAINPROJECT_MOVENODE_H
#include <vector>
#include "move.h"

/**
 * @brief Class representing a node in the MinMax tree.
 */
class MoveNode {
public:
    /**
     * @brief Constructor for MoveNode class.
     * @param move The move associated with this node.
     * @param score The score of this node.
     */
    MoveNode(const Move& move, int score);

    /**
     * @brief Get the move associated with this node.
     * @return The move associated with this node.
     */
    Move getMove() const;

    /**
     * @brief Get the score of this node.
     * @return The score of this node.
     */
    int getScore() const;

    /**
     * @brief Get the children of this node.
     * @return A vector of MoveNode representing the children.
     */
    std::vector<MoveNode> getChildren() const;

    /**
     * @brief Add a child to this node.
     * @param child The child node to be added.
     */
    void addChild(const MoveNode& child);

private:
    friend class Board;
    friend class logic;
    Move move;                     /**< The move associated with this node. */
    int score;                     /**< The score of this node. */
    std::vector<MoveNode> children; /**< The children of this node. */
};
#endif //MAINPROJECT_MOVENODE_H
