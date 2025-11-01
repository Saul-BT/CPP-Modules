#include "HumanA.hpp"

// Constructors
HumanA::HumanA( std::string const & name, Weapon const & weapon ) : _name(name), _weapon(weapon) {}

// Other functions
void HumanA::attack( void ) const {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
