#ifndef HOLDER_HPP
#define HOLDER_HPP

#include <vector>
#include <string>
#include <memory>

struct Holder {
    std::shared_ptr<AST::Expr> expr;
    std::shared_ptr<std::vector<std::shared_ptr<AST::Expr>>> args;
    std::shared_ptr<AST::FuncCall> funccall;
    std::shared_ptr<AST::Stmt> stmt;
    std::shared_ptr<AST::Block> block;
    std::shared_ptr<std::vector<std::shared_ptr<AST::Stmt>>> stmts;
    std::shared_ptr<std::vector<std::shared_ptr<AST::DecVar>>> decvars;
    std::shared_ptr<std::vector<AST::Param>> params;
    std::shared_ptr<AST::DecVar> decvar;
    std::shared_ptr<AST::DecFunc> decfunc;
    std::shared_ptr<std::string> lexeme;
    std::shared_ptr<std::vector<std::shared_ptr<AST::Instr>>> instr;
    int token;
};

#endif
