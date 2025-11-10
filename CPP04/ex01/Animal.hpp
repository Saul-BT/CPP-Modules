#ifndef ANIMAL_CLASS_H
#define ANIMAL_CLASS_H

#include <string>
#include <iostream>

class Animal {

protected:

    std::string _type;

public:

    Animal( void );
    Animal( std::string const & name );
    Animal( Animal const & other );
    virtual ~Animal();

    Animal& operator=( Animal const & other );

    const std::string& getType( void ) const;
    void setType( std::string const & type );

    virtual void makeSound( void ) const;

};

#endif
