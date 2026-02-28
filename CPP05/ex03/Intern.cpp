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
AForm * Intern::createShrubbery( const std::string & target ) {
    return new ShrubberyCreationForm(target);
}

AForm * Intern::createRobotomy( const std::string & target ) {
    return new RobotomyRequestForm(target);
}

AForm * Intern::createPresidential( const std::string & target ) {
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm( const std::string & formName, const std::string & target ) const {
    struct FormEntry {
        const std::string & name;
        AForm * (*factory)(std::string const &);
    };

    static FormEntry const entries[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPresidential }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == entries[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return entries[i].factory(target);
        }
    }
    std::cout << "Intern: unknown form \"" << formName << "\"" << std::endl;
    return NULL;
}
