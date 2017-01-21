#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

namespace lex {
    struct Token {
        enum Type {ID = 0x0, DECIMAL = 0x2, KEY = 0x3, SYM = 0x4, COMMENT = 0x5, ERROR = 0x6, EoF = 0x7};
    
        Token(Type type, const std::string & lexeme) : lexeme(lexeme), type(type) {}
        ~Token() {}
        
        friend std::ostream & operator << (std::ostream & os, const Token & t) {
            switch (t.type) {
                case ID: os << "ID\t"; break;
                case DECIMAL: os << "DEC\t"; break;
                case KEY: os << "KEY\t"; break;
                case SYM: os << "SYM\t"; break;
                case COMMENT: os << "COMMENT\t"; break;
                case ERROR: os << "ERROR\t"; break;
                default: return os;
            }
            os << '\"' << t.lexeme << '\"';
            return os;
        }

        std::string lexeme;
        Type type;
    };
    

    class Scanner {
    private:
        std::ifstream src_file;
        std::unordered_map<std::string, Token::Type> word_filter = {{"def", Token::Type::KEY}, {"if", Token::Type::KEY}, {"else", Token::Type::KEY}, {"while", Token::Type::KEY}, {"break", Token::Type::KEY}, {"void", Token::Type::KEY}, {"continue", Token::Type::KEY}, {"return", Token::Type::KEY}, {"int", Token::Type::KEY}};
        
        void discard_whitespaces();
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

        Token next_token();
        std::vector<Token> get_all_tokens();
    };
}

#endif
