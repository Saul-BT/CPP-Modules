#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: this program must take the sequence to compute as argument." << std::endl;
        return 1;
    }
    RPN rpn;
    if (!rpn.compute(argv[1]))
        return 1;
    return 0;
}
