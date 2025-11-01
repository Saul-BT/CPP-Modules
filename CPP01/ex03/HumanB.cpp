#include "HumanB.hpp"

// Constructors
HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {}

// Setters
void HumanB::setWeapon( Weapon const & weapon ) {
    this->_weapon = &weapon;
}

// Other functions
void HumanB::attack( void ) const {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
