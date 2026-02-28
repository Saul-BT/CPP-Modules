#ifndef AFORM_CLASS_H
#define AFORM_CLASS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Bureaucrat;

class AForm {

private:

    const  std::string _name;
    bool _isSigned;
    const int _requiredGradeToSign;
    const int _requiredGradeToExec;

    static int _checkGrade(int grade);

protected:

    virtual void beExecuted( void ) const = 0;

public:

    AForm( void );
    AForm(
        std::string const & name,
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

    class SignedException : public std::exception {

        public:

            const char * what( void ) const throw();
    };
};

std::ostream & operator<<( std::ostream & os, AForm const & form );

#endif
