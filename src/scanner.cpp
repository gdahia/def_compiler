#include <scanner.hpp>

Scanner::Scanner(const std::string & src_file_path) : src_file(src_file_path, std::ios::in) {
    if (!src_file.is_open())
        throw std::runtime_error("Error: unable to open source file");
}
