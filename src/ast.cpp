#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

std::ostream & operator <<(std::ostream & os, const Node & node) {
    node.codegen(os);
    return os;
}

Program::Program(const std::shared_ptr<std::vector<std::shared_ptr<Instr>>> instr) : instr(instr) {
    validate(table);
}

const std::string & FuncCall::get_name() const {
    return *name;
}

std::shared_ptr<std::string> Param::get_name() const {
    return name;
}

Param::Param(const int type, const std::shared_ptr<std::string> name) : name(name) {
    if (type == VOID)
        throw std::runtime_error("Parameter \"" + *name + "\" declared \'void\'");
}

DecVar::DecVar(const int type, const std::shared_ptr<std::string> name) : name(name) {
    if (type == VOID)
        throw std::runtime_error("Variable \"" + *name + "\" declared \'void\'");
}

DecVar::DecVar(const int type, const std::shared_ptr<std::string> name, const std::shared_ptr<Expr> rhs) : name(name), rhs(rhs) {
    if (type == VOID)
        throw std::runtime_error("Variable \"" + *name + "\" declared \'void\'");
}

DecFunc::DecFunc(const int type, const std::shared_ptr<std::string> name, const std::shared_ptr<std::vector<Param>> paramlist, const std::shared_ptr<Block> block) : type(type), name(name), paramlist(paramlist), block(block) {}

DecFunc::DecFunc(const int type, const std::shared_ptr<std::string> name, const std::shared_ptr<Block> block) : type(type), name(name), block(block) {}

Block::Block(const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>> vars, const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>> stmts) : vars(vars), stmts(stmts) {}    

Assign::Assign(const std::shared_ptr<std::string> lhs, const std::shared_ptr<Expr> rhs) : lhs(lhs), rhs(rhs) {}    

If::If(const std::shared_ptr<Expr> expr, const std::shared_ptr<Block> if_block) : expr(expr), if_block(if_block) {}

If::If(const std::shared_ptr<Expr> expr, const std::shared_ptr<Block> if_block, const std::shared_ptr<Block> else_block) : expr(expr), if_block(if_block), else_block(else_block) {}    

While::While(const std::shared_ptr<Expr> expr, const std::shared_ptr<Block> block) : expr(expr), block(block) {}

Return::Return() {}

Return::Return(const std::shared_ptr<Expr> expr) : expr(expr) {}

BinOp::BinOp(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Add::Add(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Sub::Sub(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Times::Times(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Div::Div(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Less::Less(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Leq::Leq(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Great::Great(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Geq::Geq(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Eq::Eq(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Diff::Diff(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

And::And(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

Or::Or(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : BinOp(left, right) {}

UnOp::UnOp(const std::shared_ptr<Expr> expr) : expr(expr) {}

Not::Not(const std::shared_ptr<Expr> expr) : UnOp(expr) {}

Opp::Opp(const std::shared_ptr<Expr> expr) : UnOp(expr) {}

Number::Number(const std::shared_ptr<std::string> lexeme) : val(std::stoi(*lexeme)) {}

Var::Var(const std::shared_ptr<std::string> name) : name(name) {}

FuncCall::FuncCall(const std::shared_ptr<std::string> name, const std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args) : name(name), args(args) {}

FuncCall::FuncCall(const std::shared_ptr<std::string> name) : name(name) {}
