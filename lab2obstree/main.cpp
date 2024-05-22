#include <iostream>
#include <memory>

#include "RecursiveStrategy.h"
#include "obstree.h"

int main() {
    std::unique_ptr<TreeConstructionStrategy> strategy = std::make_unique<RecursiveStrategy>();
    OBSTree obst(std::move(strategy));
    obst.createTreeFromConsole();
    obst.print();

    return 0;
}
