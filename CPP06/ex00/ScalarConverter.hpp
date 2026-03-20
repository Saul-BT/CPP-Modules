#ifndef SCALAR_CONVERTER_CLASS_H
#define SCALAR_CONVERTER_CLASS_H

#include <string>

class ScalarConverter {

private:

    static char _cvalue;
    static int _ivalue;
    static float _fvalue;
    static double _dvalue;

    static bool _isChar( std::string const & value );
    static bool _isInt( std::string const & value );
    static bool _isFloat( std::string const & value );
    static bool _isDouble( std::string const & value );
    static void _parseValues( std::string const & value );

public:

    ScalarConverter( void );
    ScalarConverter( ScalarConverter const & other );
    virtual ~ScalarConverter() = 0;

    ScalarConverter & operator=( ScalarConverter const & other );
    

    static void convert( std::string const & value );

};

#endif
