#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat( void ) : _name("Unknown"), _grade(150) {
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat: Constructor with parameters called" << std::endl;
    if (grade > 150) {
        throw GradeTooLowException();
    }
    else if (grade < 1) {
        throw GradeTooHighException();
    }
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
    if (this->_grade <= 1) {
        throw GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::downgrade( void ) {
    if (this->_grade >= 150) {
        throw GradeTooLowException();
    }
    this->_grade++;
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
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;

    return os;
}
