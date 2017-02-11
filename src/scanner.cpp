#include <lex.hpp>

using namespace lex;

Scanner::Scanner(const std::string & src_file_path) : src_file(src_file_path, std::ios::in) {
    if (!src_file.is_open())
        throw std::runtime_error("Error: unable to open source file");
}

bool Scanner::is_alphanumerical(const char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c >= '0' && c <= '9');
}

bool Scanner::is_alphabetical(const char c) const {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
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
    discard_whitespaces();
    
    // no more tokens filter
    if (src_file.peek() == EOF)
        return Token(Token::Type::EoF);
    
    // get current char
    std::string ret;
    ret += static_cast<char>(src_file.get());
    
    if (is_alphabetical(ret[0])) {
        // if first char is alphabetical, then token type is either ID or KEY
        // get chars while they are alphanumerical
        while (is_alphanumerical(src_file.peek()))
            ret += static_cast<char>(src_file.get());

        // match token type in hash table
        Token::Type t = word_filter[ret];
        if (t == Token::Type::ID)
            return Token(t, ret);
        else
            return Token(t);
    }
    else if (is_numeral(ret[0])) {
        // if first char is numeral, then token type is NUM
        // get chars while they are numerals
        while (is_numeral(src_file.peek()))
            ret += static_cast<char>(src_file.get());

        return Token(Token::Type::DEC, ret);
    }
    else {
        // if neither above, first char is either SYM or ERROR
        switch (ret[0]) {
            // match slash and eventually comments
            case '/':
                if (src_file.peek() == '/') {
                    ret += static_cast<char>(src_file.get());
                    // discard whole comment
                    while (src_file.peek() != EOF && src_file.peek() != '\n')
                        ret += static_cast<char>(src_file.get());
                    return Token(Token::Type::COMMENT);
                }
            return Token(Token::Type::SLASH);
            // match single symbol only SYMs
            case '+': return Token(Token::Type::PLUS);
            case '-': return Token(Token::Type::MINUS);
            case '*': return Token(Token::Type::STAR);
            case ',': return Token(Token::Type::COMMA);
            case ';': return Token(Token::Type::SCOLON);
            case '(': return Token(Token::Type::LPAR);
            case ')': return Token(Token::Type::RPAR);
            case '{': return Token(Token::Type::LBRAC);
            case '}': return Token(Token::Type::RBRAC);
            // match logical SYMs
            case '&':
                if ('&' == src_file.peek()) {
                    src_file.get();
                    return Token(Token::Type::AND);
                }
            break;
            case '|':
                if ('|' == src_file.peek()) {
                    src_file.get();
                    return Token(Token::Type::OR);
                }
            break;
            // match symbols that could be followed by =
            case '=':
                if ('=' == src_file.peek()) {
                    src_file.get();
                    return Token(Token::Type::EQ);
                }
                else
                    return Token(Token::Type::ASS);
            case '<':
                if ('=' == src_file.peek()) {
                    src_file.get();
                    return Token(Token::Type::LEQ);
                }
                else
                    return Token(Token::Type::LESS);
            case '>':
                if ('=' == src_file.peek()) {
                    src_file.get();
                    return Token(Token::Type::GEQ);
                }
                else
                    return Token(Token::Type::GREAT);
            case '!':
                if ('=' == src_file.peek()) {
                    src_file.get();
                    return Token(Token::Type::DIFF);
                }
                else
                    return Token(Token::Type::NOT);
        }
    }
    
    return Token(Token::Type::ERROR, ret);
}

std::vector<Token> Scanner::get_all_tokens() {
    std::vector<Token> ret;
    while (src_file.peek() != EOF) {
        Token next = next_token();
        if (next.type != Token::Type::EoF && next.type != Token::Type::COMMENT)
            ret.push_back(next);
    }
    return ret;
}
