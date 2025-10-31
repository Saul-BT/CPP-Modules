#include <iostream>
#include <locale>

int main(int argc, char *argv[])
{
    std::locale loc;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j]; j++)
            std::cout << std::toupper(argv[i][j], loc);
    std::cout << std::endl;    
    return 0;
}