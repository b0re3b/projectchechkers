#include "hashtable.h"

PerfectHashTable::PerfectHashTable(const std::vector<Rational>& input, std::shared_ptr<IHashFunction> hash_func)
        : elements(input.begin(), input.end()), hashFunction(hash_func) {
    size = elements.size();
    table.resize(hashFunction->getTableSize());

    for (size_t i = 0; i < table.size(); ++i) {
        table[i].resize(1);
    }

    for (const auto& element : elements) {
        insert(element);
    }
}

void PerfectHashTable::insert(const Rational& key) {
    int index = hashFunction->hash(key, 0);
    int i = 1;
    bool inserted = false;
    while (i <= size && !inserted) {
        if (!table[index][0].first && !table[index][0].second) {
            table[index][0] = key;
            inserted = true;
        } else {
            index = hashFunction->hash(key, i);
            i++;
        }
    }
    if (!inserted) {
        throw std::runtime_error("Failed to insert element into the hash table: No available slots.");
    }
}

bool PerfectHashTable::find(const Rational& key) const {
    int index = hashFunction->hash(key, 0);
    int i = 1;
    while (i <= size) {
        if (table[index][0] == key) {
            return true;
        }
        index = hashFunction->hash(key, i);
        i++;
    }
    return false;
}

void PerfectHashTable::printElementsByIndex() const {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << "Index " << i << ": ";
        if (table[i][0].first == 0 && table[i][0].second == 0) {
            std::cout << "Empty" << std::endl;
        } else {
            std::cout << "{" << table[i][0].first << ", " << table[i][0].second << "}" << std::endl;
        }
    }
}