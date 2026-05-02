#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include "Span.hpp"

int main() {
    std::cout << "=== Span basic usage ===" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        std::cout << "Trying to add one more number (should throw)\n";
        sp.addNumber(42);
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== addRange tests ===" << std::endl;
    try {
        Span big(10);
        std::vector<int> v;
        for (int i = 0; i < 8; ++i)
            v.push_back(i * 10);

        big.addRange(v.begin(), v.end());
        std::cout << "After adding range of 8 elements, size ok.\n";
        std::cout << "Shortest: " << big.shortestSpan() << "  Longest: " << big.longestSpan() << std::endl;

        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        std::cout << "Attempting to add a small list of 3 elements (should exceed capacity and throw)\n";
        big.addRange(lst.begin(), lst.end());

    } catch (const std::exception& e) {
        std::cout << "Caught expected exception from addRange: " << e.what() << std::endl;
    }

    std::cout << "\n=== duplicate values ===" << std::endl;
    try {
        Span dup(3);
        dup.addNumber(5);
        dup.addNumber(5);
        dup.addNumber(5);
        std::cout << "Shortest (expect 0): " << dup.shortestSpan() << std::endl;
        std::cout << "Longest  (expect 0): " << dup.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== error cases ===" << std::endl;
    try {
        Span small(1);
        small.addNumber(42);
        std::cout << "Calling shortestSpan on a container with 1 element (should throw)\n";
        small.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}
