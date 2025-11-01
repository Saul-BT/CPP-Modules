#ifndef HUMAN_A_CLASS_H
#define HUMAN_A_CLASS_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string const _name;
    Weapon const & _weapon;
public:
    // Constructors
    HumanA( std::string const & name, Weapon const & weapon );

    // Other functions
    void attack( void ) const;
};

#endif
