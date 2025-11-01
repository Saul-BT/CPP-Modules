#include "Zombie.hpp"

// Constructors
Zombie::Zombie( void ): _name("Unknown") {}
Zombie::Zombie( std::string const & name ): _name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << this->_name << std::endl;
}

// Setters
void Zombie::setName( std::string const & name ) {
    this->_name = name;
}

// Other methods
void Zombie::announce( void ) const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
