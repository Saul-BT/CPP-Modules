#ifndef SCAV_TRAP_CLASS_H
#define SCAV_TRAP_CLASS_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( ScavTrap const & other );
    ~ScavTrap();

    void guardGate( void ) const;
};

#endif
