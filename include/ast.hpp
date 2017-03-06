#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include <memory>
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
        const std::shared_ptr<std::string> name;
    
    public:
        Param(const int, const std::shared_ptr<std::string>);
    };
    
    class DecVar : public Instr {
    private:
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<Expr> rhs;
    
    public:
        DecVar(const int, const std::shared_ptr<std::string>);
        DecVar(const int, const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
    };
    
    class DecFunc : public Instr {
    private:
        const int type;
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<std::vector<Param>> paramlist;
        const std::shared_ptr<Block> block;
    
    public:
        DecFunc(const int, const std::shared_ptr<std::string>, const std::shared_ptr<std::vector<Param>>, const std::shared_ptr<Block>);
        DecFunc(const int, const std::shared_ptr<std::string>, const std::shared_ptr<Block>);
    };
    
    class Block : public Node {
    private:
        const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>> vars;
        const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>> funcs;
    
    public:
        Block(const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>>, const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>>);
    };
    
    class Assign : public Stmt {
    private:
        const std::shared_ptr<std::string> lhs;
        const std::shared_ptr<Expr> rhs;
    
    public:
        Assign(const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
    };
    
    class If : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
        const std::shared_ptr<Block> if_block, else_block;
    
    public:
        If(const std::shared_ptr<Expr>, const std::shared_ptr<Block>);
        If(const std::shared_ptr<Expr>, const std::shared_ptr<Block>, const std::shared_ptr<Block>);
    };
    
    class While : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
        const std::shared_ptr<Block> block;
    
    public:
        While(const std::shared_ptr<Expr>, const std::shared_ptr<Block>);
    };
    
    class Return : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Return();
        Return(const std::shared_ptr<Expr>);
    };
    
    class Continue : public Stmt {};
    
    class Break : public Stmt {};
    
    class Add : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Add(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Sub : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Sub(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Times : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Times(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Div : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Div(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Less : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Less(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Leq : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Leq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Great : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Great(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Geq : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Geq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Eq : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Eq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Diff : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Diff(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class And : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        And(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Or : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Or(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
    };
    
    class Not : public Expr {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Not(const std::shared_ptr<Expr>);
    };
    
    class Opp : public Expr {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Opp(const std::shared_ptr<Expr>);
    };
    
    class Number : public Expr {
    private:
        const long long val;
    
    public:
        Number(const std::shared_ptr<std::string>);
    };
    
    class Var : public Expr {
    private:
        const std::shared_ptr<std::string> name;
    
    public:
        Var(const std::shared_ptr<std::string>);
    };
    
    class FuncCall : public Expr {
    private:
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args;
    
    public:
        FuncCall(const std::shared_ptr<std::string>);
        FuncCall(const std::shared_ptr<std::string>, const std::shared_ptr<std::vector<std::shared_ptr<Expr>>>);
    };
    
};

#endif
