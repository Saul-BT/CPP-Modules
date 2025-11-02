#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <iostream>

class Fixed {

private:

    int _value;
    static const int _fractionalBits;

public:

    Fixed( void );
    Fixed( int const value );
    Fixed( Fixed const & other );
    ~Fixed();

    Fixed& operator=( Fixed const & other );

    void setRawBits( int const raw );
    int getRawBits( void ) const;

};

#endif
