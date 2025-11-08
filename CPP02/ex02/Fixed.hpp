#ifndef FIXED_CLASS_H
#define FIXED_CLASS_H

#include <cmath>
#include <iostream>

class Fixed {

private:

    int _value;
    static const int _fractionalBits;

public:

    Fixed( void );
    Fixed( int const value );
    Fixed( float const value );
    Fixed( Fixed const & other );
    ~Fixed();

    Fixed& operator=( Fixed const & other );

    bool operator>( Fixed const & other ) const;
    bool operator<( Fixed const & other ) const;
    bool operator>=( Fixed const & other ) const;
    bool operator<=( Fixed const & other ) const;
    bool operator==( Fixed const & other ) const;
    bool operator!=( Fixed const & other ) const;

    Fixed operator+( Fixed const & other ) const;
    Fixed operator-( Fixed const & other ) const;
    Fixed operator*( Fixed const & other ) const;
    Fixed operator/( Fixed const & other ) const;

    Fixed& operator++( void );
    Fixed& operator--( void );
    Fixed operator++( int );
    Fixed operator--( int );

    void setRawBits( int const raw );
    int getRawBits( void ) const;

    float toFloat( void ) const;
    int toInt( void ) const;

    static Fixed& min( Fixed & f1, Fixed & f2 );
    static Fixed& max( Fixed & f1, Fixed & f2 );
    static Fixed& min( Fixed const & f1, Fixed const & f2 );
    static Fixed& max( Fixed const & f1, Fixed const & f2 );

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
