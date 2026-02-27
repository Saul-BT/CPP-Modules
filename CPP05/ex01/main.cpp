#include "Form.hpp"
#include "Bureaucrat.hpp"

int main( void ) {
    Form tiovivo("tiovivo", false, 10, 10);
    Bureaucrat jaimito("jaimito", 6);
    Bureaucrat sigismundo("sigismundo", 94);

    std::cout << "== Good example ==" << std::endl;

    jaimito.signForm(tiovivo);
    tiovivo.beSigned(jaimito);

    std::cout << std::endl << "== Bad examples ==" << std::endl;

    sigismundo.signForm(tiovivo);

    try {
        tiovivo.beSigned(sigismundo);
    } catch (const Form::GradeTooLowException & e) {
        std::cerr << "x Sigismundo broke his leg when trying to jump the tiovivo's fence" << std::endl;
        std::cerr << "x Actual exception message: " << e.what() << std::endl;
    }
}
