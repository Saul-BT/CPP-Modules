#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_H
#define PRESIDENTIAL_PARDON_FORM_CLASS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:

    std::string _target;

public:

    PresidentialPardonForm( void );
    PresidentialPardonForm( std::string const & target );
    PresidentialPardonForm( PresidentialPardonForm const & other );
    ~PresidentialPardonForm();

    void claimPardon( void ) const;

    PresidentialPardonForm & operator=( PresidentialPardonForm const & other );
};

std::ostream & operator<<( std::ostream & os, PresidentialPardonForm const & form );

#endif
