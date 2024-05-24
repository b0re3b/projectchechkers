#include <iostream>
#include <vector>
#include <memory>
#include "hashfunction.h"
#include "hashtable.h"
#include "ihashstrategy.h"

/// Reads a rational number from the console
Rational readRationalFromConsole() {
    int numerator, denominator;
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;
    return {numerator, denominator};
}

int main() {
    std::vector<Rational> input;
    int n, a, b, p, m;

    std::cout << "Enter the number of rational numbers: ";
    std::cin >> n;
    std::cout << "Enter " << n << " rational numbers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        input.push_back(readRationalFromConsole());
    }

    std::cout << "Enter the value for a: ";
    std::cin >> a;
    std::cout << "Enter the value for b: ";
    std::cin >> b;
    std::cout << "Enter the value for p: ";
    std::cin >> p;
    std::cout << "Enter the value for m: ";
    std::cin >> m;

    std::shared_ptr<IHashFunction> hash_func = std::make_shared<UniversalHashFunction>(input.size(), a, b, p, m);
    PerfectHashTable pht(input, hash_func);

    std::cout << std::boolalpha;
    std::cout << "Enter the number of rational numbers to search: ";
    std::cin >> n;
    std::cout << "Enter " << n << " rational numbers to search:" << std::endl;
    for (int i = 0; i < n; ++i) {
        Rational toSearch = readRationalFromConsole();
        std::cout << "Found {" << toSearch.first << ", " << toSearch.second << "}: " << pht.find(toSearch) << std::endl;
    }

    std::cout << "Elements by index:" << std::endl;
    pht.printElementsByIndex();

    return 0;
}
