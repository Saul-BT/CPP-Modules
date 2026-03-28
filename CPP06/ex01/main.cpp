#include <iostream>

#include "Serializer.hpp"


int main( void ) {
    Data data;
    data.content = "Hello World!";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Original pointer : " << &data << std::endl;
    std::cout << "Serialized (raw) : " << raw << std::endl;

    Data * deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized ptr : " << deserialized << std::endl;
    std::cout << "Content          : " << deserialized->content << std::endl;

    std::cout << "Pointers match   : "
              << (deserialized == &data ? "true" : "false") << std::endl;

    std::cout << std::endl << "== Edge cases ==" << std::endl;

    try {
        Serializer::serialize(NULL);
    } catch ( std::exception & e ) {
        std::cout << "serialize(NULL) caught: " << e.what() << std::endl;
    }

    try {
        Serializer::deserialize(0);
    } catch ( std::exception & e ) {
        std::cout << "deserialize(0) caught: " << e.what() << std::endl;
    }
    
    return 0;
}
