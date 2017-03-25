#include <symbol_table.hpp>

#include <ast.hpp>
#include <parser.hpp>

SymbolTable::SymbolTable() {
    // add global scope
    add_scope();
    
    // define print unconditionally
    add_func(VOID, "print", 1);
    
    whiles = 0;
    abs_whiles = 0;
    ifs = 0;
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
    abs_whiles++;
}

void SymbolTable::add_if() {
    ifs++;
}

unsigned int SymbolTable::get_current_while() const {
    return abs_whiles;
}

unsigned int SymbolTable::get_current_if() const {
    return ifs;
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
    if (decvar.size() > 1) {
        locals[cur_func->first]++;
        // save var idx
    }
    return decvar.back().insert(name).second;
}

bool SymbolTable::add_func(const int type, const std::string & name, const unsigned int n_args) {
    bool success;
    std::tie(cur_func, success) = decfunc.emplace(name, std::make_pair(type, n_args));
    // index params
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

bool SymbolTable::is_global(const std::string & name) const {
    return decvar[0].find(name) != decvar[0].end();
}

int SymbolTable::var_idx(const std::string & name) const {
    return 1;
}

std::string SymbolTable::var_name(const std::string & name) const {
    if (is_global(name))
        return name;
    return std::to_string(-4 * var_idx(name)) + "($fp)";
}

void SymbolTable::clear() {
    whiles = 0;
    abs_whiles = 0;
    ifs = 0;
    decvar.clear();
    decfunc.clear();
}

int SymbolTable::n_local_vars(const std::string & name) {
    return locals[name];
}

bool SymbolTable::can_be_expr(const std::string & name) const {
    auto f = decfunc.find(name);
    if (f == decfunc.end())
        throw std::runtime_error("Function \"" + name + "\" was not declared");
    
    return f->second.first == INT;
}
