#ifndef WRONG_CAT_CLASS_H
#define WRONG_CAT_CLASS_H

#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

    WrongCat( void );
    WrongCat( std::string const & type );
    WrongCat( WrongCat const & other );
    ~WrongCat();

    WrongCat& operator=( WrongCat const & other );

};

#endif
