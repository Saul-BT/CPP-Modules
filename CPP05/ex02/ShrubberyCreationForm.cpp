#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(
        void
    ) : AForm::AForm("shrubbery creation", 145, 137), _target("Unknown") {
    std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
        std::string const & target
    ) : AForm::AForm("shrubbery creation", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm: Constructor with parameters called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
        ShrubberyCreationForm const & other
    ) : AForm::AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & other ) {
    std::cout << "ShrubberyCreationForm: Assignment operator called" << std::endl;

    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }

    return *this;
}

// Getters
const std::string & ShrubberyCreationForm::getTarget( void ) const {
    return this->_target;
}

// Other methods
void ShrubberyCreationForm::beExecuted( void ) const {
    std::ofstream file((this->_target + "_shrubbery").c_str());

    if (!file.is_open()) {
        std::cout << "Error: file cannot be opened" << std::endl;
        return;
    }

    file << "   *\n";
    file << "  ***\n";
    file << " *****\n";
    file << "*******\n";
    file << "  |||\n";

    file.close();
}

// << operator
std::ostream & operator<<( std::ostream & os, ShrubberyCreationForm const & form ) {
    os <<  "Form name: " << form.getName()
       <<  " | Target: " << form.getTarget()
       <<  " | Signed: " <<  (form.getIsSigned()  ?  "yes"  :  "no")
       <<  " | Grade to sign: "  << form.getRequiredGradeToSign()
       <<  " | Grade to exec: "  << form.getRequiredGradeToExec()
       << std::endl;

    return os;
}
