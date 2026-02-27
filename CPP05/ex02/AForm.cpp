#include "AForm.hpp"
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

// Exceptions
const char * AForm::GradeTooHighException::what( void ) const throw() {
    return "Invalid AForm grade, is too high";
}

const char * AForm::GradeTooLowException::what( void ) const throw() {
    return "Invalid AForm grade, is too low";
}

// << operator
std::ostream & operator<<( std::ostream & os, AForm const & form ) {
    os << form.getName() << ", AForm grade " << form.getRequiredGradeToSign() << std::endl;

    return os;
}
