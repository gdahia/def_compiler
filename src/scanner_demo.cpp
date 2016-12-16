#include <scanner.hpp>
#include <iostream>

int main(int argc, char ** argv) {
    if (argc <= 1) {
        std::cerr << "Error: pass input file as argument" << std::endl;
        return 1;
    }
    lex::Scanner scanner(argv[1]);
    std::vector<lex::Token> all_tokens = scanner.get_all_tokens();
    for (const lex::Token & t : all_tokens)
        std::cout << t << std::endl;
}
