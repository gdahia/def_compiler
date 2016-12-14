#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <string>
#include <utility>
#include <unordered_map>

namespace lex {
    enum Token {ID = 0x0, DECIMAL = 0x2, KEY = 0x3, SYM = 0x4, ERROR = 0x5};

    class Scanner {
    private:
        std::ifstream src_file;
        bool eof;
        char looked_up;
        std::unordered_map<std::string, Token> word_filter = {{"def", KEY}, {"if", KEY}, {"else", KEY}, {"main", KEY}, {"break", KEY}, {"continue", KEY}, {"return", KEY}, {"int", KEY}};
        
        char lookup();
        void pop_lookup();
        bool is_alphanumerical(const char) const;
        bool is_alphabetical(const char) const;
        bool is_numeral(const char) const;
        bool is_whitespace(const char) const;

    public:
        Scanner(const std::string &);
        ~Scanner() {}
        Scanner(const Scanner &) = delete;
        Scanner(Scanner &&) = delete;
        Scanner operator = (const Scanner &) = delete;

        std::pair<Token, std::string> next_token();
    };
}

#endif
