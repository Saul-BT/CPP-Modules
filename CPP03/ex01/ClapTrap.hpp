#ifndef CLAP_TRAP_CLASS_H
#define CLAP_TRAP_CLASS_H

#include <string>
#include <iostream>

class ClapTrap {

protected:

    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

public:

    ClapTrap( void );
    ClapTrap( std::string name );
    ClapTrap( ClapTrap const & other );
    ~ClapTrap();

    ClapTrap& operator=( ClapTrap const & other );

    void attack( std::string const & target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

};

#endif
