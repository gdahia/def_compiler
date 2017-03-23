#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

std::ostream & operator <<(std::ostream & os, const Node & node) {
    node.print(os);
    return os;
}

void Program::print(std::ostream & os) const {
    os << "[program";
    for (auto i = instr->rbegin(); i != instr->rend(); i++)
        os << " " << **i;
    os << "]";
}

Program::Program(const std::shared_ptr<std::vector<std::shared_ptr<Instr>>> instr) : instr(instr) {
    validate(table);
    
    table.func_lookup("main", 0);
}

void Continue::validate(SymbolTable & table) const {
    if (!table.inside_while())
        throw std::runtime_error("Continue statement not within loop");
}

void Break::validate(SymbolTable & table) const {
    if (!table.inside_while())
        throw std::runtime_error("Break statement not within loop");
}

void Number::validate(SymbolTable & table) const {}

void Var::validate(SymbolTable & table) const {
    table.var_lookup(*name);
}

void Assign::validate(SymbolTable & table) const {
    table.var_lookup(*lhs);
    if (FuncCall * func = dynamic_cast<FuncCall *>(rhs.get()))
        table.can_be_expr(func->get_name());
    rhs->validate(table);
}

void FuncCall::validate(SymbolTable & table) const {
    if (args) {
        table.func_lookup(*name, args->size());
        for (auto arg = args->rbegin(); arg != args->rend(); arg++)
            (*arg)->validate(table);
    }
    else
        table.func_lookup(*name, 0);
}

const std::string & FuncCall::get_name() const {
    return *name;
}

void Program::validate(SymbolTable & table) const {
    for (auto i = instr->rbegin(); i != instr->rend(); i++)
        (*i)->validate(table);
}

void DecVar::validate(SymbolTable & table) const {
    table.add_var(*name);
    if (rhs) {
        if (FuncCall * func = dynamic_cast<FuncCall *>(rhs.get()))
            table.can_be_expr(func->get_name());
        rhs->validate(table);
    }
}

std::shared_ptr<std::string> Param::get_name() const {
    return name;
}

void DecFunc::validate(SymbolTable & table) const {
    if (paramlist) {
        table.add_func(type, *name, paramlist->size());
        block->validate(table, paramlist);
    }
    else {
        table.add_func(type, *name, 0);
        block->validate(table);
    }
}

void Block::validate(SymbolTable & table) const {
    table.add_scope();
    for (auto i = vars->rbegin(); i != vars->rend(); i++)
        (*i)->validate(table);
    for (auto i = stmts->rbegin(); i != stmts->rend(); i++)
        (*i)->validate(table);
    table.pop_scope();
}

void Block::validate(SymbolTable & table, const std::shared_ptr<std::vector<Param>> paramlist) const {
    for (const Param & param : *paramlist)
        vars->push_back(std::make_shared<DecVar>(INT, param.get_name()));
    validate(table);
    for (int i = 0, len = paramlist->size(); i < len; i++)
        vars->pop_back();
}

void If::validate(SymbolTable & table) const {
    if (FuncCall * func = dynamic_cast<FuncCall *>(expr.get()))
        table.can_be_expr(func->get_name());
    expr->validate(table);
    if_block->validate(table);
    if (else_block) else_block->validate(table);
}

void While::validate(SymbolTable & table) const {
    table.add_while();
    if (FuncCall * func = dynamic_cast<FuncCall *>(expr.get()))
        table.can_be_expr(func->get_name());
    expr->validate(table);
    block->validate(table);
    table.pop_while();
}

void Return::validate(SymbolTable & table) const {
    if (expr) {
        if (!table.inside_int_func())
            throw std::runtime_error("Function \"" + table.get_func_name() + "\" has type \'void\' but returns an \'int\'");
        if (FuncCall * func = dynamic_cast<FuncCall *>(expr.get()))
            table.can_be_expr(func->get_name());
        expr->validate(table);
    }
    else if (table.inside_int_func())
        throw std::runtime_error("Function \"" + table.get_func_name() + "\" has type \'int\' but returns no \'int\'");
}

void BinOp::validate(SymbolTable & table) const {
    if (FuncCall * func = dynamic_cast<FuncCall *>(left.get()))
        table.can_be_expr(func->get_name());
    if (FuncCall * func = dynamic_cast<FuncCall *>(right.get()))
        table.can_be_expr(func->get_name());
    left->validate(table);
    right->validate(table);
}

void UnOp::validate(SymbolTable & table) const {
    if (FuncCall * func = dynamic_cast<FuncCall *>(expr.get()))
        table.can_be_expr(func->get_name());
    expr->validate(table);
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
    os << "[while " << *expr << " " << *block << "]";
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

void BinOp::print(std::ostream & os) const {
    os << " " << *left << " " << *right << "]";
}

void Add::print(std::ostream & os) const {
    os << "[+";
    BinOp::print(os);
}

void Sub::print(std::ostream & os) const {
    os << "[-";
    BinOp::print(os);
}

void Or::print(std::ostream & os) const {
    os << "[||";
    BinOp::print(os);
}

void And::print(std::ostream & os) const {
    os << "[&&";
    BinOp::print(os);
}

void Times::print(std::ostream & os) const {
    os << "[*";
    BinOp::print(os);
}

void Div::print(std::ostream & os) const {
    os << "[/";
    BinOp::print(os);
}

void UnOp::print(std::ostream & os) const {
     os << " " << *expr << "]";
}

void Not::print(std::ostream & os) const {
    os << "[!";
    UnOp::print(os);
}

void Opp::print(std::ostream & os) const {
    os << "[-";
    UnOp::print(os);
}

void Less::print(std::ostream & os) const {
    os << "[<";
    BinOp::print(os);
}

void Leq::print(std::ostream & os) const {
    os << "[<=";
    BinOp::print(os);
}

void Great::print(std::ostream & os) const {
    os << "[>";
    BinOp::print(os);
}

void Geq::print(std::ostream & os) const {
    os << "[>=";
    BinOp::print(os);
}

void Eq::print(std::ostream & os) const {
    os << "[==";
    BinOp::print(os);
}

void Diff::print(std::ostream & os) const {
    os << "[!=";
    BinOp::print(os);
}

void Number::print(std::ostream & os) const {
    os << "[" << val << "]";
}

void Var::print(std::ostream & os) const {
    os << "[" << *name << "]";
}

void FuncCall::print(std::ostream & os) const {
    os << "[funccall [" << *name << "] [arglist";
    if (args) {
        for (auto arg = args->rbegin(); arg != args->rend(); arg++)
            os << " " << **arg;
    }
    os << "]]";
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
