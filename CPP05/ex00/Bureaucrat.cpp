#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat( void ) : _name("Unknown"), _grade(150) {
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name), _grade(grade) {
    if (grade > 150) {
        throw GradeTooHighException();
    }
    else if (grade < 0) {
        throw GradeTooLowException();
    }
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

const int & Bureaucrat::getGrade( void ) const {
    return this->_grade;
}

// Other methods
void Bureaucrat::upgrade( void ) {
    if (this->_grade <= 0) {
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
