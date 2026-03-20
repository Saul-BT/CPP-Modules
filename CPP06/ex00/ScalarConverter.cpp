#include <iostream>
#include "ScalarConverter.hpp"

// Static attributes
char ScalarConverter::_cvalue = 0;
int ScalarConverter::_ivalue = 0;
float ScalarConverter::_fvalue = 0;
double ScalarConverter::_dvalue = 0;

// Constructors
ScalarConverter::ScalarConverter( void ) {
    std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & other ) {
    std::cout << "ScalarConverter: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter: Destructor called" << std::endl;
}

// Assignment operator
ScalarConverter & ScalarConverter::operator=( ScalarConverter const & other ) {
    std::cout << "ScalarConverter: Assignment operator called" << std::endl;
    if (this != &other) {
        // No dynamic allocation, so no need to copy
    }
    return *this;
}

// Private methods
bool ScalarConverter::_isChar( std::string const & value ) {
    if (value.length() != 3)
        return false;
    if (value[0] != '\'')
        return false;
    if (value[2] != '\'')
        return false;
    return true;
}

bool ScalarConverter::_isInt( std::string const & value ) {
    size_t start = 0;
    if (value[0] == '-' || value[0] == '+')
        start = 1;
    for (size_t i = start; i < value.length(); i++) {
        if (!isdigit(value[i]))
            return false;
    }
    return value.length() > 0;
}

bool ScalarConverter::_isFloat( std::string const & value ) {
    size_t last = value.length() - 1;
    if (value[last] != 'f')
        return false;
    if (!ScalarConverter::_isDouble(value.substr(0, last)))
        return false;
    return true;
}

bool ScalarConverter::_isDouble( std::string const & value ) {
    size_t dot = value.find('.');
    size_t last = value.length() - 1;
    std::string intPart = value.substr(0, dot);
    std::string floatPart = value.substr(dot + 1, last - dot);
    if (dot == std::string::npos)
        return false;
    if (intPart.length() == 0 && floatPart.length() == 0)
        return false;
    if (intPart.length() > 0 && !ScalarConverter::_isInt(intPart))
        return false;
    if (floatPart.length() > 0 && !ScalarConverter::_isInt(floatPart))
        return false;
    return true;
}

void ScalarConverter::_parseValues( std::string const & value ) {
    if (ScalarConverter::_isChar(value)) {
        std::cout << "-> debug: is char" << std::endl;
        ScalarConverter::_cvalue = value[1];
        ScalarConverter::_ivalue = static_cast<int>(ScalarConverter::_cvalue);
        ScalarConverter::_fvalue = static_cast<float>(ScalarConverter::_cvalue);
        ScalarConverter::_dvalue = static_cast<double>(ScalarConverter::_cvalue);
    }
    else if (ScalarConverter::_isInt(value)) {
        std::cout << "-> debug: is int" << std::endl;
        ScalarConverter::_ivalue = std::stoi(value);
        ScalarConverter::_fvalue = static_cast<float>(ScalarConverter::_ivalue);
        ScalarConverter::_dvalue = static_cast<double>(ScalarConverter::_ivalue);
    }
    else if (ScalarConverter::_isFloat(value)) {
        std::cout << "-> debug: is float" << std::endl;
        ScalarConverter::_fvalue = std::stof(value);
        ScalarConverter::_ivalue = static_cast<int>(ScalarConverter::_fvalue);
        ScalarConverter::_dvalue = static_cast<double>(ScalarConverter::_fvalue);
    }
    else if (ScalarConverter::_isDouble(value)) {
        std::cout << "-> debug: is double" << std::endl;
        ScalarConverter::_dvalue = std::stod(value);
        ScalarConverter::_ivalue = static_cast<int>(ScalarConverter::_dvalue);
        ScalarConverter::_fvalue = static_cast<float>(ScalarConverter::_dvalue);
    }
    else {
        std::cout << "-> debug: is invalid" << std::endl;
        std::cout << "Invalid input" << std::endl;
    }
}

// Other methods
void ScalarConverter::convert( std::string const & value ) {
    ScalarConverter::_parseValues(value);
    std::cout << "char: " << _cvalue << std::endl;
    std::cout << "int: " << _ivalue << std::endl;
    std::cout << "float: " << _fvalue << std::endl;
    std::cout << "double: " << _dvalue << std::endl;
}
