#include "Brain.hpp"

// Constructors
Brain::Brain( void ) {
    for (int i = 0; i < MAX_IDEAS; i++) {
        this->_ideas[i] = " 🧠 ";
    }
    std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain( Brain const & other ) {
    std::cout << "Brain: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Brain::~Brain() {
    std::cout << "Brain: Destructor called" << std::endl;
}

// Assignment operator
Brain& Brain::operator=( Brain const & other ) {
    std::cout << "Brain: Assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < MAX_IDEAS; i++)
            this->_ideas[i] = other._ideas[i];
    }

    return *this;
}

// Getter / Setter by idx
const std::string& Brain::getIdea( int idx ) const {
    if (idx < 0 || idx > MAX_IDEAS)
        throw new std::runtime_error("Error: idea out of range");

    return this->_ideas[idx];
}

void Brain::setIdea( int idx, std::string const & idea ) {
    if (idx < 0 || idx > MAX_IDEAS)
        throw new std::runtime_error("Error: idea out of range");

    this->_ideas[idx] = idea;
}
