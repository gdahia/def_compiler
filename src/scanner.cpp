#include <scanner.hpp>
#include <iostream>

using namespace lex;

Scanner::Scanner(const std::string & src_file_path) : src_file(src_file_path, std::ios::in) {
    if (!src_file.is_open())
        throw std::runtime_error("Error: unable to open source file");
    lookup = buffer.end();
}

std::string Scanner::next_word() {
    // current buffer has ended
    if (lookup == buffer.end()) {
        if (src_file >> buffer)
            lookup = buffer.begin();
        else
            return "";
    }
    
    // filter next word from current buffer
    std::string ret;
    while (lookup != buffer.end()) {
        if (!ret.empty() && followup[ret[0]] != *lookup && (is_symbol[*lookup] || is_symbol[ret[0]]))
            break;
        ret += *lookup;
        lookup++;
    }   
    
    return ret;
}

void Scanner::test_next_word() {
    std::string current_word;
    while (current_word = next_word(), !current_word.empty())
        std::cout << current_word << std::endl;
}
