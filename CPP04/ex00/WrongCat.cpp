#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat( void ) {
    this->_type = "WrongCat";
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat( std::string const & type ) : WrongAnimal(type) {
    std::cout << "WrongCat: Type constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & other ): WrongAnimal(other) {
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called" << std::endl;
}

// Assignment operator
WrongCat& WrongCat::operator=( WrongCat const & other ) {
    std::cout << "WrongCat: Assignment operator called" << std::endl;
    if (this != &other) {
        this->_type = other._type;
    }

    return *this;
}
