#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(
        void
    ) : AForm::AForm("PresidentialPardonForm", false, 25, 5), _target("Unknown") {
    std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
        std::string const & target
    ) : AForm::AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
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

// Other methods
void PresidentialPardonForm::claimPardon( void ) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// << operator
std::ostream & operator<<( std::ostream & os, PresidentialPardonForm const & form ) {
    os << form.getName() << ", PresidentialPardonForm grade " << form.getRequiredGradeToSign() << std::endl;

    return os;
}
