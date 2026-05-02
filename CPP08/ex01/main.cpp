#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <climits>
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

    std::cout << "\n=== additional edge cases ===" << std::endl;

    // 1) Invalid range (begin > end for random-access iterators)
    try {
        Span s(10);
        std::vector<int> vals;
        vals.push_back(1);
        vals.push_back(2);
        vals.push_back(3);
        std::cout << "Testing invalid range (begin > end) for addRange (should throw)\n";
        s.addRange(vals.end(), vals.begin());
    } catch (const std::exception& e) {
        std::cout << "Caught expected exception for invalid range: " << e.what() << std::endl;
    }

    // 2) Overflow in longestSpan (INT_MIN and INT_MAX)
    try {
        Span ov(2);
        ov.addNumber(INT_MIN);
        ov.addNumber(INT_MAX);
        std::cout << "Calling longestSpan with INT_MIN and INT_MAX (may throw overflow_error)\n";
        std::cout << "Longest span: " << ov.longestSpan() << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "Caught expected overflow_error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 3) shortestSpan with large values that could overflow when subtracted
    try {
        Span ov2(3);
        ov2.addNumber(INT_MIN);
        ov2.addNumber(-1);
        ov2.addNumber(INT_MAX);
        std::cout << "Calling shortestSpan with extreme values (should work or throw if overflow)\n";
        std::cout << "Shortest span: " << ov2.shortestSpan() << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "Caught expected overflow_error in shortestSpan: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception in shortestSpan: " << e.what() << std::endl;
    }

    std::cout << "\n=== large scale (subject) ===" << std::endl;
    try {
        Span big(10000);
        std::vector<int> v;
        v.reserve(10000);
        for (int i = 0; i < 10000; ++i)
            v.push_back(i);
        big.addRange(v.begin(), v.end());
        std::cout << "10000 numbers — Shortest: " << big.shortestSpan()
                  << "  Longest: " << big.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Span huge(100000);
        std::vector<int> v;
        v.reserve(100000);
        for (int i = 0; i < 100000; ++i)
            v.push_back(i * 2);
        huge.addRange(v.begin(), v.end());
        std::cout << "100000 numbers — Shortest: " << huge.shortestSpan()
                  << "  Longest: " << huge.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
