#include "obstree.h"
#include <iostream>

#include <algorithm>


// Приватна структура Node

// Метод побудови дерева
std::unique_ptr<Node> OBSTree::constructTree(int start, int end, const std::vector<std::vector<int>>& root) {
    if (start < 0 || end >= static_cast<int>(root.size()) || start > end) return nullptr;

    int rootIndex = root[start][end];
    if (rootIndex == -1 || rootIndex < start || rootIndex > end) return nullptr;

    std::unique_ptr<Node> node = std::make_unique<Node>(values[rootIndex], probabilities[rootIndex]);

    node->left = constructTree(start, rootIndex - 1, root);
    node->right = constructTree(rootIndex + 1, end, root);

    return node;
}

// Рекурсивний метод для друку дерева в консоль
void OBSTree::print(Node* node, int level, bool isLeft) const {
    if (!node) return;
    for (int i = 0; i < level; ++i) std::cout << "|\t";
    std::cout << (isLeft ? "LEFT " : "RIGHT ");
    std::cout << "Value = " << node->value << ", Probability = " << node->probability << std::endl;
    print(node->left.get(), level + 1, true);
    print(node->right.get(), level + 1, false);
}

// Конструктор класу OBSTree
OBSTree::OBSTree(std::unique_ptr<TreeConstructionStrategy> strategyPtr)
        : strategy(std::move(strategyPtr)) {}

// Метод для створення дерева з консолі
void OBSTree::createTreeFromConsole() {
    int n;
    std::cout << "Enter the number of values: ";
    std::cin >> n;

    values.resize(n);
    probabilities.resize(n);

    std::cout << "Enter the values:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    std::cout << "Enter the probabilities:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> probabilities[i];
    }

    std::vector<std::vector<double>> cost(n, std::vector<double>(n, -1));
    std::vector<std::vector<int>> root(n, std::vector<int>(n, 0));

    strategy->constructTree(0, n - 1, cost, root, probabilities);

    rootPtr = constructTree(0, n - 1, root);
}

// Метод для друку дерева в консоль
void OBSTree::print() const {
    print(rootPtr.get(), 0, true);
}
