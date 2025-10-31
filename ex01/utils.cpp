#include "utils.hpp"

void printCell(std::string value) {
    std::string clamped = value;
    if (!value.empty() && value.size() > 10)
        clamped = value.substr(0, 9) + '.';
    std::cout << std::setfill(' ') << std::setw (10) << clamped;
}

void print_msg(MsgType type, const std::string& message) {
    switch(type) {
        case READ:
            std::cout << COLOR_BLUE << message << COLOR_RESET << std::endl;
            break;
        case WARN:
            std::cout << COLOR_ORANGE << "[WARN] " 
                      << message << COLOR_RESET << std::endl;
            break;
        case ERROR:
            std::cerr << COLOR_RED << "[ERROR] " 
                      << message << COLOR_RESET << std::endl;
            break;
    }
}
