#ifndef TREE_CONSTRUCTION_STRATEGY_H
#define TREE_CONSTRUCTION_STRATEGY_H
#pragma once

#include <vector>

class TreeConstructionStrategy {
public:
    virtual double constructTree(int start, int end, std::vector<std::vector<double>>& cost, std::vector<std::vector<int>>& root, const std::vector<double>& probabilities) const = 0;
    virtual ~TreeConstructionStrategy() = default;
};

#endif // TREE_CONSTRUCTION_STRATEGY_H
