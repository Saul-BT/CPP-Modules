#ifndef HARL_CLASS_H
#define HARL_CLASS_H

#include <string>
#include <iostream>
#include <locale>

class Harl {

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    void complain( std::string level );

};

#endif