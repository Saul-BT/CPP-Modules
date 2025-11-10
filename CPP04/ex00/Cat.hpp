#ifndef CAT_CLASS_H
#define CAT_CLASS_H

#include <string>
#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {

public:

    Cat( void );
    Cat( std::string const & type );
    Cat( Cat const & other );
    ~Cat();

    Cat& operator=( Cat const & other );

    void makeSound( void ) const;

};

#endif
