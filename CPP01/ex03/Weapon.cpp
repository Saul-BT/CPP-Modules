#include "Weapon.hpp"
#include <iostream>

// Constructors
Weapon::Weapon ( std::string const & type ) : _type(type) {}

// Setters
void Weapon::setType( std::string type ) {
    this->_type = type;
}

// Getters
const std::string& Weapon::getType( void ) const {
    return this->_type;
}
