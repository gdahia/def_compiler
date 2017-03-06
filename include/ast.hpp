#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include <string>

namespace AST {
    class Node {
    public:
        virtual ~Node() = default;
    };
    
    class Instr : public Node {};
    
    class Stmt : public Node {};
    
    class Expr : public Stmt {};
    
    class Block;
    
    class Param : public Node {
    private:
        const std::string * name;
        const int type;
    
    public:
        Param(const int, const std::string *);
    };
    
    class DecVar : public Instr {
    private:
        const std::string * name;
        const Expr * rhs;
    
    public:
        DecVar(const int, const std::string *);
        DecVar(const int, const std::string *, const Expr *);
    };
    
    class DecFunc : public Instr {
    private:
        const std::string * name;
        const int type;
        const std::vector<Param *> * paramlist;
        const Block * block;
    
    public:
        DecFunc(const int, const std::string *, const std::vector<Param> *, const Block *);
        DecFunc(const int, const std::string *, const Block *);
    };
    
    class Block : public Node {
    private:
        const std::vector<DecVar *> * vars;
        const std::vector<Stmt *> * funcs;
    
    public:
        Block(const std::vector<DecVar *> *, const std::vector<Stmt *> *);
    };
    
    class Assign : public Stmt {
    private:
        const std::string * lhs;
        const Expr * rhs;
    
    public:
        Assign(const std::string *, const Expr *);
    };
    
    class If : public Stmt {
    private:
        const Expr * expr;
        const Block * if_block, else_block;
    
    public:
        If(const Expr *, const Block *);
        If(const Expr *, const Block *, const Block *);
    };
    
    class While : public Stmt {
    private:
        const Expr * expr;
        const Block * block;
    
    public:
        While(const Expr *, const Block *);
    };
    
    class Return : public Stmt {
    private:
        const Expr * expr;
    
    public:
        Return();
        Return(const Expr *);
    };
    
    class Continue : public Stmt {};
    
    class Break : public Stmt {};
    
    class Add : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Add(const Expr *, const Expr *);
    };
    
    class Sub : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Sub(const Expr *, const Expr *);
    };
    
    class Times : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Times(const Expr *, const Expr *);
    };
    
    class Div : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Div(const Expr *, const Expr *);
    };
    
    class Less : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Less(const Expr *, const Expr *);
    };
    
    class Leq : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Leq(const Expr *, const Expr *);
    };
    
    class Great : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Great(const Expr *, const Expr *);
    };
    
    class Geq : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Geq(const Expr *, const Expr *);
    };
    
    class Eq : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Eq(const Expr *, const Expr *);
    };
    
    class Diff : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Diff(const Expr *, const Expr *);
    };
    
    class And : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        And(const Expr *, const Expr *);
    };
    
    class Or : public Expr {
    private:
        const Expr * left, * right;
    
    public:
        Or(const Expr *, const Expr *);
    };
    
    class Not : public Expr {
    private:
        const Expr * expr;
    
    public:
        Not(const Expr *);
    };
    
    class Opp : public Expr {
    private:
        const Expr * expr;
    
    public:
        Opp(const Expr *);
    };
    
    class Number : public Expr {
    private:
        const long long val;
    
    public:
        Number(const std::string *);
    };
    
    class Var : public Expr {
    private:
        const std::string * name;
    
    public:
        Var(const std::string *);
    };
    
    class FuncCall : public Expr {
    private:
        const std::string * name;
        const std::vector<Expr *> * args;
    
    public:
        FuncCall(const std::string *);
        FuncCall(const std::string *, const std::vector<Expr *> *);
    };
    
};

#endif
