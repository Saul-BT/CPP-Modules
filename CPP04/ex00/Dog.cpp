#include "Dog.hpp"

// Constructors
Dog::Dog( void ) {
    this->_type = "Dog";
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog( std::string const & type ) : Animal(type) {
    std::cout << "Dog: Type constructor called" << std::endl;
}

Dog::Dog( Dog const & other ): Animal(other) {
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Dog::~Dog() {
    std::cout << "Dog: Destructor called" << std::endl;
}

// Assignment operator
Dog& Dog::operator=( Dog const & other ) {
    std::cout << "Dog: Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }

    return *this;
}

// Other methods
void Dog::makeSound( void ) const {
    std::cout << "Guau! Guau!" << std::endl;
}
