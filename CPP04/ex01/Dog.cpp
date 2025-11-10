#include "Dog.hpp"

// Constructors
Dog::Dog( void ) {
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog( std::string const & type ) : Animal(type) {
    this->_brain = new Brain();
    std::cout << "Dog: Type constructor called" << std::endl;
}

Dog::Dog( Dog const & other ): Animal(other) {
    this->_brain = NULL;
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Dog::~Dog() {
    if (this->_brain) {
        delete this->_brain;
    }
    std::cout << "Dog: Destructor called" << std::endl;
}

// Assignment operator
Dog& Dog::operator=( Dog const & other ) {
    std::cout << "Dog: Assignment operator called" << std::endl;
    if (this->_brain) {
        delete this->_brain;
    }
    if (this != &other) {
        this->_type = other._type;
        this->_brain = new Brain(*other._brain);
    }

    return *this;
}

// Getters and Setters
Brain& Dog::getBrain( void ) const {
    return *this->_brain;
}

void Dog::setBrain( Brain & brain ) {
    this->_brain = &brain;
}

// Other methods
void Dog::makeSound( void ) const {
    std::cout << "Guau! Guau!" << std::endl;
}


void Dog::showThinking( void ) const {
    std::cout << "=== Thinking of " << this->_type << " ===" << std::endl;
    for (int i = 0; i < MAX_IDEAS; i++)
        std::cout << this->_brain->getIdea(i);
    std::cout << std::endl;
    std::cout << "=====================================" << std::endl;
}
