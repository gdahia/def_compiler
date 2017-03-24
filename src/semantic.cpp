#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

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
