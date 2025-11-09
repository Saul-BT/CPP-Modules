#include "Fixed.hpp"

// Static attributes
const int Fixed::_fractionalBits = 8;

// Constructors
Fixed::Fixed( void ) : _value(0) { };

Fixed::Fixed( int const value ) {
    this->_value = value * (1 << this->_fractionalBits);
}

Fixed::Fixed( float const value ) {
    this->_value = static_cast<int>(roundf(value * (1 << this->_fractionalBits)));
}

Fixed::Fixed( Fixed const & other ) {
    *this = other;
};

// Destructor
Fixed::~Fixed() { }

// Assignment operator
Fixed& Fixed::operator=( Fixed const & other ) {
    if (this != &other) {
        this->_value = other.getRawBits();
    }

    return *this;
}

// Comparison operators
bool Fixed::operator>( Fixed const & other ) const {
    return this->_value > other._value;
}

bool Fixed::operator<( Fixed const & other ) const {
    return this->_value < other._value;
}

bool Fixed::operator>=( Fixed const & other ) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=( Fixed const & other ) const {
    return this->_value <= other._value;
}

bool Fixed::operator==( Fixed const & other ) const {
    return this->_value == other._value;
}

bool Fixed::operator!=( Fixed const & other ) const {
    return this->_value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+( Fixed const & other ) const {
    Fixed fixed;

    fixed._value = this->_value + other._value;

    return fixed;
}

Fixed Fixed::operator-( Fixed const & other ) const {
    Fixed fixed;

    fixed._value = this->_value - other._value;

    return fixed;
}

Fixed Fixed::operator*( Fixed const & other ) const {
    Fixed fixed(this->toFloat() * other.toFloat());

    return fixed;
}

Fixed Fixed::operator/( Fixed const & other ) const {
    Fixed fixed(this->toFloat() / other.toFloat());

    return fixed;
}

// Selfmutate operators (inc / dec)
Fixed& Fixed::operator++( void ) {
    ++this->_value;

    return *this;
}

Fixed& Fixed::operator--( void ) {
    --this->_value;

    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed prev = *this;

    ++this->_value;

    return prev;
}

Fixed Fixed::operator--( int ) {
    Fixed prev = *this;

    --this->_value;

    return prev;
}

// Setters
void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

// Getters
int Fixed::getRawBits( void ) const {
    return this->_value;
}

// Other methods
float Fixed::toFloat( void ) const {
    return this->_value / static_cast<float>(1 << this->_fractionalBits);
}
int Fixed::toInt( void ) const {
    return this->_value / (1 << this->_fractionalBits);
}

// Static methods
Fixed& Fixed::min( Fixed & f1, Fixed & f2 ) {
    if (f1 < f2) return f1;

    return f2;
}

Fixed& Fixed::max( Fixed & f1, Fixed & f2 ) {
    if (f1 > f2) return f1;

    return f2;
}

const Fixed& Fixed::min( Fixed const & f1, Fixed const & f2 ) {
    if (f1 < f2) return f1;

    return f2;
}

const Fixed& Fixed::max( Fixed const & f1, Fixed const & f2 ) {
    if (f1 > f2) return f1;

    return f2;
}

// Utilities
std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
    out << fixed.toFloat();

    return out;
}
