#include "heaprealization.h"


/**
 * @brief Constructor to initialize an empty binomial heap.
 */
BinomialHeap::BinomialHeap() : min_node(nullptr), count(0) {}

/**
 * @brief Check if the heap is empty.
 * @return True if the heap is empty, false otherwise.
 */
bool BinomialHeap::is_empty() const {
    return count == 0;
}

/**
 * @brief Insert a new element into the heap.
 * @param value The value to be inserted into the heap.
 */
void BinomialHeap::insert(double value) {
    BinomialHeap temp_heap;
    temp_heap.trees.push_back(NodeFactory::createNode(value));
    temp_heap.count = 1;
    merge(temp_heap);
}

/**
 * @brief Merge this heap with another heap.
 * @param other The heap to be merged with this heap.
 */
void BinomialHeap::merge(BinomialHeap& other) {
    trees.insert(trees.end(), other.trees.begin(), other.trees.end());
    count += other.count;
    other.trees.clear();
    other.count = 0;

    min_node = nullptr;  // Reset min_node before searching
    for (auto node : trees) {
        if (!min_node || node->value < min_node->value) {
            min_node = node;
        }
    }

    _consolidate();
}

/**
 * @brief Get the minimum element from the heap.
 * @return The minimum element from the heap.
 */
double BinomialHeap::get_min() const {
    if (is_empty()) {
        std::cerr << "Heap is empty" << std::endl;
        exit(1);
    }
    return min_node->value;
}

/**
 * @brief Extract the minimum element from the heap.
 * @return The minimum element extracted from the heap.
 */
double BinomialHeap::extract_min() {
    if (is_empty()) {
        std::cerr << "Heap is empty" << std::endl;
        exit(1);
    }

    Node* minNode = min_node;
    auto it = std::find(trees.begin(), trees.end(), minNode);
    trees.erase(it);

    BinomialHeap temp_heap;
    temp_heap.trees = std::move(minNode->children);
    temp_heap.count = (1 << minNode->degree) - 1;

    merge(temp_heap);
    count--;

    double minValue = minNode->value;
    delete minNode;
    return minValue;
}

/**
 * @brief Decrease the key of a node in the heap.
 * @param node The node whose key needs to be decreased.
 * @param new_value The new value to be assigned to the node.
 */
void BinomialHeap::decrease_key(Node* node, double new_value) {
    if (new_value > node->value) {
        std::cerr << "New value is greater than the current value" << std::endl;
        exit(1);
    }
    node->value = new_value;
    _bubble_up(node);
}

/**
 * @brief Delete a node from the heap.
 * @param node The node to be deleted from the heap.
 */
void BinomialHeap::delete_node(Node* node) {
    decrease_key(node, -std::numeric_limits<double>::infinity());
    extract_min();
}

/**
 * @brief Get the number of elements in the heap.
 * @return The number of elements in the heap.
 */
int BinomialHeap::size() const {
    return count;
}

/**
 * @brief Print the heap.
 */
void BinomialHeap::print() const {
    for (auto tree : trees) {
        print_tree(tree, 0);
        std::cout << std::endl;
    }
}

/**
 * @brief Print a binomial tree.
 * @param node The root node of the tree to be printed.
 * @param indent The indentation level for proper tree representation.
 */
void BinomialHeap::print_tree(Node* node, int indent) const {
    if (node) {
        std::cout << std::string(indent, ' ') << node->value << std::endl;
        for (auto child : node->children) {
            print_tree(child, indent + 4);
        }
    }
}

/**
 * @brief Link two binomial trees.
 * @param y Pointer to the root of the first tree.
 * @param z Pointer to the root of the second tree.
 */
void BinomialHeap::_link(Node* y, Node* z) {
    y->parent = z;
    z->children.push_back(y);
    z->degree++;
}

/**
 * @brief Bubble up the node to maintain heap property.
 * @param node The node to be bubbled up.
 */
void BinomialHeap::_bubble_up(Node* node) {
    while (node->parent && node->value < node->parent->value) {
        std::swap(node->value, node->parent->value);
        node = node->parent;
    }
}

/**
 * @brief Consolidate binomial trees to maintain heap property.
 */
void BinomialHeap::_consolidate() {
    if (trees.empty()) return;

    int max_degree = static_cast<int>(std::floor(std::log2(count))) + 1;
    std::vector<Node*> degree_table(max_degree + 1, nullptr);

    for (auto node : trees) {
        int d = node->degree;
        while (degree_table[d]) {
            Node* other = degree_table[d];
            if (node->value > other->value) {
                _link(node, other);
                node = other;
            } else {
                _link(other, node);
            }
            degree_table[d] = nullptr;
            d++;
        }
        degree_table[d] = node;
    }

    trees.clear();
    min_node = nullptr;
    for (auto node : degree_table) {
        if (node) {
            if (!min_node || node->value < min_node->value) {
                min_node = node;
            }
            trees.push_back(node);
        }
    }
}


BinomialHeap* BinomialHeapSingleton::instance = nullptr;

/**
 * @brief Get the singleton instance of BinomialHeap.
 * @return Pointer to the singleton instance.
 */
BinomialHeap* BinomialHeapSingleton::getInstance() {
    if (!instance) {
        instance = new BinomialHeap();
    }
    return instance;
}

