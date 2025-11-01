#include <fstream>
#include <string>
#include <iostream>

void replace(
    std::string & str,
    std::string const & search,
    std::string const & replace
) {
    size_t idx = 0;

    while((idx = str.find(search, idx)) != std::string::npos) {
        str.erase(idx, search.length());
        str.insert(idx, replace);
        idx += replace.length();
    }
}

int main( int argc, char* argv[] ) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::ifstream fileIn(argv[1]);
    if (!fileIn.is_open()) {
        std::cerr << "The file '" << argv[1] << "' can't be opened" << std::endl;
        return 2;
    }
    
    std::ofstream fileOut((std::string(argv[1]) + ".replace").c_str());
    if (!fileOut.is_open()) {
        std::cerr << "The file '" << argv[1] << "' can't be opened" << std::endl;
        return 2;
    }
    
    std::string line;
    while (getline(fileIn, line)) {
        replace(line, argv[2], argv[3]);
        fileOut << line << std::endl;
    }

    fileIn.close();
    fileOut.close();
    return 0;
}
