#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern( void ) {
    std::cout << "Intern: Default constructor called" << std::endl;
}

Intern::Intern( Intern const & other ) {
    std::cout << "Intern: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Intern::~Intern() {
    std::cout << "Intern: Destructor called" << std::endl;
}

// Assignment operator
Intern & Intern::operator=( Intern const & other ) {
    std::cout << "Intern: Assignment operator called" << std::endl;
    (void) other;

    return *this;
}

// Other methods
AForm * Intern::makeForm( const std::string & formName, const std::string & target ) const {
    AForm *request = NULL;
    AForm *forms[3];
    forms[0] = new ShrubberyCreationForm(target);
    forms[1] = new RobotomyRequestForm(target);
    forms[2] = new PresidentialPardonForm(target);

    for (int i = 0; i < 3; i++) {
        if (forms[i]->getName() == formName)
            request = forms[i];
        else
            delete forms[i];
    }

    if (request == NULL)
        std::cerr << "Sorry, the requested form wasn't found" << std::endl;
    else
        std::cout << "Intern creates " << formName << std::endl;

    return request;
}
