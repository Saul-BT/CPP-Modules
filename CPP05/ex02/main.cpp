#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    std::srand(std::time(0));

    {
        Bureaucrat god("pepe", 5);
        
        ShrubberyCreationForm shruForm("parque");
        RobotomyRequestForm roboForm(god.getName());
        PresidentialPardonForm presiForm(god.getName());
        
        std::cout << std::endl << "== Golden path example ==" << std::endl;
    
        god.signForm(shruForm);
        god.executeForm(shruForm);
    
        std::cout << std::endl;
    
        god.signForm(roboForm);
        god.executeForm(roboForm);
    
        std::cout << std::endl;
    
        god.signForm(presiForm);
        god.executeForm(presiForm);

        std::cout << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    {
        Bureaucrat juanillo("Juan", 5);
        
        ShrubberyCreationForm shruForm("zapato");
        RobotomyRequestForm roboForm(juanillo.getName());
        PresidentialPardonForm presiForm(juanillo.getName());
        
        std::cout << std::endl << "== Bad examples ==" << std::endl;
    
        try {
            juanillo.executeForm(shruForm);
        } catch (const AForm::SignedException & e) {
            std::cout << "x Onde va tu, anda pa tu casa" << std::endl;
            std::cout << "x Actual exception message: " << e.what() << std::endl;
        }

        std::cout << std::endl;

        try {
            juanillo.downgrade();
            juanillo.signForm(presiForm);
            juanillo.executeForm(presiForm);
        } catch (const AForm::GradeTooLowException & e) {
            std::cout << "x A donde vas tu payaso" << std::endl;
            std::cout << "x Actual exception message: " << e.what() << std::endl;
        }

        std::cout << std::endl;

        for (int i = 0; i < 80; i++)
            juanillo.downgrade();
        juanillo.signForm(roboForm);

        std::cout << std::endl;
    }

    return 0;
}
