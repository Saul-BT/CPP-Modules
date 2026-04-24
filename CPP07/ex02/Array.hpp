#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <stdlib.h>

template <typename T>
class Array {

private:

    T * _elements;
    unsigned int _size;

public:

    Array( void ) : _elements(NULL), _size(0) {}

    Array( unsigned int n ) : _elements(new T[n]()), _size(n) {}

    Array( Array const & src ) : _elements(NULL), _size(0) {
        *this = src;
    }

    ~Array(void) {
        delete[] _elements;
    }

    Array & operator=( Array const & rhs ) {
        if (this != &rhs) {
            delete[] _elements;
            _size = rhs._size;
            _elements = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = rhs._elements[i];
        }
        return *this;
    }

    T & operator[]( unsigned int index ) {
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }

    T const & operator[]( unsigned int index ) const {
        if (index >= _size)
            throw std::exception();
        return _elements[index];
    }

    unsigned int size( void ) const {
        return _size;
    }
};

#endif