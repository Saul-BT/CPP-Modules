#ifndef ROBOTOMY_REQUEST_FORM_CLASS_H
#define ROBOTOMY_REQUEST_FORM_CLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:

    std::string _target;

    static const int REQUIRED_GRADE_TO_SIGN;
    static const int REQUIRED_GRADE_TO_EXEC;

protected:

    void beExecuted( void ) const;

public:

    RobotomyRequestForm( void );
    RobotomyRequestForm( std::string const & target );
    RobotomyRequestForm( RobotomyRequestForm const & other );
    ~RobotomyRequestForm();

    const std::string & getTarget( void ) const;

    RobotomyRequestForm & operator=( RobotomyRequestForm const & other );
};

std::ostream & operator<<( std::ostream & os, RobotomyRequestForm const & form );

#endif
