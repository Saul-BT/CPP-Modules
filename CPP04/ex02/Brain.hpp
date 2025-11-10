#ifndef BRAIN_CLASS_H
#define BRAIN_CLASS_H

#define MAX_IDEAS 100

#include <string>
#include <iostream>

class Brain {

private:

    std::string _ideas[MAX_IDEAS];

public:

    Brain( void );
    Brain( std::string const & type );
    Brain( Brain const & other );
    ~Brain();

    Brain& operator=( Brain const & other );

    const std::string& getIdea( int idx ) const;
    void setIdea( int idx, std::string const & idea );

};

#endif
