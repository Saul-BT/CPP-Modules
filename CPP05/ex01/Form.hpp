#ifndef FORM_CLASS_H
#define FORM_CLASS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Bureaucrat;

class Form {

private:

    std::string _name;
    bool _isSigned;
    int _requiredGradeToSign;
    int _requiredGradeToExec;

    static int _checkGrade(int grade);

public:

    Form( void );
    Form(
        std::string const & name,
        int requiredGradeToSign,
        int requiredGradeToExec
    );
    Form( Form const & other );
    ~Form();

    Form & operator=( Form const & other );
    

    const std::string & getName( void ) const;
    bool getIsSigned( void ) const;
    int getRequiredGradeToSign( void ) const;
    int getRequiredGradeToExec( void ) const;
    void beSigned( const Bureaucrat & bureaucrat );

    class GradeTooHighException : public std::exception {

        public:

            const char * what( void ) const throw();

    };

    class GradeTooLowException : public std::exception {

        public:

            const char * what( void ) const throw();
    };
};

std::ostream & operator<<( std::ostream & os, Form const & form );

#endif
