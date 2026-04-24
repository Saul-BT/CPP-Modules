#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main( void ) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Test deep copy via copy constructor
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    // Verify values preserved after copy destruction
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // Test out-of-bounds access
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Out of bounds (negative): " << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Out of bounds (overflow): " << e.what() << std::endl;
    }

    // Test assignment operator deep copy
    {
        Array<int> copy;
        copy = numbers;
        for (int i = 0; i < MAX_VAL; i++) {
            if (copy[i] != numbers[i]) {
                std::cerr << "Assignment copy failed!" << std::endl;
                return 1;
            }
        }
        copy[0] = -1;
        if (numbers[0] == -1) {
            std::cerr << "Assignment is shallow copy!" << std::endl;
            return 1;
        }
    }

    // Test empty array
    {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
        try {
            empty[0] = 42;
        }
        catch(const std::exception& e) {
            std::cerr << "Empty array access: " << e.what() << std::endl;
        }
    }

    // Test with different types
    {
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "42";
        for (unsigned int i = 0; i < strArr.size(); i++)
            std::cout << strArr[i] << std::endl;
    }

    // Test size()
    std::cout << "Size: " << numbers.size() << std::endl;

    delete[] mirror;
    return 0;
}
