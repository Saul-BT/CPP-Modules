#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H

#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;

public:
    Zombie( void );
    Zombie( std::string const & name );
    ~Zombie();

    // Setters
    void setName( std::string const & name );

    // Other methods
    void announce( void ) const;
};

Zombie* zombieHorde( int N, std::string const & name );

#endif
