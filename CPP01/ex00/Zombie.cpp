#include "Zombie.hpp"

// Constructors
Zombie::Zombie( std::string name ): _name(name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << this->_name << std::endl;
}

// Other methods
void Zombie::announce( void ) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
