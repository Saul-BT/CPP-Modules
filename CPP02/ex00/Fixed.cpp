#include "Fixed.hpp"

// Static attributes
const int Fixed::_fractionalBits = 8;

// Constructors
Fixed::Fixed( void ) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( Fixed const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Fixed& Fixed::operator=( Fixed const & other ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }

    return *this;
}

// Setters
void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;

    this->_value = raw;
}

// Getters
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;

    return this->_value;
}
