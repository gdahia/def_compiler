#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

std::ostream & operator <<(std::ostream & os, const Node & node) {
    node.print(os);
    return os;
}

void Program::print(std::ostream & os) const {
    os << "[program";
    for (auto i = instr.rbegin(); i != instr.rend(); i++)
        os << " " << **i;
    os << "]";
}

void Param::print(std::ostream & os) const {
    os << "[" << *name << "]";
}

void Block::print(std::ostream & os) const {
    os << "[block";
    for (auto d = vars->rbegin(); d != vars->rend(); d++)
        os << " " << **d;
    for (auto d = stmts->rbegin(); d != stmts->rend(); d++)
        os << " " << **d;
    os << "]";
}

void Assign::print(std::ostream & os) const {
    os << "[assign [" << *lhs << "] " << *rhs << "]"; 
}

void If::print(std::ostream & os) const {
    os << "[if " << *expr << " " << *if_block;
    if (else_block)
        os << " " << *else_block;
    os << "]";
}

void Return::print(std::ostream & os) const {
    os << "[return";
    if (expr)
        os << " " << *expr;
    os << "]";
}

void Continue::print(std::ostream & os) const {
    os << "[continue]";
}

void Break::print(std::ostream & os) const {
    os << "[break]";
}

void While::print(std::ostream & os) const {
    os << "[while " << *expr << " " << *block;
}

void DecVar::print(std::ostream & os) const {
    os << "[decvar [" << *name << "]";
    if (rhs)
        os << " " << *rhs;
    os << "]";
}

void DecFunc::print(std::ostream & os) const {
    os << "[decfunc [" << *name << "] [paramlist";
    if (paramlist)
        for (auto param = paramlist->rbegin(); param != paramlist->rend(); param++)
            os << " " << *param;
    os << "] " << *block << "]";
}

void Add::print(std::ostream & os) const {
    os << "[+ " << *left << " " << *right << "]";
}

void Sub::print(std::ostream & os) const {
    os << "[- " << *left << " " << *right << "]";
}

void Or::print(std::ostream & os) const {
    os << "[|| " << *left << " " << *right << "]";
}

void And::print(std::ostream & os) const {
    os << "[&& " << *left << " " << *right << "]";
}

void Times::print(std::ostream & os) const {
    os << "[* " << *left << " " << *right << "]";
}

void Div::print(std::ostream & os) const {
    os << "[/ " << *left << " " << *right << "]";
}

void Not::print(std::ostream & os) const {
    os << "[! " << *expr << "]";
}

void Opp::print(std::ostream & os) const {
    os << "[- " << *expr << "]";
}

void Less::print(std::ostream & os) const {
    os << "[< " << *left << " " << *right << "]";
}

void Leq::print(std::ostream & os) const {
    os << "[<= " << *left << " " << *right << "]";
}

void Great::print(std::ostream & os) const {
    os << "[> " << *left << " " << *right << "]";
}

void Geq::print(std::ostream & os) const {
    os << "[>= " << *left << " " << *right << "]";
}

void Eq::print(std::ostream & os) const {
    os << "[== " << *left << " " << *right << "]";
}

void Diff::print(std::ostream & os) const {
    os << "[!= " << *left << " " << *right << "]";
}

void Number::print(std::ostream & os) const {
    os << "[" << val << "]";
}

void Var::print(std::ostream & os) const {
    os << "[" << *name << "]";
}

void FuncCall::print(std::ostream & os) const {
    os << "[" << *name;
}

Param::Param(const int type, const std::shared_ptr<std::string> name) : name(name) {
    if (type == VOID)
        throw std::runtime_error("Parameter " + *name + " declared \'void\'");
}

DecVar::DecVar(const int type, const std::shared_ptr<std::string> name) : name(name) {
    if (type == VOID)
        throw std::runtime_error("Variable " + *name + " declared \'void\'");
}

DecVar::DecVar(const int type, const std::shared_ptr<std::string> name, const std::shared_ptr<Expr> rhs) : name(name), rhs(rhs) {
    if (type == VOID)
        throw std::runtime_error("Variable " + *name + " declared \'void\'");
}

DecFunc::DecFunc(const int type, const std::shared_ptr<std::string> name, const std::shared_ptr<std::vector<Param>> paramlist, const std::shared_ptr<Block> block) : name(name), paramlist(paramlist), block(block) {
    if (type == VOID && block->has_int_return())
        throw std::runtime_error("Function " + *name + " has type \'void\' but returns an \'int\'");
    if (type == INT && block->has_void_return())
        throw std::runtime_error("Function " + *name + " has type \'int\' but returns no \'int\'");
}

bool Block::has_int_return() const {
    for (auto stmt : *stmts)
        if (Return * ret = dynamic_cast<Return *>(stmt.get()))
            if (ret->has_val())
                return true;
    return false;
}

bool Block::has_void_return() const {
    for (auto stmt : *stmts)
        if (Return * ret = dynamic_cast<Return *>(stmt.get()))
            if (!ret->has_val())
                return true;
    return false;       
}

bool Return::has_val() const {
    return (expr ? true : false);
}

DecFunc::DecFunc(const int type, const std::shared_ptr<std::string> name, const std::shared_ptr<Block> block) : name(name), block(block) {
    if (type == VOID && block->has_int_return())
        throw std::runtime_error("Function " + *name + " has type \'void\' but returns an \'int\'");
    if (type == INT && block->has_void_return())
        throw std::runtime_error("Function " + *name + " has type \'int\' but returns no \'int\'");
}

Block::Block(const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>> vars, const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>> stmts) : vars(vars), stmts(stmts) {}    

Assign::Assign(const std::shared_ptr<std::string> lhs, const std::shared_ptr<Expr> rhs) : lhs(lhs), rhs(rhs) {}    

If::If(const std::shared_ptr<Expr> expr, const std::shared_ptr<Block> if_block) : expr(expr), if_block(if_block) {}

If::If(const std::shared_ptr<Expr> expr, const std::shared_ptr<Block> if_block, const std::shared_ptr<Block> else_block) : expr(expr), if_block(if_block), else_block(else_block) {}    

While::While(const std::shared_ptr<Expr> expr, const std::shared_ptr<Block> block) : expr(expr), block(block) {}

Return::Return() {}

Return::Return(const std::shared_ptr<Expr> expr) : expr(expr) {}

Add::Add(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Sub::Sub(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Times::Times(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Div::Div(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Less::Less(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Leq::Leq(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Great::Great(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Geq::Geq(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Eq::Eq(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Diff::Diff(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

And::And(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Or::Or(const std::shared_ptr<Expr> left, const std::shared_ptr<Expr> right) : left(left), right(right) {}

Not::Not(const std::shared_ptr<Expr> expr) : expr(expr) {}

Opp::Opp(const std::shared_ptr<Expr> expr) : expr(expr) {}

Number::Number(const std::shared_ptr<std::string> lexeme) : val(std::stol(*lexeme)) {}

Var::Var(const std::shared_ptr<std::string> name) : name(name) {}

FuncCall::FuncCall(const std::shared_ptr<std::string> name, const std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args) : name(name), args(args) {}

FuncCall::FuncCall(const std::shared_ptr<std::string> name) : name(name) {}
