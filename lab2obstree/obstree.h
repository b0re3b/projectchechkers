#ifndef OBSTREE_H
#define OBSTREE_H
#include <iostream>
#include <vector>
#include <memory>
#include "TreeConstructionStrategy.h"

struct Node {
    double value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    double probability;

    Node(double val, double prob)
            : value(val), left(nullptr), right(nullptr), probability(prob) {}
};

class OBSTree {
private:
    std::vector<double> values;
    std::vector<double> probabilities;
    std::unique_ptr<Node> rootPtr;
    std::unique_ptr<TreeConstructionStrategy> strategy;

    std::unique_ptr<Node> constructTree(int start, int end, const std::vector<std::vector<int>>& root);
    void print(Node* node, int level, bool isLeft) const;

public:
    OBSTree(std::unique_ptr<TreeConstructionStrategy> strategyPtr);
    void createTreeFromConsole();
    void print() const;
};


#endif
