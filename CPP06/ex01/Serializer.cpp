#include <stdexcept>
#include <iostream>

#include "Serializer.hpp"


// Constructors
Serializer::Serializer( void ) { }

Serializer::Serializer( Serializer const & other ) {
    (void) other;
}

// Destructor
Serializer::~Serializer() {
}

// Assignment operator
Serializer & Serializer::operator=( Serializer const & other ) {
    (void) other;

    return *this;
}

// Static methods
uintptr_t Serializer::serialize( Data * ptr ) {
    if (ptr == NULL)
        throw std::invalid_argument("Error: null pointer cannot be serialized");

    return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize( uintptr_t raw ) {
    if (raw == 0)
        throw std::invalid_argument("Error: null reference cannot be deserialized");

    try {
        return reinterpret_cast<Data *>(raw);
    }
    catch ( std::exception const & e ) {
        std::cout << "aa" << e.what() << std::endl;
    }
    return NULL;
}
