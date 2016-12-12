#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <string>

class Scanner {
private:
    std::ifstream src_file;

public:
    Scanner(const std::string &);
    ~Scanner() {}

};

#endif
