#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    std::srand(std::time(0));
    Intern anon;
    Bureaucrat supervisor("lucas", 1);
    std::string name = supervisor.getName();

    AForm *form = anon.makeForm("shrubbery creation", "jardín");

    std::cout << std::endl << "== ShrubberyCreationForm ==" << std::endl;
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;

    std::cout << std::endl;

    form = anon.makeForm("robotomy request", name);

    std::cout << std::endl << "== RobotomyRequestForm ==" << std::endl;
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;

    std::cout << std::endl;

    form = anon.makeForm("presidential pardon", name);
    
    std::cout << std::endl << "== PresidentialPardonForm ==" << std::endl;
    supervisor.signForm(*form);
    supervisor.executeForm(*form);
    delete form;

    std::cout << std::endl;

    std::cout << std::endl << "== UnknownForm ==" << std::endl;
    
    form = anon.makeForm("UnknownForm", name);

    if (form != NULL) {
        supervisor.signForm(*form);
        supervisor.executeForm(*form);
        delete form;
    }

    return 0;
}
