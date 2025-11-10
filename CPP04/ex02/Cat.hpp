#ifndef CAT_CLASS_H
#define CAT_CLASS_H

#include <string>
#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

private:

    Brain* _brain;

public:

    Cat( void );
    Cat( std::string const & type );
    Cat( Cat const & other );
    ~Cat();

    Cat& operator=( Cat const & other );

    Brain& getBrain( void ) const;
    void setBrain( Brain & brain );

    void makeSound( void ) const;
    void showThinking( void ) const;

};

#endif
