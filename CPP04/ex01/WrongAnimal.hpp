#ifndef WRONG_ANIMAL_CLASS_H
#define WRONG_ANIMAL_CLASS_H

#include <string>
#include <iostream>

class WrongAnimal {

protected:

    std::string _type;

public:

    WrongAnimal( void );
    WrongAnimal( std::string const & name );
    WrongAnimal( WrongAnimal const & other );
    virtual ~WrongAnimal();

    WrongAnimal& operator=( WrongAnimal const & other );

    const std::string& getType( void ) const;
    void setType( std::string const & type );

    virtual void makeSound( void ) const;

};

#endif
