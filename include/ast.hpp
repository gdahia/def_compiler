#ifndef AST_HPP
#define AST_HPP

namespace AST {
    class Node {
    public:
        virtual ~Node() = default;
    };
    
    class Stmt : public Node {};
    
    class Expr : public Stmt {};
    
    class Assign : public Stmt {
    private:
        const std::shared_ptr<std::string> lhs;
        const std::shared_ptr<Expr> rhs;
    
    public:
        Assign(const std::shared_ptr<std::string>, const std::shared_ptr<Expr>);
    };
    
    class Plus : public Expr {
    private:
        const std::shared_ptr<Expr> left, right;
    
    public:
        Plus(const std::shared_ptr<Expr>, const std::shared_ptr<Expr>);
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
    
    class Number : public Expr {
    private:
        long long val;
    
    public:
        Number(const std::shared_ptr<std::string>);
        
        void oppose();
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
        FuncCall(const std::shared_ptr<std::string>, const std::shared_ptr<std::vector<std::shared_ptr<Expr>>>);
    };
    
    class Instr : public Node {};
    
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
        const std::shared_ptr<std::string> name;
        const int type;
        const std::shared_ptr<std::vector<std::shared_ptr<Param>>> paramlist;
        const std::shared_ptr<Block> block;
    
    public:
        DecFunc(const int, const std::shared_ptr<std::string>, const std::shared_ptr<std::vector<std::shared_ptr<Param>>>, const std::shared_ptr<Block>);
    };
    
    class Param : public Node {
    private:
        const std::shared_ptr<std::string> name;
        const int type;
    
    public:
        Param(const int, const std::shared_ptr<std::string>);
    };
    
    
};

#endif
