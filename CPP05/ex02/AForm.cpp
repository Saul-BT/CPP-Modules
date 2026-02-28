#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
AForm::AForm( void ) : _name("Unknown"),
                     _isSigned(false),
                     _requiredGradeToSign(1),
                     _requiredGradeToExec(1) {
    std::cout << "AForm: Default constructor called" << std::endl;
}

AForm::AForm(
        std::string const & name,
        bool isSigned,
        int requiredGradeToSign,
        int requiredGradeToExec
    ) : _name(name),
        _isSigned(isSigned),
        _requiredGradeToSign(requiredGradeToSign),
        _requiredGradeToExec(requiredGradeToExec) {
    std::cout << "AForm: Constructor with parameters called" << std::endl;
    if (requiredGradeToSign > 150 || requiredGradeToExec > 150) {
        throw AForm::GradeTooLowException();
    }
    else if (requiredGradeToSign < 1 || requiredGradeToExec < 1) {
        throw AForm::GradeTooHighException();
    }
}

AForm::AForm( AForm const & other ) {
    std::cout << "AForm: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
AForm::~AForm() {
    std::cout << "AForm: Destructor called" << std::endl;
}

// Assignment operator
AForm & AForm::operator=( AForm const & other ) {
    std::cout << "AForm: Assignment operator called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
        this->_requiredGradeToSign = other._requiredGradeToSign;
        this->_requiredGradeToExec = other._requiredGradeToExec;
    }

    return *this;
}

// Getters
const std::string & AForm::getName( void ) const {
    return this->_name;
}

bool AForm::getIsSigned( void ) const {
    return this->_isSigned;
}

int AForm::getRequiredGradeToSign( void ) const {
    return this->_requiredGradeToSign;
}

int AForm::getRequiredGradeToExec( void ) const {
    return this->_requiredGradeToExec;
}

// Other methods
void AForm::beSigned( const Bureaucrat & bureaucrat ) {
    if (this->_requiredGradeToSign < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();

    this->_isSigned = true;
}

// Dear programmer:
// When I wrote this code, only god and
// I knew how it worked.
// Now, only god knows it!
//
// Therefore, if you are trying to optimize
// this routine and it fails (most surely),
// please increase this counter as a
// warning for the next person:
//
// total_hours_wasted_here = 254
//
// Just kidding, I do this because the subject says:
// >  implement a function to execute the
// > form’s action in the concrete classes
//
// (but I know that is cleaner to have another
// virtual method here, and simply override it)
//
void AForm::execute( const Bureaucrat & executor ) const {
    if (!this->_isSigned)
        throw SignedException();
    if (this->_requiredGradeToExec < executor.getGrade())
        throw AForm::GradeTooLowException();

    if (const ShrubberyCreationForm* form = dynamic_cast<const ShrubberyCreationForm*>(this)) {
        form->makeTreeASCII();
    }
    else if (const RobotomyRequestForm* form = dynamic_cast<const RobotomyRequestForm*>(this)) {
        form->makeDrillingNoises();
    }
    else if (const PresidentialPardonForm* form = dynamic_cast<const PresidentialPardonForm*>(this)) {
        form->claimPardon();
    }
}

// Exceptions
const char * AForm::GradeTooHighException::what( void ) const throw() {
    return "Invalid Bureaucrat grade for this Form, is too high";
}

const char * AForm::GradeTooLowException::what( void ) const throw() {
    return "Invalid Bureaucrat grade for this Form, is too low";
}

const char * AForm::SignedException::what( void ) const throw() {
    return "The form must be signed to perform this action";
}

// << operator
std::ostream & operator<<( std::ostream & os, AForm const & form ) {
    os << form.getName() << ", AForm grade " << form.getRequiredGradeToSign() << std::endl;

    return os;
}
