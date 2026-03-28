#ifndef SCALAR_CONVERTER_CLASS_H
#define SCALAR_CONVERTER_CLASS_H

#include <string>

class ScalarConverter {

private:

    static bool _isChar( std::string const & value );
    static bool _isInt( std::string const & value );
    static bool _isFloat( std::string const & value );
    static bool _isDouble( std::string const & value );
    static bool _isPseudo( std::string const & value );
    static void _printChar( double const & raw );
    static void _printInt( double const & raw );
    static void _printFloat( double const & raw );
    static void _printDouble( double const & raw );
    static void _printPseudo( std::string const & value );

    ScalarConverter( void );
    ScalarConverter( ScalarConverter const & other );
    ~ScalarConverter();
    
    ScalarConverter & operator=( ScalarConverter const & other );

public:

    static void convert( std::string const & value );

    class InvalidFormatException : public std::exception {

    public:

        const char * what( void ) const throw();

    };

};

#endif
