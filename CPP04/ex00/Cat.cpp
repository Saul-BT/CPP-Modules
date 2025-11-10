#include "Cat.hpp"

// Constructors
Cat::Cat( void ) {
    this->_type = "Cat";
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat( std::string const & type ) : Animal(type) {
    std::cout << "Cat: Type constructor called" << std::endl;
}

Cat::Cat( Cat const & other ): Animal(other) {
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Cat::~Cat() {
    std::cout << "Cat: Destructor called" << std::endl;
}

// Assignment operator
Cat& Cat::operator=( Cat const & other ) {
    std::cout << "Cat: Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }

    return *this;
}

// Other methods
void Cat::makeSound( void ) const {
    std::cout << "Meow! Meow!" << std::endl;
}
