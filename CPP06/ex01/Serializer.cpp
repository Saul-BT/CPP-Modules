#include <cmath>
#include <limits>
#include <cerrno>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include "Serializer.hpp"

// Constructors
Serializer::Serializer( void ) {
    std::cout << "Serializer: Default constructor called" << std::endl;
}

Serializer::Serializer( Serializer const & other ) {
    std::cout << "Serializer: Copy constructor called" << std::endl;
    (void) other;
}

// Destructor
Serializer::~Serializer() {
    std::cout << "Serializer: Destructor called" << std::endl;
}

// Assignment operator
Serializer & Serializer::operator=( Serializer const & other ) {
    std::cout << "Serializer: Assignment operator called" << std::endl;
    (void) other;

    return *this;
}

// Static methods
uintptr_t Serializer::serialize( Data * ptr ) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize( uintptr_t raw ) {
    return reinterpret_cast<Data *>(raw);
}
