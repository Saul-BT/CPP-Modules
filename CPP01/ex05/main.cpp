#include "Harl.hpp"

int main( void ) {
    Harl harl;

    harl.complain("debug");
    harl.complain("DEBUG");
    harl.complain("info");
    harl.complain("INFO");
    harl.complain("warning");
    harl.complain("WARNING");
    harl.complain("error");
    harl.complain("ERROR");

    harl.complain("Pikachu");

    return 0;
}
