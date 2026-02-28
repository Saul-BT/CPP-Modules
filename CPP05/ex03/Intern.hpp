#ifndef INTERN_CLASS_H
#define INTERN_CLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "AForm.hpp"

class Intern {

private:

    static AForm * createShrubbery( const std::string & target );
    static AForm * createRobotomy( const std::string & target );
    static AForm * createPresidential( const std::string & target );

public:

    Intern( void );
    Intern( Intern const & other );
    ~Intern();

    AForm * makeForm( const std::string & formName, const std::string & target ) const;

    Intern & operator=( Intern const & other );
};

#endif
