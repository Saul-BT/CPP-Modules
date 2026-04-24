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

    ~Array( void ) {
        delete[] this->_elements;
    }

    Array & operator=( Array const & rhs ) {
        if (this != &rhs) {
            delete[] this->_elements;
            this->_size = rhs._size;
            this->_elements = new T[this->_size]();
            for (unsigned int i = 0; i < this->_size; i++)
                this->_elements[i] = rhs._elements[i];
        }
        return *this;
    }

    T & operator[]( unsigned int index ) {
        if (index >= this->_size)
            throw std::out_of_range("Array index out of bounds");
        return this->_elements[index];
    }

    T const & operator[]( unsigned int index ) const {
        if (index >= this->_size)
            throw std::out_of_range("Array index out of bounds");
        return this->_elements[index];
    }

    unsigned int size( void ) const {
        return this->_size;
    }
};

#endif