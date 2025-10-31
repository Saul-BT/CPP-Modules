#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H

#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;

public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie();

    // Setters
    void setName( std::string name );

    // Other methods
    void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif
