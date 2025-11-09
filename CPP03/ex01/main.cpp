#include "ScavTrap.hpp"

int main ( void ) {
    ClapTrap a;
    ScavTrap b("Jimmy");
    ScavTrap c(b);
    ScavTrap d;

    d = c;

    a.attack("🐶 Sanxe");
    b.attack("🐶 Sanxe");
    c.attack("🐶 Sanxe");
    d.attack("🐶 Sanxe");

    // Taxes
    a.takeDamage(10);
    b.takeDamage(10);
    c.takeDamage(10);

    // 'c' is trying to evade taxes
    c.guardGate();

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
