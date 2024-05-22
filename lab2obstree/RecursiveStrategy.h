#pragma once

#include "TreeConstructionStrategy.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

class RecursiveStrategy : public TreeConstructionStrategy {
public:
    /**
     * @brief Метод для побудови дерева.
     * @param start Початковий індекс діапазону.
     * @param end Кінцевий індекс діапазону.
     * @param cost Матриця для збереження обчислених витрат.
     * @param root Матриця для збереження кореневих індексів.
     * @param probabilities Вектор ймовірностей.
     * @return Вартість побудови оптимального дерева в даному діапазоні.
     */
    double constructTree(int start, int end, std::vector<std::vector<double>>& cost, std::vector<std::vector<int>>& root, const std::vector<double>& probabilities) const override {
        if (start > end) return 0;

        if (cost[start][end] != -1) return cost[start][end];

        double minCost = std::numeric_limits<double>::infinity();
        int bestRoot = -1;

        double prefixSum = std::accumulate(probabilities.begin() + start, probabilities.begin() + end + 1, 0.0);

        for (int i = start; i <= end; ++i) {
            double currCost = constructTree(start, i - 1, cost, root, probabilities) +
                              constructTree(i + 1, end, cost, root, probabilities) +
                              prefixSum;

            if (currCost < minCost) {
                minCost = currCost;
                bestRoot = i;
            }
        }

        cost[start][end] = minCost;
        root[start][end] = bestRoot;
        return minCost;
    }
};
