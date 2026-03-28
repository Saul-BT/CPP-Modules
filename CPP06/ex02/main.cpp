#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate( void ) {
    int random = std::rand() % 3;

    if (random == 0) {
        std::cout << "Generating A instance" << std::endl;
        return new A();
    }
    else if (random == 1) {
        std::cout << "Generating B instance" << std::endl;
        return new B();
    }
    else {
        std::cout << "Generating C instance" << std::endl;
        return new C();
    }

}

void identify( Base * ptr ) {
    std::cout << "Identifying pointer type: ";

    if (dynamic_cast<A *>(ptr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(ptr))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(ptr))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify( Base & ref ) {
    std::cout << "Identifying ref type: ";

    try {
        (void) dynamic_cast<A &>(ref);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast &) {}

    try {
        (void) dynamic_cast<B &>(ref);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast &) {}

    try {
        (void) dynamic_cast<C &>(ref);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast &) {}

    std::cout << "Unknown" << std::endl;
}

int main( void ) {
    std::srand(std::time(0));

    std::cout << "== Good examples ==" << std::endl;

    Base * ptr = generate();
    identify( *ptr );
    delete ptr;

    ptr = generate();
    identify( ptr );
    delete ptr;

    std::cout << std::endl << "== Bad examples ==" << std::endl;

    ptr = NULL;
    identify( ptr );

    Base ref;
    identify( ref );

    return 0;
}
