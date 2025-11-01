#ifndef HUMAN_B_CLASS_H
#define HUMAN_B_CLASS_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string _name;
    Weapon const * _weapon;
public:
    // Constructors
    HumanB( std::string name );

    // Setters
    void setWeapon( Weapon const & weapon );

    // Other functions
    void attack( void ) const;
};

#endif
