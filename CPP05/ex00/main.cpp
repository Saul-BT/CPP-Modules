#include "Bureaucrat.hpp"

int main( void ) {
    std::srand(std::time(0));
    Bureaucrat juan;
    Bureaucrat pepe("pepe", 1);

    
    std::cout << "== Bad examples ==" << std::endl;

    try {
        juan.downgrade();
    } catch (const Bureaucrat::GradeTooLowException & e) {
        std::cout << "x Juan can do it better, exploited with GradeTooLowException" << std::endl;
        std::cout << "x Actual exception message: " << e.what() << std::endl;
    }
    
    try {
        pepe.upgrade();
    } catch (const Bureaucrat::GradeTooHighException & e) {
        std::cout << "x Pepe's head is flying, to much power" << std::endl;
        std::cout << "x Actual exception message: " << e.what() << std::endl;
    }

    try {
        Bureaucrat maria("maria", 0);
    } catch (const Bureaucrat::GradeTooHighException & e) {
        std::cout << "x Maria never exists" << std::endl;
        std::cout << "x Actual exception message: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lucas("lucas", 151);
    } catch (const Bureaucrat::GradeTooLowException & e) {
        std::cout << "x Lucas? Where are u?" << std::endl;
        std::cout << "x Actual exception message: " << e.what() << std::endl;
    }

    try {
        int grade = std::rand() % 401 - 200;
        Bureaucrat loquillo("loquillo", grade);

        std::cout << loquillo << std::endl;

        if (std::rand() > RAND_MAX / 2)
            loquillo.upgrade();
        else
            loquillo.downgrade();

        std::cout << loquillo << std::endl;
    } catch (const std::exception & e) {
        std::cout << "x loquillo illo k ase?" << std::endl;
        std::cout << "x Actual exception message: " << e.what() << std::endl;
    }

    std::cout << std::endl << "== Good examples ==" << std::endl;

    Bureaucrat laura("laura", 5);

    std::cout << laura << std::endl;

    laura.upgrade();

    std::cout << laura << std::endl;

    Bureaucrat claudia("claudia", 67);

    std::cout << claudia << std::endl;

    claudia.upgrade();

    std::cout << claudia << std::endl;

    return 0;
}
