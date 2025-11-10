#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include <string>
#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {

public:

    Dog( void );
    Dog( std::string const & type );
    Dog( Dog const & other );
    ~Dog();

    Dog& operator=( Dog const & other );

    void makeSound( void ) const;

};

#endif
