#include "ClapTrap.hpp"

int main ( void ) {
    ClapTrap a;
    ClapTrap b("Jimmy");
    ClapTrap c(b);
    ClapTrap d;

    d = c;

    a.attack("🐶 Sanxe");
    b.attack("🐶 Sanxe");
    c.attack("🐶 Sanxe");
    d.attack("🐶 Sanxe");

    // Taxes
    a.takeDamage(10);
    b.takeDamage(10);
    c.takeDamage(10);

    // There's a bug for 'd'
    for (int i = 0; i < 9; i++)
        d.beRepaired(1);

    // Trying to recover
    a.beRepaired(10);
    b.beRepaired(10);
    c.beRepaired(10);
    d.beRepaired(10);

    // Taxes again
    a.takeDamage(10);
    b.takeDamage(10);
    c.takeDamage(10);
    d.takeDamage(10);

    return 0;
}
