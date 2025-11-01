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

    HumanA( std::string const & name, Weapon const & weapon );

    void attack( void ) const;

};

#endif
