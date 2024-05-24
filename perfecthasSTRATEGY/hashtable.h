#ifndef PERFECTHASHING_HASHTABLE_H
#define PERFECTHASHING_HASHTABLE_H
#include <vector>
#include "iostream"
#include "ihashstrategy.h"
#include "hashfunction.h"
/// Implementation of a perfect hash table
class PerfectHashTable {
public:
    /**
     * @brief Constructor for the perfect hash table
     * @param input A vector of rational numbers to be inserted into the table
     * @param hash_func A shared pointer to the hash function object
     * @note This demonstrates the use of the Strategy pattern, as the hash function can be replaced without changing the table implementation
     */
    PerfectHashTable(const std::vector<Rational>& input, std::shared_ptr<IHashFunction> hash_func);
    /**
     * @brief Inserts a rational number into the table
     * @param key The rational number to be inserted
     */
    void insert(const Rational& key);
    /**
    * @brief Searches for a rational number in the table
    * @param key The rational number to search for
    * @return true if the number is found, otherwise false
    */
    bool find(const Rational& key) const;
    /// Prints the elements of the table by index
    void printElementsByIndex() const;

private:
    std::vector<Rational> elements;///< Vector of elements in the table
    std::vector<std::vector<Rational>> table;///< Vector of vectors for the hash table
    size_t size;///< Size of the table
    std::shared_ptr<IHashFunction> hashFunction; ///< Shared pointer to the hash function
};
#endif //PERFECTHASHING_HASHTABLE_H
