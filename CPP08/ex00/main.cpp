#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main( void ) {
    // Test vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(42);
    vec.push_back(7);

    try {
        // Nice
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found in vector: " << *it << std::endl;

        // Not nice
        it = easyfind(vec, 99);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try {
        // Nice
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;

        // Not nice
        it = easyfind(lst, 99);
        std::cout << "Found in list: " << *it << std::endl;
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);

    try {
        // Nice
        std::deque<int>::iterator it = easyfind(deq, 100);
        std::cout << "Found in deque: " << *it << std::endl;

        // Not nice
        it = easyfind(deq, 99);
        std::cout << "Found in deque: " << *it << std::endl;
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test const vector
    const std::vector<int> cvec = vec;
    try {
        // Nice
        std::vector<int>::const_iterator cit = easyfind(cvec, 42);
        std::cout << "Found in const vector: " << *cit << std::endl;

        // Not nice
        cit = easyfind(cvec, 99);
        std::cout << "Found in const vector: " << *cit << std::endl;
    } catch (std::exception & e) {
        std::cout << "Exception (const): " << e.what() << std::endl;
    }

    return 0;
}
