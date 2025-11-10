#ifndef AANIMAL_CLASS_H
#define AANIMAL_CLASS_H

#include <string>
#include <iostream>

class AAnimal {

protected:

    std::string _type;

public:

    AAnimal( void );
    AAnimal( std::string const & name );
    AAnimal( AAnimal const & other );
    virtual ~AAnimal();

    AAnimal& operator=( AAnimal const & other );

    const std::string& getType( void ) const;
    void setType( std::string const & type );

    virtual void makeSound( void ) const = 0;

};

#endif
