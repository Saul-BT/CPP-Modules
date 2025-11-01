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

    HumanB( std::string name );

    void setWeapon( Weapon const & weapon );

    void attack( void ) const;

};

#endif
