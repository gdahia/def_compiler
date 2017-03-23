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

void SymbolTable::add_var(const std::string & name) {
    if (!decvar.back().insert(name).second)
        throw std::runtime_error("Redefinition of variable \"" + name + "\"");
}

void SymbolTable::add_func(const int type, const std::string & name, const unsigned int n_args) {
    bool success;
    std::tie(cur_func, success) = decfunc.emplace(name, std::make_pair(type, n_args));
    if (!success)
        throw std::runtime_error("Redefintion of function \"" + name + "\"");
}

bool SymbolTable::var_lookup(const std::string & name) const {
    for (auto i = decvar.rbegin(); i != decvar.rend(); i++)
        if (i->count(name))
            return true;
    throw std::runtime_error("Variable \"" + name + "\" was not declared");
}

bool SymbolTable::func_lookup(const std::string & name, const unsigned int n_args) const {
    auto f = decfunc.find(name);
    if (f != decfunc.end()) {
        if (f->second.second == n_args)
            return true;
        throw std::runtime_error("\"" + name + "\" function called with " + std::to_string(n_args) + " arguments, but it takes " + std::to_string(f->second.second) + " parameters"); 
    }
    throw std::runtime_error("Function \"" + name + "\" was not declared");
}

bool SymbolTable::can_be_expr(const std::string & name) const {
    auto f = decfunc.find(name);
    if (f != decfunc.end()) {
        if (f->second.first == INT)
            return true;
        else
            throw std::runtime_error("Function \"" + name + "\" does not return \"int\", as it was previously declared \"void\"");
    }
    else
        throw std::runtime_error("Function \"" + name + "\" was not declared");
}
