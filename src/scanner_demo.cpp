#include <iostream>
#include <fstream>

#include <lex.hpp>

int main(int argc, char ** argv) {
    if (argc < 1) {
        std::cerr << "Error: pass input file as argument" << std::endl;
        return 1;
    }
    else if (argc > 2) {
        std::ofstream output_file(argv[2]);
        if (!output_file.is_open()) {
            std::cerr << "Error: unable to open output file " << argv[2] << std::endl;
            return 1;
        }
        
        lex::Scanner scanner(argv[1]);
        for (const lex::Token & t : scanner.get_all_tokens()) {
            if (t.type == lex::Token::Type::ERROR) {
                std::cerr << t << std::endl;
                return 1;
            }
            else
                output_file << t << std::endl;
        }
    }
    else {
        lex::Scanner scanner(argv[1]);
        for (const lex::Token & t : scanner.get_all_tokens()) {
            if (t.type == lex::Token::Type::ERROR) {
                std::cerr << t << std::endl;
                return 1;
            }
            else
                std::cout << t << std::endl;
        }
    }
}
