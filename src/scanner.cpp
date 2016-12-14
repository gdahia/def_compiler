#include <scanner.hpp>
#include <iostream>

using namespace lex;

Scanner::Scanner(const std::string & src_file_path) : src_file(src_file_path, std::ios::in) {
    if (!src_file.is_open())
        throw std::runtime_error("Error: unable to open source file");
    eof = false;
    while (!eof)
        std::cout << next_token().second << std::endl;
}

char Scanner::lookup() {
    return (eof ? -1 : looked_up);
}

void Scanner::pop_lookup() {
    // todo: see if .read() is faster than >>
    eof = (!(src_file >> std::noskipws >> looked_up));
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

std::pair<Token, std::string> Scanner::next_token() {
    std::string ret;
    
    // todo: discard comments and whitespace here
    
    // get current char
    ret += lookup();
    pop_lookup();
    
    // determine first char's nature
    if (is_alphabetical(ret[0])) {
        while (is_alphanumerical(lookup())) {
            ret += lookup();
            pop_lookup();
        }
        return std::make_pair(word_filter[ret], ret);
    }
    else if (is_numeral(ret[0])) {
        while (is_numeral(lookup())) {
            ret += lookup();
            pop_lookup();
        }
        return std::make_pair(DECIMAL, ret);
    }
    else {
        switch (ret[0]) {
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
                return std::make_pair(SYM, ret);

            case '&':
            case '|':
                if (ret[0] == lookup()) {
                    pop_lookup();
                    ret += ret[0];
                    return std::make_pair(SYM, ret);
                }
                break;

            case '=':
            case '<':
            case '>':
            case '!':
                if (lookup() == '=') {
                    pop_lookup();
                    ret += '=';
                }
                return std::make_pair(SYM, ret);
        }
    }
    
    return std::make_pair(ERROR, ret);
}
