#include <string>
#include <iostream>

int main ( void ) {
    std::string meh = "HI THIS IS BRAIN";
    std::string* stringPTR = &meh;
    std::string& stringREF = meh;

    std::cout << "&meh: " << &meh << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "&stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "meh: " << meh << std::endl;
    std::cout << "*stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
}
