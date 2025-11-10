#include "AAnimal.hpp"

// Constructors
AAnimal::AAnimal( void ) : _type("Unknown") {
    std::cout << "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string const & type ) : _type(type) {
    std::cout << "AAnimal: Type constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const & other ) {
    std::cout << "AAnimal: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
AAnimal::~AAnimal() {
    std::cout << "AAnimal: Destructor called" << std::endl;
}

// Assignment operator
AAnimal& AAnimal::operator=( AAnimal const & other ) {
    std::cout << "AAnimal: Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }

    return *this;
}

// Getters and Setters
const std::string& AAnimal::getType( void ) const {
    return this->_type;
}

void AAnimal::setType( std::string const & type ) {
    this->_type = type;
}
