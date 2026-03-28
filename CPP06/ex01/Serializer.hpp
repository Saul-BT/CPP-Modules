#ifndef SERIALIZER_CLASS_H
#define SERIALIZER_CLASS_H

#include <cstdint>
#include "Data.hpp"


class Serializer {

private:

    Serializer( void );
    Serializer( Serializer const & other );
    virtual ~Serializer() = 0;
    
    Serializer & operator=( Serializer const & other );

public:

    static uintptr_t serialize( Data * ptr );

    static Data * deserialize( uintptr_t raw );

};

#endif
