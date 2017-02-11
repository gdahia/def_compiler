#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

namespace lex {
    struct Token {
        enum Type {
            ID = 0x0,
            DEC = 0x1,
            IF = 0x2,
            ELSE = 0x3,
            WHILE = 0x4,
            RETURN = 0x5,
            BREAK = 0x6,
            CONTINUE = 0x7,
            DEF = 0x8,
            INT = 0x9,
            VOID = 0xA,
            LPAR = 0xB,
            RPAR = 0xC,
            SCOLON = 0xD,
            COMMA = 0xE,
            LBRAC = 0xF,
            RBRAC = 0x10,
            PLUS = 0x11,
            MINUS = 0x12,
            STAR = 0x13,
            SLASH = 0x14,
            LESS = 0x15,
            LEQ = 0x16,
            GREAT = 0x17,
            GEQ = 0x18,
            ASS = 0x19,
            EQ = 0x1A,
            DIFF = 0x1B,
            AND = 0x1C,
            OR = 0x1D,
            NOT = 0x1E,
            COMMENT = 0x1F,
            ERROR = 0x20,
            EoF = 0x21
        };
    
        Token(Type type, const std::string & lexeme) : lexeme(lexeme), type(type) {}
        Token(Type type) : type(type) {}
        ~Token() = default;
        
        friend std::ostream & operator << (std::ostream & os, const Token & t) {
            switch (t.type) {
                case IF: os << "KEY\t\"if\""; return os;
                case ELSE: os << "KEY\t\"else\""; return os;
                case WHILE: os << "KEY\t\"while\""; return os;
                case BREAK: os << "KEY\t\"break\""; return os;
                case CONTINUE: os << "KEY\t\"continue\""; return os;
                case RETURN: os << "KEY\t\"return\""; return os;
                case INT: os << "KEY\t\"int\""; return os;
                case DEF: os << "KEY\t\"def\""; return os;
                case VOID: os << "KEY\t\"void\""; return os;
                case LPAR: os << "SYM\t\"(\""; return os;
                case RPAR: os << "SYM\t\")\""; return os;
                case LBRAC: os << "SYM\t\"{\""; return os;
                case RBRAC: os << "SYM\t\"}\""; return os;
                case NOT: os << "SYM\t\"!\""; return os;
                case EQ: os << "SYM\t\"==\""; return os;
                case ASS: os << "SYM\t\"=\""; return os;
                case SCOLON: os << "SYM\t\";\""; return os;
                case PLUS: os << "SYM\t\"+\""; return os;
                case MINUS: os << "SYM\t\"-\""; return os;
                case COMMA: os << "SYM\t\",\""; return os;
                case DIFF: os << "SYM\t\"!=\""; return os;
                case GEQ: os << "SYM\t\">=\""; return os;
                case LEQ: os << "SYM\t\"<=\""; return os;
                case GREAT: os << "SYM\t\">\""; return os;
                case LESS: os << "SYM\t\"<\""; return os;
                case STAR: os << "SYM\t\"*\""; return os;
                case SLASH: os << "SYM\t\"/\""; return os;
                case OR: os << "SYM\t\"||\""; return os;
                case AND: os << "SYM\t\"&&\""; return os;
                case ID: os << "ID\t"; break;
                case DEC: os << "DEC\t"; break;
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
        std::unordered_map<std::string, Token::Type> word_filter = {{"def", Token::Type::DEF}, {"if", Token::Type::IF}, {"else", Token::Type::ELSE}, {"while", Token::Type::WHILE}, {"break", Token::Type::BREAK}, {"void", Token::Type::VOID}, {"continue", Token::Type::CONTINUE}, {"return", Token::Type::RETURN}, {"int", Token::Type::INT}};
        
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
