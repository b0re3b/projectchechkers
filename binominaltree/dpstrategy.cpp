#include "dpstrategy.h"

double DPStrategy::constructTreeDP(int start, int end, std::vector<std::vector<double>>& cost, std::vector<std::vector<int>>& root) {
    if (start > end) return 0;

    if (cost[start][end] != -1) return cost[start][end];

    double minCost = std::numeric_limits<double>::infinity();
    int bestRoot = -1;

    double prefixSum = 0;
    for (int i = start; i <= end; ++i) {
        prefixSum += probabilities[i];
    }

    for (int i = start; i <= end; ++i) {
        double currCost = constructTreeDP(start, i - 1, cost, root) +
                          constructTreeDP(i + 1, end, cost, root) +
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