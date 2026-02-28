#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    Intern anon;
    Bureaucrat supervisor("lucas", 1);
    std::string name = supervisor.getName();

    {
        AForm *form = anon.makeForm("ShrubberyCreationForm", "jardín");
    
        std::cout << std::endl << "== ShrubberyCreationForm ==" << std::endl;
        supervisor.signForm(*form);
        supervisor.executeForm(*form);
    }
    std::cout << std::endl;
    {
        AForm *form = anon.makeForm("RobotomyRequestForm", name);
    
        std::cout << std::endl << "== RobotomyRequestForm ==" << std::endl;
        supervisor.signForm(*form);
        supervisor.executeForm(*form);
    }
    std::cout << std::endl;
    {
        AForm *form = anon.makeForm("PresidentialPardonForm", name);
    
        std::cout << std::endl << "== PresidentialPardonForm ==" << std::endl;
        supervisor.signForm(*form);
        supervisor.executeForm(*form);
    }
    std::cout << std::endl;
    {
        std::cout << std::endl << "== UnknownForm ==" << std::endl;
        
        AForm *form = anon.makeForm("UnknownForm", name);

        if (form != NULL) {
            supervisor.signForm(*form);
            supervisor.executeForm(*form);
        }
    }

    return 0;
}
