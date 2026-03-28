#ifndef SERIALIZER_CLASS_H
#define SERIALIZER_CLASS_H

#include <stdint.h>

#include "Data.hpp"


class Serializer {

private:

    Serializer( void );
    Serializer( Serializer const & other );
    ~Serializer();
    
    Serializer & operator=( Serializer const & other );

public:

    static uintptr_t serialize( Data * ptr );

    static Data * deserialize( uintptr_t raw );

};

#endif
