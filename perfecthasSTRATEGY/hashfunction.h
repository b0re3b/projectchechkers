
#ifndef PERFECTHASHING_HASHFUNCTION_H
#define PERFECTHASHING_HASHFUNCTION_H
#include <utility>
#include "ihashstrategy.h"
using Rational = std::pair<int, int>;
/// Implementation of a universal hash function
class UniversalHashFunction: public IHashFunction {
public:
/**
     * @brief Constructor for the universal hash function
     * @param size The size of the table
     * @param a_val The value of parameter a
     * @param b_val The value of parameter b
     * @param p_val The value of parameter p
     * @param m_val The value of parameter m
     */
    UniversalHashFunction(int size, int a_val, int b_val, int p_val, int m_val);
    /**
    * @brief Computes the hash for a rational number with an additional parameter
    * @param key The rational number to be hashed
    * @param i An additional parameter for hashing
    * @return The hash value
    */
    int hash(const Rational& key, int i) const;
    /**
     * @brief Gets the size of the table
     * @return The size of the table
     */
    int getTableSize() const;

private:
    int a, b, p, m;
};
/// Implementation of a simple hash function
class SimpleHashFunction {
public:
    /**
    * @brief Constructor for the simple hash function
    * @param m_val The value of parameter m (the size of the table)
    */
    SimpleHashFunction(int m_val);
    /**
     * @brief Computes the hash for a rational number with an additional parameter
     * @param key The rational number to be hashed
     * @param i An additional parameter for hashing (ignored in this implementation)
     * @return The hash value
     */
    int hash(const Rational& key, int i) const;
    /**
     * @brief Gets the size of the table
     * @return The size of the table
     */
    int getTableSize() const;

private:
    int m;
};

#endif //PERFECTHASHING_HASHFUNCTION_H
