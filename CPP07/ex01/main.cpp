#include <iostream>
#include <string>
#include "iter.hpp"

void mul3( int & num ) {
    std::cout << (num * 3) << std::endl;
}

void parenthesize( std::string & word ) {
    std::cout << "(" << word << ")" << std::endl;
}

int main( void ) {
    int nums[] = {1, 2, 3};
    ::iter(nums, 3, mul3);

    std::string words[] = {"hello", "world", "!"};
    ::iter(words, 3, parenthesize);
    return 0;
}