#ifndef BUREAUCRAT_CLASS_H
#define BUREAUCRAT_CLASS_H

#include <string>
#include <iostream>

class Bureaucrat {

private:

    std::string _name;
    int _grade;

public:

    Bureaucrat( void );
    Bureaucrat( std::string const & name, int grade );
    Bureaucrat( Bureaucrat const & other );
    ~Bureaucrat();

    Bureaucrat & operator=( Bureaucrat const & other );
    

    const std::string & getName( void ) const;
    const int & getGrade( void ) const;

    void upgrade( void );
    void downgrade( void );

    class GradeTooHighException : public std::exception {

        public:

            const char * what( void ) const throw();

    };

    class GradeTooLowException : public std::exception {

        public:

            const char * what( void ) const throw();
    };
};

std::ostream & operator<<( std::ostream & os, Bureaucrat const & bureaucrat );

#endif
