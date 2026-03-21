#ifndef SCALAR_CONVERTER_CLASS_H
#define SCALAR_CONVERTER_CLASS_H

#include <string>

class ScalarConverter {

private:

    static unsigned char _cvalue;
    static int _ivalue;
    static float _fvalue;
    static double _dvalue;
    static bool _hasDecimals;

    static bool _isChar( std::string const & value );
    static bool _isInt( std::string const & value );
    static bool _isFloat( std::string const & value );
    static bool _isDouble( std::string const & value );
    static bool _isPseudo( std::string const & value );
    static void _parseValues( std::string const & value );
    static void _printChar();
    static void _printInt();
    static void _printFloat();
    static void _printDouble();
    static void _printPseudo( std::string const & value );

    ScalarConverter( void );
    ScalarConverter( ScalarConverter const & other );
    virtual ~ScalarConverter() = 0;
    
    ScalarConverter & operator=( ScalarConverter const & other );

public:

    static void convert( std::string const & value );

    class InvalidParseException : public std::exception {

    public:

        const char * what( void ) const throw();

    };

};

#endif
