#ifndef FRAG_TRAP_CLASS_H
#define FRAG_TRAP_CLASS_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

    FragTrap( void );
    FragTrap( std::string name );
    FragTrap( FragTrap const & other );
    ~FragTrap();

    void highFivesGuys( void ) const;
};

#endif
