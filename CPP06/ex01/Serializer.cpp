#include <iostream>

#include "Serializer.hpp"


// Constructors
Serializer::Serializer( void ) { }

Serializer::Serializer( Serializer const & other ) {
    (void) other;
}

// Destructor
Serializer::~Serializer() { }

// Assignment operator
Serializer & Serializer::operator=( Serializer const & other ) {
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
