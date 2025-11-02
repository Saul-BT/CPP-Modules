#include "Harl.hpp"

// Private methods
void Harl::debug( void ) {
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month" << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

// Public methods
void Harl::complain( std::string level ) {
    int levelCount = 4;
    std::locale loc;
    std::string reqLevel = level;
    std::string levels[levelCount] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    void (Harl::*logFunction[levelCount])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    for (size_t i = 0; i < level.length(); i++)
        reqLevel[i] = std::toupper(reqLevel[i], loc);

    for(int i = 0; i < levelCount; i++) {
        if (levels[i] == reqLevel) {
            (this->*logFunction[i])();
            return;
        }
    }
}

