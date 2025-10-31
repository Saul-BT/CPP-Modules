#include "Zombie.hpp"

int main ( void ) {
    int zombieCount = 5;
    Zombie* horde = zombieHorde(5, "pepito");

    std::cout << "Argh, there are some 'pepitos'(?) over there" << std::endl;

    for (int i = 0; i < zombieCount; i++)
        horde[i].announce();

    delete[] horde;

    return 0;
}
