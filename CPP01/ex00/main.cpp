#include "Zombie.hpp"

int main ( void ) {
    // Using `newZombie`
    Zombie *pepe = newZombie("Pepe");
    pepe->announce();
    delete pepe;

    // Using `randomChump`
    randomChump("Chiquito");

    return 0;
}
