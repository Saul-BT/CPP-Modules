#ifndef BUREAUCRAT_CLASS_H
#define BUREAUCRAT_CLASS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class AForm;

class Bureaucrat {

private:

    const  std::string _name;
    int _grade;

    static int _checkGrade(int grade);

public:

    Bureaucrat( void );
    Bureaucrat( std::string const & name, int grade );
    Bureaucrat( Bureaucrat const & other );
    ~Bureaucrat();

    Bureaucrat & operator=( Bureaucrat const & other );
    

    const std::string & getName( void ) const;
    int getGrade( void ) const;

    void upgrade( void );
    void downgrade( void );
    void signForm( AForm & form );
    void executeForm( const AForm & form );

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
