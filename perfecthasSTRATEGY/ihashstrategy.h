#ifndef PERFECTHASHING_IHASHSTRATEGY_H
#define PERFECTHASHING_IHASHSTRATEGY_H
#include <utility>
/// Represents a rational number
using Rational = std::pair<int, int>;
/// Interface for hash functions
class IHashFunction {
public:
    /// Virtual destructor
    virtual ~IHashFunction() = default;
    /**
     * @brief Computes the hash for a rational number with an additional parameter
     * @param key The rational number to be hashed
     * @param i An additional parameter for hashing
     * @return The hash value
     */
    virtual int hash(const Rational& key, int i) const = 0;
    /**
     * @brief Gets the size of the table
     * @return The size of the table
     */
    virtual int getTableSize() const = 0;
};
#endif //PERFECTHASHING_IHASHSTRATEGY_H
