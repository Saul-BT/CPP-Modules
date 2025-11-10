#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap: Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap: Name constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap(other) {
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

// Other methods
void ScavTrap::guardGate( void ) const {
    if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap '" << this->_name << "': I'm dead 🥲!" << std::endl;
        return;
    }

    std::cout << "ScavTrap '" << this->_name << "' is now in Gatekeeper mode" << std::endl;
}
