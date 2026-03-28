#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base * generate( void ) {
    int random = std::rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();

}

void identify( Base * ptr ) {
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
    try {
        (void) dynamic_cast<A &>(ref);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception &) {}

    try {
        (void) dynamic_cast<B &>(ref);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception &) {}

    try {
        (void) dynamic_cast<C &>(ref);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception &) {}

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
