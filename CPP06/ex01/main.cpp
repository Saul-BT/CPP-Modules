#include "Serializer.hpp"
#include <iostream>

int main( void ) {
    Data data;
    data.content = "Hello World!";

    uintptr_t raw = Serializer::serialize( &data );
    std::cout << "Raw: " << raw << std::endl;

    Data * deserialized = Serializer::deserialize( raw );
    std::cout << "Deserialized: " << deserialized->content << std::endl;
    
    return 0;
}
