#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constants
const int PresidentialPardonForm::REQUIRED_GRADE_TO_SIGN = 25;
const int PresidentialPardonForm::REQUIRED_GRADE_TO_EXEC = 5;

// Constructors
PresidentialPardonForm::PresidentialPardonForm(
        void
    ) : AForm::AForm(
        "presidential pardon",
        PresidentialPardonForm::REQUIRED_GRADE_TO_SIGN,
        PresidentialPardonForm::REQUIRED_GRADE_TO_EXEC
    ), _target("Unknown") {
    std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
        std::string const & target
    ) : AForm::AForm(
        "presidential pardon",
        PresidentialPardonForm::REQUIRED_GRADE_TO_SIGN,
        PresidentialPardonForm::REQUIRED_GRADE_TO_EXEC
    ), _target(target) {
    std::cout << "PresidentialPardonForm: Constructor with parameters called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
        PresidentialPardonForm const & other
    ) : AForm::AForm(other), _target(other._target) {
    std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & other ) {
    std::cout << "PresidentialPardonForm: Assignment operator called" << std::endl;

    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }

    return *this;
}

// Getters
const std::string & PresidentialPardonForm::getTarget( void ) const {
    return this->_target;
}

// Other methods
void PresidentialPardonForm::beExecuted( void ) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// << operator
std::ostream & operator<<( std::ostream & os, PresidentialPardonForm const & form ) {
    os <<  "Form name: " << form.getName()
       <<  " | Target: " << form.getTarget()
       <<  " | Signed: " <<  (form.getIsSigned()  ?  "yes"  :  "no")
       <<  " | Grade to sign: "  << form.getRequiredGradeToSign()
       <<  " | Grade to exec: "  << form.getRequiredGradeToExec()
       << std::endl;

    return os;
}
