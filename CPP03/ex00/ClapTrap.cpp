#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap(void) : _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

// Assignment operator
ClapTrap& ClapTrap::operator=( ClapTrap const & other ) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
    }

    return *this;
}

// Other methods
void ClapTrap::attack( std::string const & target ) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " almost dead!" << std::endl;
        return;
    }

    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is useless!" << std::endl;
        return;
    }

    this->_energyPoints--;

    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " almost dead! Bully!" << std::endl;
        return;
    }

    this->_hitPoints -= amount;

    std::cout << "ClapTrap " << this->_name << " loses " << amount << " hit point, now has " << this->_hitPoints << " hit points!" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is useless!" << std::endl;
        return;
    }

    this->_energyPoints--;
    this->_hitPoints += amount;

    std::cout << "ClapTrap " << this->_name << " was repaired, added " << amount << " points, total of " << this->_hitPoints << " hit points!" << std::endl;
}
