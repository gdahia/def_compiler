#include <symbol_table.hpp>

#include <ast.hpp>
#include <parser.hpp>

SymbolTable::SymbolTable() {
    // add global scope
    add_scope();
    
    // define print unconditionally
    add_func(VOID, "print");
}

void SymbolTable::add_scope() {
    decvar.push_back(std::unordered_set<std::string>());
}

void SymbolTable::pop_scope() {
    if (decvar.empty())
        throw std::runtime_error("No scope to discard");
    decvar.pop_back();
}

void SymbolTable::add_var(const std::string & name) {
    if (!decvar.back().insert(name).second)
        throw std::runtime_error("Redefinition of variable \"" + name + "\"");
}

void SymbolTable::add_func(const int type, const std::string & name) {
    if (!decfunc.emplace(name, type).second)
        throw std::runtime_error("Redefintion of function \"" + name + "\"");
}

bool SymbolTable::var_lookup(const std::string & name) {
    for (auto i = decvar.rbegin(); i != decvar.rend(); i++)
        if (i->count(name))
            return true;
    throw std::runtime_error("Variable \"" + name + "\" was not declared");
}

bool SymbolTable::func_lookup(const std::string & name) {
    if (decfunc.count(name))
        return true;
    throw std::runtime_error("Function \"" + name + "\" was not declared");
}

bool SymbolTable::can_be_expr(const std::string & name) {
    auto f = decfunc.find(name);
    if (f != decfunc.end()) {
        if (f->second == INT)
            return true;
        else
            throw std::runtime_error("Function \"" + name + "\" does not return \"int\", as it was previously declared \"void\"");
    }
    else
        throw std::runtime_error("Function \"" + name + "\" was not declared");
}
