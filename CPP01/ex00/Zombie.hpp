#ifndef ZOMBIE_CLASS_H
#define ZOMBIE_CLASS_H

#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;

public:
    Zombie( std::string name );
    ~Zombie();
    void announce( void ) const;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
