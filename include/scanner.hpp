#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <string>
#include <utility>
#include <set>
#include <map>

namespace lex {
    enum Token {ID, DECIMAL, KEY, SYM, ERROR};

    class Scanner {
    private:
        std::map<char, bool> is_symbol = {{'(', true}, {'{', true}, {'[', true}, {']', true}, {'}', true}, {')', true}, {',', true}, {';', true}, {'=', true}, {'+', true}, {'-', true}, {'*', true}, {'/', true}, {'<', true}, {'>', true}, {'&', true}, {'|', true}, {'!', true}};
        std::map<char, char> followup= {{'=', '='}, {'<', '='}, {'>', '='}, {'!', '='}, {'&', '&'}, {'|', '|'}};
        std::ifstream src_file;
        std::string buffer;
        std::string::iterator lookup;

        std::string next_word();

    public:
        Scanner(const std::string &);
        ~Scanner() {}
        Scanner(const Scanner &) = delete;
        Scanner(Scanner &&) = delete;
        Scanner operator = (const Scanner &) = delete;

        void test_next_word();
    };
}

#endif
