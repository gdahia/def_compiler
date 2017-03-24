#include <symbol_table.hpp>

#include <ast.hpp>
#include <parser.hpp>

SymbolTable::SymbolTable() {
    // add global scope
    add_scope();
    
    // define print unconditionally
    add_func(VOID, "print", 1);
    
    whiles = 0;
}

bool SymbolTable::inside_int_func() const {
    return (cur_func != decfunc.end() && cur_func->second.first == INT);
}

const std::string & SymbolTable::get_func_name() const {
    return cur_func->first;
}

void SymbolTable::add_scope() {
    decvar.push_back(std::unordered_set<std::string>());
}

void SymbolTable::add_while() {
    whiles++;
}

void SymbolTable::pop_while() {
    whiles--;
}

bool SymbolTable::inside_while() const {
    return whiles > 0;
}

void SymbolTable::pop_scope() {
    if (decvar.empty())
        throw std::runtime_error("No scope to discard");
    decvar.pop_back();
}

bool SymbolTable::add_var(const std::string & name) {
    return decvar.back().insert(name).second;
}

bool SymbolTable::add_func(const int type, const std::string & name, const unsigned int n_args) {
    bool success;
    std::tie(cur_func, success) = decfunc.emplace(name, std::make_pair(type, n_args));
    return success;
}

bool SymbolTable::var_lookup(const std::string & name) const {
    for (auto i = decvar.rbegin(); i != decvar.rend(); i++)
        if (i->count(name))
            return true;
    return false;
}

bool SymbolTable::func_lookup(const std::string & name, const unsigned int n_args) const {
    auto f = decfunc.find(name);
    if (f == decfunc.end())
        throw std::runtime_error("Function \"" + name + "\" was not declared");
    
    return f->second.second == n_args;
}

bool SymbolTable::can_be_expr(const std::string & name) const {
    auto f = decfunc.find(name);
    if (f == decfunc.end())
        throw std::runtime_error("Function \"" + name + "\" was not declared");
    
    return f->second.first == INT;
}
