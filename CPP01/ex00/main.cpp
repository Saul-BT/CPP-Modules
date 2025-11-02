#include "Zombie.hpp"

int main ( void ) {
    Zombie *pepe = newZombie("Pepe");
    pepe->announce();
    delete pepe;

    randomChump("Chiquito");

    return 0;
}
