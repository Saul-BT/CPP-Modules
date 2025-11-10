#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap: Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap: Name constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const & other ) : ClapTrap(other) {
    std::cout << "FragTrap: Copy constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap: Destructor called" << std::endl;
}

// Other methods
void FragTrap::highFivesGuys( void ) const {
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap '" << this->_name << "': I'm dead 🫠!" << std::endl;
        return;
    }

    std::cout << "FragTrap '" << this->_name << "' give me f*king five!!!" << std::endl;
}
