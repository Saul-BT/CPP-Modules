#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(
        void
    ) : AForm::AForm("RobotomyRequestForm", false, 145, 137), _target("Unknown") {
    std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(
        std::string const & target
    ) : AForm::AForm("RobotomyRequestForm", false, 145, 137), _target(target) {
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

// Other methods
void RobotomyRequestForm::makeDrillingNoises( void ) const {
    std::srand(std::time(0));
    std::string message = " has been robotomized successfully";

    if (std::rand() > 0.5)
        message = " failed to be robotomized";

    std::cout << this->_target << message << std::endl;
}

// << operator
std::ostream & operator<<( std::ostream & os, RobotomyRequestForm const & robotomyRequestForm ) {
    os << robotomyRequestForm.getName() << ", RobotomyRequestForm grade " << robotomyRequestForm.getRequiredGradeToSign() << std::endl;

    return os;
}
