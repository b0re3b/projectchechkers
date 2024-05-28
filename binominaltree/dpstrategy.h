#ifndef BINOMINALTREE_DPSTRATEGY_H
#define BINOMINALTREE_DPSTRATEGY_H
#include <limits>
#include "treetemplate.h"
/**
 * @brief Підклас з конкретною реалізацією кроків побудови ОБДП.
 */
class DPStrategy : public OBSTreeTemplate {
protected:
    /**
     * @brief Реалізація методу побудови дерева за допомогою динамічного програмування.
     * @param start Початковий індекс діапазону.
     * @param end Кінцевий індекс діапазону.
     * @param cost Матриця вартостей.
     * @param root Матриця коренів.
     * @return Вартість побудови дерева.
     */
    friend class OBSTreeTest;
    FRIEND_TEST(OBSTreeTest, BasicConstruction);
    FRIEND_TEST(OBSTreeTest, EmptyInput);
    FRIEND_TEST(OBSTreeTest, SingleElement);
    double constructTreeDP(int start, int end, std::vector<std::vector<double>>& cost, std::vector<std::vector<int>>& root) override;
};
#endif //BINOMINALTREE_DPSTRATEGY_H
