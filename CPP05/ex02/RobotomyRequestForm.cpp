#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(
        void
    ) : AForm::AForm("robotomy request", 72, 45), _target("Unknown") {
    std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(
        std::string const & target
    ) : AForm::AForm("robotomy request", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm: Constructor with parameters called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(
        RobotomyRequestForm const & other
    ) : AForm::AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & other ) {
    std::cout << "RobotomyRequestForm: Assignment operator called" << std::endl;

    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }

    return *this;
}

// Getters
const std::string & RobotomyRequestForm::getTarget( void ) const {
    return this->_target;
}

// Other methods
void RobotomyRequestForm::beExecuted( void ) const {
    std::string message = " has been robotomized successfully";

    if (std::rand() > RAND_MAX / 2)
        message = " failed to be robotomized";

    std::cout << "* drrr drrrrr drrr *" << std::endl;
    std::cout << this->_target << message << std::endl;
}

// << operator
std::ostream & operator<<( std::ostream & os, RobotomyRequestForm const & form ) {
    os <<  "Form name: " << form.getName()
       <<  " | Target: " << form.getTarget()
       <<  " | Signed: " <<  (form.getIsSigned()  ?  "yes"  :  "no")
       <<  " | Grade to sign: "  << form.getRequiredGradeToSign()
       <<  " | Grade to exec: "  << form.getRequiredGradeToExec()
       << std::endl;

    return os;
}
