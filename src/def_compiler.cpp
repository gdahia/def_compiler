#include <iostream>
#include <vector>
#include <memory>

#include <ast.hpp>
#include <parser.hpp>

extern std::vector<std::shared_ptr<AST::Instr>> program;
extern int yyparse();

int main(int argc, char ** argv) {
    yyparse();
}
