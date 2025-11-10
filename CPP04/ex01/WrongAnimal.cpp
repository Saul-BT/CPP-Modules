#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal( void ) : _type("Unknown") {
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string const & type ) : _type(type) {
    std::cout << "WrongAnimal: Type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & other ) {
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

// Assignment operator
WrongAnimal& WrongAnimal::operator=( WrongAnimal const & other ) {
    std::cout << "WrongAnimal: Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }

    return *this;
}

// Getters and Setters
const std::string& WrongAnimal::getType( void ) const {
    return this->_type;
}

void WrongAnimal::setType( std::string const & type ) {
    this->_type = type;
}

// Other methods
void WrongAnimal::makeSound( void ) const {
    std::cout << "WrongAnimal sound: WrHOng! WrHOng! WrHOng!!! 🎅" << std::endl;
}
