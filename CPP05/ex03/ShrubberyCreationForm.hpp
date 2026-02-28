#ifndef SHRUBBERY_CREATION_FORM_CLASS_H
#define SHRUBBERY_CREATION_FORM_CLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:

    std::string _target;

public:

    ShrubberyCreationForm( void );
    ShrubberyCreationForm( std::string const & target );
    ShrubberyCreationForm( ShrubberyCreationForm const & other );
    ~ShrubberyCreationForm();

    const std::string & getTarget( void ) const;

    void makeTreeASCII( void ) const;

    ShrubberyCreationForm & operator=( ShrubberyCreationForm const & other );
};

std::ostream & operator<<( std::ostream & os, ShrubberyCreationForm const & form );

#endif
