#ifndef AST_HPP
#define AST_HPP

#include <vector>
#include <memory>
#include <string>
#include <ostream>

#include <symbol_table.hpp>

namespace AST {
    class Node {
    public:
        virtual ~Node() = default;
        
        virtual void codegen(std::ostream &) const = 0;
    };
    
    class Instr : public Node {
    public:
        virtual void validate(SymbolTable &) const = 0;
    };
    
    class Program : public Node {
    private:
        const std::shared_ptr<std::vector<std::shared_ptr<Instr>>> instr;
        SymbolTable table;

    public:
        Program(const std::shared_ptr<std::vector<std::shared_ptr<Instr>>>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class Stmt : public Node {
    public:
        virtual void validate(SymbolTable &) const = 0;
    };
    
    class Expr : public Stmt {
    public:
        virtual void validate(SymbolTable &) const = 0;
    };
    
    class Block;
    
    class Param : public Node {
    private:
        const std::shared_ptr<std::string> name;
    
    public:
        Param(const int, const std::shared_ptr<std::string>);
        
        void codegen(std::ostream &) const;
        std::shared_ptr<std::string> get_name() const;
    };
    
    class DecVar : public Instr {
    private:
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<Expr> rhs;
    
    public:
        DecVar(const int, const std::shared_ptr<std::string>);
        DecVar(const int, const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
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
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class Block : public Node {
    private:
        const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>> vars;
        const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>> stmts;
        
    public:
        Block(const std::shared_ptr<std::vector<std::shared_ptr<DecVar>>>, const std::shared_ptr<std::vector<std::shared_ptr<Stmt>>>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
        void validate(SymbolTable &, const std::shared_ptr<std::vector<Param>>) const;
    };
    
    class Assign : public Stmt {
    private:
        const std::shared_ptr<std::string> lhs;
        const std::shared_ptr<Expr> rhs;
    
    public:
        Assign(const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class If : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
        const std::shared_ptr<Block> if_block, else_block;
    
    public:
        If(const std::shared_ptr<Expr>, const std::shared_ptr<Block>);
        If(const std::shared_ptr<Expr>, const std::shared_ptr<Block>, const std::shared_ptr<Block>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class While : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
        const std::shared_ptr<Block> block;
    
    public:
        While(const std::shared_ptr<Expr>, const std::shared_ptr<Block>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class Return : public Stmt {
    private:
        const std::shared_ptr<Expr> expr;
    
    public:
        Return();
        Return(const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class Continue : public Stmt {
    public:
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class Break : public Stmt {
    public:
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class BinOp : public Expr {
    protected:
        const std::shared_ptr<Expr> left, right;
    
    public:
        BinOp(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        virtual void codegen(std::ostream &) const;
        virtual void validate(SymbolTable &) const;
    };
    
    class Add : public BinOp {
    public:
        Add(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Sub : public BinOp {
    public:
        Sub(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Times : public BinOp {
    public:
        Times(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Div : public BinOp {
    public:
        Div(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Less : public BinOp {
    public:
        Less(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Leq : public BinOp {
    public:
        Leq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Great : public BinOp {
    public:
        Great(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Geq : public BinOp {
    public:
        Geq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Eq : public BinOp {
    public:
        Eq(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Diff : public BinOp {
    public:
        Diff(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class And : public BinOp {
    public:
        And(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Or : public BinOp {
    public:
        Or(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class UnOp : public Expr {
    protected:
        const std::shared_ptr<Expr> expr;
    
    public:
        UnOp(const std::shared_ptr<Expr>);
        virtual void codegen(std::ostream &) const;
        virtual void validate(SymbolTable &) const;
    };
    
    class Not : public UnOp {
    public:
        Not(const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Opp : public UnOp {
    public:
        Opp(const std::shared_ptr<Expr>);
        
        void codegen(std::ostream &) const;
    };
    
    class Number : public Expr {
    private:
        const int val;
    
    public:
        Number(const std::shared_ptr<std::string>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class Var : public Expr {
    private:
        const std::shared_ptr<std::string> name;
    
    public:
        Var(const std::shared_ptr<std::string>);
        
        void codegen(std::ostream &) const;
        void validate(SymbolTable &) const;
    };
    
    class FuncCall : public Expr {
    private:
        const std::shared_ptr<std::string> name;
        const std::shared_ptr<std::vector<std::shared_ptr<Expr>>> args;
    
    public:
        FuncCall(const std::shared_ptr<std::string>);
        FuncCall(const std::shared_ptr<std::string>, const std::shared_ptr<std::vector<std::shared_ptr<Expr>>>);
        
        void codegen(std::ostream &) const;
        const std::string & get_name() const;
        void validate(SymbolTable &) const;
    };
    
};

std::ostream & operator <<(std::ostream &, const AST::Node &);

#endif
