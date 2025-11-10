#include "Animal.hpp"

// Constructors
Animal::Animal( void ) : _type("Unknown") {
    std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal( std::string const & type ) : _type(type) {
    std::cout << "Animal: Type constructor called" << std::endl;
}

Animal::Animal( Animal const & other ) {
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal: Destructor called" << std::endl;
}

// Assignment operator
Animal& Animal::operator=( Animal const & other ) {
    std::cout << "Animal: Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }

    return *this;
}

// Getters and Setters
const std::string& Animal::getType( void ) const {
    return this->_type;
}

void Animal::setType( std::string const & type ) {
    this->_type = type;
}

// Other methods
void Animal::makeSound( void ) const {
    std::cout << "Animal sound: Ho! Ho! Ho!!! 🎅" << std::endl;
}
