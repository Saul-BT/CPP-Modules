#include <cctype>
#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

// Static attributes
unsigned char ScalarConverter::_cvalue = 0;
int ScalarConverter::_ivalue = 0;
float ScalarConverter::_fvalue = 0;
double ScalarConverter::_dvalue = 0;
bool ScalarConverter::_hasDecimals = false;

// Constructors
ScalarConverter::ScalarConverter( void ) {
    std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const & other ) {
    std::cout << "ScalarConverter: Copy constructor called" << std::endl;
    (void) other;
}

// Destructor
ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter: Destructor called" << std::endl;
}

// Assignment operator
ScalarConverter & ScalarConverter::operator=( ScalarConverter const & other ) {
    std::cout << "ScalarConverter: Assignment operator called" << std::endl;
    (void) other;

    return *this;
}

// Private methods
bool ScalarConverter::_isChar( std::string const & value ) {
    if (value.length() != 1)
        return false;
    if (std::isdigit(value[0]))
        return false;

    return true;
}

bool ScalarConverter::_isInt( std::string const & value ) {
    size_t start = 0;
    if (value[0] == '-' || value[0] == '+')
        start = 1;
    if (start == value.length())
        return false;
    for (size_t i = start; i < value.length(); i++) {
        if (!std::isdigit(value[i]))
            return false;
    }
    return true;
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
    if (dot == std::string::npos)
        return false;

    std::string intPart = value.substr(0, dot);
    std::string floatPart = value.substr(dot + 1, last - dot);
    if (intPart.length() == 0 && floatPart.length() == 0)
        return false;
    if (intPart.length() > 0 && !ScalarConverter::_isInt(intPart))
        return false;
    if (floatPart.length() > 0 && !ScalarConverter::_isInt(floatPart))
        return false;
    if (std::strtod(floatPart.c_str(), NULL) != 0)
        ScalarConverter::_hasDecimals = true;
    return true;
}

bool ScalarConverter::_isPseudo( std::string const & value ) {
    return (value == "nan"
        || value == "nanf"
        || value == "inf"
        || value == "+inf"
        || value == "-inf"
        || value == "inff"
        || value == "+inff"
        || value == "-inff");
}

void ScalarConverter::_parseValues( std::string const & value ) {
    ScalarConverter::_hasDecimals = false;
    if (ScalarConverter::_isChar(value)) {
        std::cout << "-> debug: is char" << std::endl;
        ScalarConverter::_cvalue = value[0];
        ScalarConverter::_ivalue = static_cast<int>(ScalarConverter::_cvalue);
        ScalarConverter::_fvalue = static_cast<float>(ScalarConverter::_cvalue);
        ScalarConverter::_dvalue = static_cast<double>(ScalarConverter::_cvalue);
    }
    else if (ScalarConverter::_isInt(value)) {
        std::cout << "-> debug: is int" << std::endl;
        long lvalue = std::strtol(value.c_str(), NULL, 10);
        ScalarConverter::_ivalue = static_cast<int>(lvalue);
        ScalarConverter::_cvalue = static_cast<char>(ScalarConverter::_ivalue);
        ScalarConverter::_fvalue = static_cast<float>(ScalarConverter::_ivalue);
        ScalarConverter::_dvalue = static_cast<double>(ScalarConverter::_ivalue);
    }
    else if (ScalarConverter::_isFloat(value)) {
        std::cout << "-> debug: is float" << std::endl;
        ScalarConverter::_fvalue = std::strtod(value.c_str(), NULL);
        ScalarConverter::_cvalue = static_cast<char>(ScalarConverter::_fvalue);
        ScalarConverter::_ivalue = static_cast<int>(ScalarConverter::_fvalue);
        ScalarConverter::_dvalue = static_cast<double>(ScalarConverter::_fvalue);
    }
    else if (ScalarConverter::_isDouble(value)) {
        std::cout << "-> debug: is double" << std::endl;
        ScalarConverter::_dvalue = std::strtod(value.c_str(), NULL);
        ScalarConverter::_cvalue = static_cast<char>(ScalarConverter::_dvalue);
        ScalarConverter::_ivalue = static_cast<int>(ScalarConverter::_dvalue);
        ScalarConverter::_fvalue = static_cast<float>(ScalarConverter::_dvalue);
    }
    else {
        throw ScalarConverter::InvalidParseException();
    }
}

void ScalarConverter::_printPseudo( std::string const & value ) {
    if (!ScalarConverter::_isPseudo(value)) throw ScalarConverter::InvalidParseException();

    size_t valueLen = value.length();
    const char* trimmed = value.c_str();
    if ((value == "nanf" || (value[valueLen - 2] == 'f' && value[valueLen - 1] == 'f'))) {
        // TODO: Check this line
        trimmed = value.substr(0, valueLen - 1).c_str();
    }
    double dValue = std::strtod(trimmed, NULL);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << dValue << "f" << std::endl;
    std::cout << "double: " << dValue << std::endl;
}

void ScalarConverter::_printChar() {
    std::cout << "char: ";
    if (ScalarConverter::_ivalue < 0 || ScalarConverter::_ivalue > 127) {
        std::cout << "impossible";
    }
    else if (std::isprint(ScalarConverter::_cvalue)) {
        std::cout << "'" << _cvalue << "'";
    }
    else {
        std::cout << "Non displayable";
    }
    std::cout << std::endl;
}

void ScalarConverter::_printInt() {
    std::cout << "int: " << _ivalue << std::endl;
}

void ScalarConverter::_printFloat() {
    std::cout << "float: " << _fvalue;
    if (!ScalarConverter::_hasDecimals) std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::_printDouble() {
    std::cout << "double: " << _dvalue;
    if (!ScalarConverter::_hasDecimals) std::cout << ".0";
    std::cout << std::endl;
}


// Other methods
void ScalarConverter::convert( std::string const & value ) {
    if (ScalarConverter::_isPseudo(value)) {
        ScalarConverter::_printPseudo(value);
        return;
    }

    try {
        ScalarConverter::_parseValues(value);
    } catch (ScalarConverter::InvalidParseException const & _e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    ScalarConverter::_printChar();
    ScalarConverter::_printInt();
    ScalarConverter::_printFloat();
    ScalarConverter::_printDouble();
}

// Exceptions
const char * ScalarConverter::InvalidParseException::what( void ) const throw() {
    return "ERROR: cannot parse value";
}
