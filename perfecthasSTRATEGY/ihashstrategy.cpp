#include "ihashstrategy.h"

/// Implementation of a universal hash function
class UniversalHashFunction : public IHashFunction {
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
    int hash(const Rational& key, int i) const override;
    /**
    * @brief Gets the size of the table
    * @return The size of the table
    */
    int getTableSize() const override;

private:
    int a, b, p, m;
};

class SimpleHashFunction : public IHashFunction {
public:
    SimpleHashFunction(int m_val);
    int hash(const Rational& key, int i) const override;
    int getTableSize() const override;

private:
    int m;
};