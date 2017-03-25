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
    
    // codegen
    std::unordered_map<std::string, int> locals;
    std::vector<std::unordered_map<std::string, int>> names;
    unsigned int acc;
    
    bool is_global(const std::string &) const;
    int var_idx(const std::string &) const;

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
    void add_namespace();
    void pop_namespace();
    void add_name(const std::string &);
    void add_while();
    unsigned int get_current_while() const;
    void pop_while();
    void clear();
    bool inside_while() const;
    bool var_lookup(const std::string &) const;
    bool func_lookup(const std::string &, const unsigned int) const;
    int n_local_vars(const std::string &);
    bool can_be_expr(const std::string &) const;
    std::string var_name(const std::string &) const;
};

#endif
