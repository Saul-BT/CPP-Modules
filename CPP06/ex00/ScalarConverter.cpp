#include <cmath>
#include <limits>
#include <cerrno>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

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

void ScalarConverter::_printPseudo( std::string const & value ) {
    if (!ScalarConverter::_isPseudo(value)) throw ScalarConverter::InvalidFormatException();

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

void ScalarConverter::_printChar( double const & raw ) {
    if (raw < 0 || raw > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char value = static_cast<char>(raw);
    std::cout << "char: ";
    if (std::isprint(value)) {
        std::cout << "'" << value << "'";
    }
    else {
        std::cout << "Non displayable";
    }

    std::cout << std::endl;
}

void ScalarConverter::_printInt( double const & raw ) {
    if (raw < -std::numeric_limits<int>::max() || raw > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
        return;
    }

    std::cout << "int: " << static_cast<int>(raw) << std::endl;
}

void ScalarConverter::_printFloat( double const & raw ) {
    if (raw < -std::numeric_limits<float>::max() || raw > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    std::cout << "float: " << static_cast<float>(raw);
    if (std::floor(raw) == raw)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::_printDouble( double const & raw ) {
    std::cout << "double: " << raw;
    if (std::floor(raw) == raw)
        std::cout << ".0";
    std::cout << std::endl;
}


// Other methods
void ScalarConverter::convert( std::string const & value ) {
    errno = 0;
    double raw;
    bool allImpossible = false;
    if (ScalarConverter::_isPseudo(value)) {
        ScalarConverter::_printPseudo(value);
        return;
    }

    if (ScalarConverter::_isChar(value))
        raw = static_cast<double>(value[0]);
    else if (ScalarConverter::_isInt(value)
          || ScalarConverter::_isFloat(value)
          || ScalarConverter::_isDouble(value))
        raw = std::strtod(value.c_str(), NULL);
    else
        allImpossible = true;

    if (allImpossible || errno == ERANGE) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    ScalarConverter::_printChar(raw);
    ScalarConverter::_printInt(raw);
    ScalarConverter::_printFloat(raw);
    ScalarConverter::_printDouble(raw);
}

// Exceptions
const char * ScalarConverter::InvalidFormatException::what( void ) const throw() {
    return "ERROR: cannot parse value";
}
