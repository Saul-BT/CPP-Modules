#include "Fixed.hpp"

// Static attributes
const int Fixed::_fractionalBits = 8;

// Constructors
Fixed::Fixed( void ) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed( int const value ) {
    std::cout << "Int constructor called" << std::endl;

    this->_value = value * (1 << this->_fractionalBits);
}

Fixed::Fixed( float const value ) {
    std::cout << "Float constructor called" << std::endl;

    this->_value = static_cast<int>(roundf(value * (1 << this->_fractionalBits)));
}

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
    return this->_value;
}

// Other methods
float Fixed::toFloat( void ) const {
    //std::cout << "toFloat member function called" << std::endl;

    return this->_value / static_cast<float>(1 << this->_fractionalBits);
}
int Fixed::toInt( void ) const {
    //std::cout << "toInt member function called" << std::endl;

    return this->_value / (1 << this->_fractionalBits);
}

// Utilities
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();

    return out;
}
