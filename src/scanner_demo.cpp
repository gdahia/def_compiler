#include <scanner.hpp>
#include <iostream>

int main(int argc, char ** argv) {
    if (argc <= 1) {
        std::cerr << "Error: pass input file as argument" << std::endl;
        return 1;
    }
    lex::Scanner scanner(argv[1]);
}
