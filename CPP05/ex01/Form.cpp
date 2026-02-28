#include "Form.hpp"
#include "Bureaucrat.hpp"

// Private static methods (common logic)
int Form::_checkGrade(int grade) {
    if  (grade <  1) 
        throw Form::GradeTooHighException();
    if  (grade >  150)
        throw Form::GradeTooLowException();

    return grade;
}

// Constructors
Form::Form( void ) : _name("Unknown"),
                     _isSigned(false),
                     _requiredGradeToSign(1),
                     _requiredGradeToExec(1) {
    std::cout << "Form: Default constructor called" << std::endl;
}

Form::Form(
        std::string const & name,
        int requiredGradeToSign,
        int requiredGradeToExec
    ) : _name(name),
        _isSigned(false),
        _requiredGradeToSign(Form::_checkGrade(requiredGradeToSign)),
        _requiredGradeToExec(Form::_checkGrade(requiredGradeToExec)) {
    std::cout << "Form: Constructor with parameters called" << std::endl;
}

Form::Form( Form const & other ) {
    std::cout << "Form: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Form::~Form() {
    std::cout << "Form: Destructor called" << std::endl;
}

// Assignment operator
Form & Form::operator=( Form const & other ) {
    std::cout << "Form: Assignment operator called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_isSigned = other._isSigned;
        this->_requiredGradeToSign = other._requiredGradeToSign;
        this->_requiredGradeToExec = other._requiredGradeToExec;
    }

    return *this;
}

// Getters
const std::string & Form::getName( void ) const {
    return this->_name;
}

bool Form::getIsSigned( void ) const {
    return this->_isSigned;
}

int Form::getRequiredGradeToSign( void ) const {
    return this->_requiredGradeToSign;
}

int Form::getRequiredGradeToExec( void ) const {
    return this->_requiredGradeToExec;
}

// Other methods
void Form::beSigned( const Bureaucrat & bureaucrat ) {
    if (this->_requiredGradeToSign < bureaucrat.getGrade())
        throw Form::GradeTooLowException();

    this->_isSigned = true;
}

// Exceptions
const char * Form::GradeTooHighException::what( void ) const throw() {
    return "Invalid Bureaucrat grade for this Form, is too high";
}

const char * Form::GradeTooLowException::what( void ) const throw() {
    return "Invalid Bureaucrat grade for this Form, is too low";
}

// << operator
std::ostream & operator<<( std::ostream & os, Form const & form ) {
    os << form.getName() << ", Form grade " << form.getRequiredGradeToSign() << std::endl;

    return os;
}
