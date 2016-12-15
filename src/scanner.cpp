#include <scanner.hpp>
#include <iostream>

using namespace lex;

Scanner::Scanner(const std::string & src_file_path) : src_file(src_file_path, std::ios::in) {
    if (!src_file.is_open())
        throw std::runtime_error("Error: unable to open source file");
    while (src_file.peek() != EOF)
        std::cout << next_token() << std::endl;
}

bool Scanner::is_alphanumerical(const char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c >= '0' && c <= '9');
}

bool Scanner::is_alphabetical(const char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

bool Scanner::is_numeral(const char c) const {
    return (c >= '0' && c <= '9');
}

bool Scanner::is_whitespace(const char c) const {
    return c == ' ' || c == '\t' || c == '\n';
}

void Scanner::discard_whitespaces() {
    while (src_file.peek() != EOF && is_whitespace(src_file.peek()))
        src_file.get();
}

Token Scanner::next_token() {
    std::string ret;

    discard_whitespaces();
    
    // todo: throw error on no more tokens
    
    // get current char
    ret += static_cast<char>(src_file.get());
    
    // if first char is alphanumerical, then token type is either ID or KEY
    if (is_alphabetical(ret[0])) {
        // get chars while they are alphanumerical
        while (is_alphanumerical(src_file.peek()))
            ret += static_cast<char>(src_file.get());

        // match token type in hash table
        return Token(word_filter[ret], ret);
    }
    // if first char is numeral, then token type is NUM
    else if (is_numeral(ret[0])) {
        // get chars while they are numerals
        while (is_numeral(src_file.peek()))
            ret += static_cast<char>(src_file.get());

        return Token(Token::Type::DECIMAL, ret);
    }
    // if neither above, first char is either SYM or ERROR
    else {
        switch (ret[0]) {
            // match single symbol only SYMs
            case '+':
            case '-':
            case '*':
            case '/':
            case ',':
            case ';':
            case '(':
            case ')':
            case '[':
            case ']':
            case '{':
            case '}':
                return Token(Token::Type::SYM, ret);

            // match logical SYMs
            case '&':
            case '|':
                if (ret[0] == src_file.peek()) {
                    ret += static_cast<char>(src_file.get());
                    return Token(Token::Type::SYM, ret);
                }
                break;

            // match remainder of math SYMs
            case '=':
            case '<':
            case '>':
            case '!':
                // check if they are followed by '='
                if (src_file.peek() == '=')
                    ret += static_cast<char>(src_file.get());

                return Token(Token::Type::SYM, ret);
        }
    }
    
    return Token(Token::Type::ERROR, ret);
}
