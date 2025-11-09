#include "ClapTrap.hpp"

int main ( void ) {
    ClapTrap a;
    ClapTrap b("Jimmy");
    ClapTrap c(b);
    ClapTrap d;

    d = c;

    a.attack("Jimmy");
    b.takeDamage(0);
    c.beRepaired(5);
    d.attack("Jimmy");
    b.takeDamage(0);

    return 0;
}
