#ifndef DOG_CLASS_H
#define DOG_CLASS_H

#include <string>
#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:

    Brain* _brain;

public:

    Dog( void );
    Dog( std::string const & type );
    Dog( Dog const & other );
    ~Dog();

    Dog& operator=( Dog const & other );

    Brain& getBrain( void ) const;
    void setBrain( Brain & brain );

    void makeSound( void ) const;
    void showThinking( void ) const;

};

#endif
