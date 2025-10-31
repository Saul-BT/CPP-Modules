#ifndef PHONE_BOOK_UTILS_H
#define PHONE_BOOK_UTILS_H

#include <string>
#include <iomanip>
#include <iostream>

#define COLOR_RESET   "\033[0m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_ORANGE  "\033[38;5;214m"
#define COLOR_RED     "\033[31m"

enum MsgType {
    READ,
    WARN,
    ERROR
};

void printCell(std::string value);
void print_msg(MsgType type, const std::string& message);

#endif
