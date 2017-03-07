#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include <memory>
#include <string>
#include <ostream>

namespace AST {
    class Node {
    public:
        virtual ~Node() = default;
        
        virtual void print(std::ostream &) const = 0;
    };
    
    class Instr : public Node {};
    
    class Program : public Node {
    public:
        Program() = default;
        
        std::vector<std::shared_ptr<Instr>> instr;
        
        void print(std::ostream &) const;
    };
    
    class Stmt : public Node {};
    
    class Expr : public Stmt {};
    
    class Block;
    
    class Param : public Node {
    private:
        const std::shared_ptr<std::string> name;
    
    public:
        Param(const int, const std::shared_ptr<std::string>);
        
        void print(std::ostream &) const;
    };
    
    class DecVar : public Instr {
    private:
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<Expr> rhs;
    
    public:
        DecVar(const int, const std::shared_ptr<std::string>);
        DecVar(const int, const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
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
        
        void print(std::ostream &) const;
    };
    
    class Block : public Node {
    private:
        const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>> vars;
        const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>> stmts;
    
    public:
        Block(const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>>, const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>>);
        
        void print(std::ostream &) const;
    };
    
    class Assign : public Stmt {
    private:
        const std::shared_ptr<std::string> lhs;
        const std::shared_ptr<Expr> rhs;
    
    public:
        Assign(const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class If : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
        const std::shared_ptr<Block> if_block, else_block;
    
    public:
        If(const std::shared_ptr<Expr>, const std::shared_ptr<Block>);
        If(const std::shared_ptr<Expr>, const std::shared_ptr<Block>, const std::shared_ptr<Block>);
        
        void print(std::ostream &) const;
    };
    
    class While : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
        const std::shared_ptr<Block> block;
    
    public:
        While(const std::shared_ptr<Expr>, const std::shared_ptr<Block>);
        
        void print(std::ostream &) const;
    };
    
    class Return : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Return();
        Return(const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Continue : public Stmt {
    public:
        void print(std::ostream &) const;
    };
    
    class Break : public Stmt {
    public:
        void print(std::ostream &) const;
    };
    
    class Add : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Add(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Sub : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Sub(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Times : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Times(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Div : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Div(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Less : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Less(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Leq : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Leq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Great : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Great(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Geq : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Geq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Eq : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Eq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Diff : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Diff(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class And : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        And(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Or : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Or(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Not : public Expr {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Not(const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Opp : public Expr {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Opp(const std::shared_ptr<Expr>);
        
        void print(std::ostream &) const;
    };
    
    class Number : public Expr {
    private:
        const long long val;
    
    public:
        Number(const std::shared_ptr<std::string>);
        
        void print(std::ostream &) const;
    };
    
    class Var : public Expr {
    private:
        const std::shared_ptr<std::string> name;
    
    public:
        Var(const std::shared_ptr<std::string>);
        
        void print(std::ostream &) const;
    };
    
    class FuncCall : public Expr {
    private:
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args;
    
    public:
        FuncCall(const std::shared_ptr<std::string>);
        FuncCall(const std::shared_ptr<std::string>, const std::shared_ptr<std::vector<std::shared_ptr<Expr>>>);
        
        void print(std::ostream &) const;
    };
    
};

std::ostream & operator <<(std::ostream &, const AST::Node &);

#endif
