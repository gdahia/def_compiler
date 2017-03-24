#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

void test_for_expr(SymbolTable & table, Expr * expr) {
    FuncCall * func = dynamic_cast<FuncCall *>(expr);
    if (func != nullptr && !table.can_be_expr(func->get_name()))
        throw std::runtime_error("Function \"" + func->get_name() + "\" does not return \"int\", as it was previously declared \"void\"");
}

void test_var(SymbolTable & table, const std::string & name) {
    if (!table.var_lookup(name))
        throw std::runtime_error("Variable \"" + name + "\" was not declared");
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
    test_var(table, *name);
}

void Assign::validate(SymbolTable & table) const {
    test_var(table, *lhs);
    test_for_expr(table, rhs.get());
    rhs->validate(table);
}

void FuncCall::validate(SymbolTable & table) const {
    if (args) {
        if (!table.func_lookup(*name, args->size()))
            throw std::runtime_error("\"" + *name + "\" function called with wrong number of arguments");
        for (auto arg = args->rbegin(); arg != args->rend(); arg++)
            (*arg)->validate(table);
    }
    else if (!table.func_lookup(*name, 0))
        throw std::runtime_error("\"" + *name + "\" function called with wrong number of arguments");
}

void Program::validate(SymbolTable & table) const {
    for (auto i = instr->rbegin(); i != instr->rend(); i++)
        (*i)->validate(table);
    
    if (!table.func_lookup("main", 0))
        throw std::runtime_error("\"main\" function called with wrong number of arguments");
}

void DecVar::validate(SymbolTable & table) const {
    if (rhs) {
        test_for_expr(table, rhs.get());
        rhs->validate(table);
    }
    if (!table.add_var(*name))
        throw std::runtime_error("Redefintion of function \"" + *name + "\"");
}

void DecFunc::validate(SymbolTable & table) const {
    if (paramlist) {
        if (!table.add_func(type, *name, paramlist->size()))
            throw std::runtime_error("Redeclaration of function \"" + *name + "\"");
        block->validate(table, paramlist);
    }
    else {
        if (!table.add_func(type, *name, 0))
            throw std::runtime_error("Redeclaration of function \"" + *name + "\"");
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
    test_for_expr(table, expr.get());
    expr->validate(table);
    if_block->validate(table);
    if (else_block) else_block->validate(table);
}

void While::validate(SymbolTable & table) const {
    table.add_while();
    test_for_expr(table, expr.get());
    expr->validate(table);
    block->validate(table);
    table.pop_while();
}

void Return::validate(SymbolTable & table) const {
    if (expr) {
        if (!table.inside_int_func())
            throw std::runtime_error("Function \"" + table.get_func_name() + "\" has type \'void\' but returns an \'int\'");
        test_for_expr(table, expr.get());
        expr->validate(table);
    }
    else if (table.inside_int_func())
        throw std::runtime_error("Function \"" + table.get_func_name() + "\" has type \'int\' but returns no \'int\'");
}

void BinOp::validate(SymbolTable & table) const {
    test_for_expr(table, left.get());
    test_for_expr(table, right.get());
    left->validate(table);
    right->validate(table);
}

void UnOp::validate(SymbolTable & table) const {
    test_for_expr(table, expr.get());
    expr->validate(table);
}
