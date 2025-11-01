#include "Zombie.hpp"

Zombie* newZombie( std::string const & name ) {
    Zombie* zombie = new Zombie(name);

    return zombie;
}
