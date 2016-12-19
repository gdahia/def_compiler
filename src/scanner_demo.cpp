#include <iostream>

#include <lex.hpp>

int main(int argc, char ** argv) {
    if (argc <= 1) {
        std::cerr << "Error: pass input file as argument" << std::endl;
        return 1;
    }
    lex::Scanner scanner(argv[1]);
    for (const lex::Token & t : scanner.get_all_tokens()) {
        std::cout << t << std::endl;
        if (t.type == lex::Token::Type::ERROR)
            return 1;
    }
}
