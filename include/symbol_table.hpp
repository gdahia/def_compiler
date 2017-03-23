#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>

class SymbolTable {
private:
    std::vector<std::unordered_set<std::string>> decvar;
    std::unordered_map<std::string, std::pair<int, unsigned int>> decfunc;
    unsigned int whiles;
    std::string const * func_name;
    bool int_func;

public:
    SymbolTable();
    ~SymbolTable() = default;
    SymbolTable(const SymbolTable &) = delete;
    SymbolTable(SymbolTable &&) = delete;
    SymbolTable & operator =(const SymbolTable &) = delete;
    
    void add_var(const std::string &);
    void add_func(const int, const std::string &, const unsigned int);
    bool inside_int_func() const;
    const std::string & get_func_name() const;
    void add_scope();
    void pop_scope();
    void add_while();
    void pop_while();
    bool inside_while() const;
    bool var_lookup(const std::string &) const;
    bool func_lookup(const std::string &, const unsigned int) const;
    bool can_be_expr(const std::string &) const;
};

#endif
