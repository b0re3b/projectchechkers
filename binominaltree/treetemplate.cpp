#include "treetemplate.h"

OBSTreeTemplate::Node::Node(double val, double prob)
        : value(val), left(nullptr), right(nullptr), probability(prob) {}

OBSTreeTemplate::OBSTreeTemplate() {}

std::unique_ptr<OBSTreeTemplate::Node> OBSTreeTemplate::constructTree(int start, int end, const std::vector<std::vector<int>>& root) {
    if (start < 0 || end >= root.size() || start > end) return nullptr;

    int rootIndex = root[start][end];
    if (rootIndex == -1 || rootIndex < start || rootIndex > end) return nullptr;

    std::unique_ptr<Node> node = std::make_unique<Node>(values[rootIndex], probabilities[rootIndex]);
    node->left = constructTree(start, rootIndex - 1, root);
    node->right = constructTree(rootIndex + 1, end, root);

    return node;
}

void OBSTreeTemplate::print(Node* node, int level, bool isLeft) const {
    if (!node) return;
    for (int i = 0; i < level; ++i) std::cout << "|\t";
    std::cout << (isLeft ? "LEFT " : "RIGHT ");
    std::cout << "Value = " << node->value << ", Probability = " << node->probability << std::endl;
    print(node->left.get(), level + 1, true);
    print(node->right.get(), level + 1, false);
}

void OBSTreeTemplate::createTreeFromConsole() {
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
    std::vector<std::vector<int>> root(n, std::vector<int>(n, -1));

    constructTreeDP(0, n - 1, cost, root);
    rootPtr = constructTree(0, n - 1, root);
}

void OBSTreeTemplate::print() const {
    print(rootPtr.get(), 0, true);
}