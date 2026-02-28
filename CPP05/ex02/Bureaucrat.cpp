#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Private static methods (common logic)
int Bureaucrat::_checkGrade(int grade) {
    if  (grade <  1) 
        throw Bureaucrat::GradeTooHighException();
    if  (grade >  150)
        throw Bureaucrat::GradeTooLowException();

    return grade;
}

// Constructors
Bureaucrat::Bureaucrat( void ) : _name("Unknown"), _grade(150) {
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(
        std::string const & name, int grade
    ) : _name(name), _grade(Bureaucrat::_checkGrade(grade)) {
    std::cout << "Bureaucrat: Constructor with parameters called" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) {
    std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    *this = other;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat: Destructor called" << std::endl;
}

// Assignment operator
Bureaucrat & Bureaucrat::operator=( Bureaucrat const & other ) {
    std::cout << "Bureaucrat: Assignment operator called" << std::endl;

    if (this != &other) {
        this->_name = other._name;
        this->_grade = other._grade;
    }

    return *this;
}

// Getters
const std::string & Bureaucrat::getName( void ) const {
    return this->_name;
}

int Bureaucrat::getGrade( void ) const {
    return this->_grade;
}

// Other methods
void Bureaucrat::upgrade( void ) {
    this->_grade = Bureaucrat::_checkGrade(this->_grade - 1);
}

void Bureaucrat::downgrade( void ) {
    this->_grade = Bureaucrat::_checkGrade(this->_grade + 1);
}

void Bureaucrat::signForm( AForm & form ) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (const std::exception & e) {
        std::cout << this->_name << " couldn’t sign "
                  << form.getName() << " because "
                  << e.what() <<  "."
                  << std::endl;
    }
}

void Bureaucrat::executeForm( const AForm & form ) {
    form.execute(*this);
    std::cout << this->_name << " executed " << form.getName() << std::endl;
}

// Exceptions
const char * Bureaucrat::GradeTooHighException::what( void ) const throw() {
    return "Invalid bureaucrat grade, is too high";
}

const char * Bureaucrat::GradeTooLowException::what( void ) const throw() {
    return "Invalid bureaucrat grade, is too low";
}

// << operator
std::ostream & operator<<( std::ostream & os, Bureaucrat const & bureaucrat ) {
    os << bureaucrat.getName() << ", bureaucrat grade "
       << bureaucrat.getGrade() << "." << std::endl;

    return os;
}
