#ifndef AFORM_CLASS_H
#define AFORM_CLASS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Bureaucrat;

class AForm {

private:

    std::string _name;
    bool _isSigned;
    int _requiredGradeToSign;
    int _requiredGradeToExec;

public:

    AForm( void );
    AForm(
        std::string const & name,
        bool isSigned,
        int requiredGradeToSign,
        int requiredGradeToExec
    );
    AForm( AForm const & other );
    virtual ~AForm();

    AForm & operator=( AForm const & other );
    
    const std::string & getName( void ) const;
    bool getIsSigned( void ) const;
    int getRequiredGradeToSign( void ) const;
    int getRequiredGradeToExec( void ) const;

    void beSigned( const Bureaucrat & bureaucrat );
    void execute( const Bureaucrat & executor ) const;

    class GradeTooHighException : public std::exception {

        public:

            const char * what( void ) const throw();

    };

    class GradeTooLowException : public std::exception {

        public:

            const char * what( void ) const throw();
    };
};

std::ostream & operator<<( std::ostream & os, AForm const & bureaucrat );

#endif
