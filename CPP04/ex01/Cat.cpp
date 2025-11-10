#include "Cat.hpp"

// Constructors
Cat::Cat( void ) {
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat( std::string const & type ) : Animal(type) {
    this->_brain = new Brain();
    std::cout << "Cat: Type constructor called" << std::endl;
}

Cat::Cat( Cat const & other ): Animal(other) {
    this->_brain = NULL;
    std::cout << "Cat: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Cat::~Cat() {
    if (this->_brain) {
        delete this->_brain;
    }
    std::cout << "Cat: Destructor called" << std::endl;
}

// Assignment operator
Cat& Cat::operator=( Cat const & other ) {
    std::cout << "Cat: Assignment operator called" << std::endl;
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
Brain& Cat::getBrain( void ) const {
    return *this->_brain;
}

void Cat::setBrain( Brain & brain ) {
    this->_brain = &brain;
}

// Other methods
void Cat::makeSound( void ) const {
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::showThinking( void ) const {
    std::cout << "=== Thinking of " << this->_type << " ===" << std::endl;
    for (int i = 0; i < MAX_IDEAS; i++)
        std::cout << this->_brain->getIdea(i);
    std::cout << std::endl;
    std::cout << "=====================================" << std::endl;
}
