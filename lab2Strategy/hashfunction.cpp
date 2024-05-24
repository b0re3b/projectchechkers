
#include "hashfunction.h"
UniversalHashFunction::UniversalHashFunction(int size, int a_val, int b_val, int p_val, int m_val)
        : a(a_val), b(b_val), p(p_val), m(m_val) {}

int UniversalHashFunction::hash(const Rational& key, int i) const {
    int num = key.first, denom = key.second;
    long long hash_val = (1LL * a * num + 1LL * b * denom + i) % p;
    return static_cast<int>((hash_val % p) % m);
}

int UniversalHashFunction::getTableSize() const {
    return m;
}

SimpleHashFunction::SimpleHashFunction(int m_val) : m(m_val) {}

int SimpleHashFunction::hash(const Rational& key, int i) const {
    int num = key.first, denom = key.second;
    int hash_val = (num + denom) % m;
    return hash_val;
}

int SimpleHashFunction::getTableSize() const {
    return m;
}