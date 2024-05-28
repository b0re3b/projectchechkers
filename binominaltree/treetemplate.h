#ifndef BINOMINALTREE_TREETEMPLATE_H
#define BINOMINALTREE_TREETEMPLATE_H
#include <iostream>
#include <vector>
#include <memory>
#include "gtest/gtest.h"
/**
 * @brief Базовий клас з шаблонним методом для побудови оптимального бінарного дерева пошуку (ОБДП).
 */
class OBSTreeTemplate {
private:
    /**
    * @brief Структура вузла дерева.
    */
    struct Node {
        double value;///< Значення вузла.
        std::unique_ptr<Node> left;///< Вказівник на ліве піддерево.
        std::unique_ptr<Node> right; ///< Вказівник на праве піддерево.
        double probability;///< Ймовірність значення вузла.
         /**
         * @brief Конструктор вузла.
         * @param val Значення вузла.
         * @param prob Ймовірність значення вузла.
         */
        Node(double val, double prob);
        ~Node() = default;
    };

    std::unique_ptr<Node> rootPtr;///< Вказівник на кореневий вузол дерева.

protected:
    std::vector<double> values;///< Значення вузлів.
    std::vector<double> probabilities;///< Ймовірності вузлів.
    /**
        * @brief Абстрактний метод для побудови дерева за допомогою динамічного програмування.
        * @param start Початковий індекс діапазону.
        * @param end Кінцевий індекс діапазону.
        * @param cost Матриця вартостей.
        * @param root Матриця коренів.
        * @return Вартість побудови дерева.
        */
    virtual double constructTreeDP(int start, int end, std::vector<std::vector<double>>& cost, std::vector<std::vector<int>>& root) = 0;
    /**
    * @brief Побудова дерева на основі матриці коренів.
    * @param start Початковий індекс діапазону.
    * @param end Кінцевий індекс діапазону.
    * @param root Матриця коренів.
    * @return Вказівник на кореневий вузол побудованого дерева.
    */
    std::unique_ptr<Node> constructTree(int start, int end, const std::vector<std::vector<int>>& root);
    /**
   * @brief Рекурсивний метод для виводу дерева у консоль.
   * @param node Вказівник на поточний вузол.
   * @param level Поточний рівень глибини вузла.
   * @param isLeft Чи є вузол лівим нащадком.
   */
    void print(Node* node, int level, bool isLeft) const;
    friend class OBSTreeTest;

    FRIEND_TEST(OBSTreeTest, BasicConstruction);
    FRIEND_TEST(OBSTreeTest, EmptyInput);
    FRIEND_TEST(OBSTreeTest, SingleElement);
public:
    /**
     * @brief Конструктор за замовчуванням.
     */
    OBSTreeTemplate();
    /**
     * @brief Метод для введення даних з консолі та побудови дерева.
     */
    void createTreeFromConsole();
    /**
     * @brief Метод для виводу дерева у консоль.
     */
    void print() const;
};
#endif //BINOMINALTREE_TREETEMPLATE_H
