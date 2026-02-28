#ifndef INTERN_CLASS_H
#define INTERN_CLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "AForm.hpp"

class Intern : public AForm {

public:

    Intern( void );
    Intern( Intern const & other );
    ~Intern();

    AForm * makeForm( const std::string & formName, const std::string & target ) const;

    Intern & operator=( Intern const & other );
};

std::ostream & operator<<( std::ostream & os, Intern const & intern );

#endif
