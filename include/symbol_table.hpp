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
    unsigned int whiles, abs_whiles, ifs;
    std::unordered_map<std::string, std::pair<int, unsigned int>>::iterator cur_func;

public:
    SymbolTable();
    ~SymbolTable() = default;
    SymbolTable(const SymbolTable &) = delete;
    SymbolTable(SymbolTable &&) = delete;
    SymbolTable & operator =(const SymbolTable &) = delete;
    
    bool add_var(const std::string &);
    bool add_func(const int, const std::string &, const unsigned int);
    bool inside_int_func() const;
    const std::string & get_func_name() const;
    void add_if();
    unsigned int get_current_if() const;
    void add_scope();
    void pop_scope();
    void add_while();
    unsigned int get_current_while() const;
    void pop_while();
    void clear();
    bool inside_while() const;
    bool var_lookup(const std::string &) const;
    bool func_lookup(const std::string &, const unsigned int) const;
    bool can_be_expr(const std::string &) const;
};

#endif
