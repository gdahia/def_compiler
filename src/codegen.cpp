#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

void Program::codegen(std::ostream & os) const {
    os << "[program";
    for (auto i = instr->rbegin(); i != instr->rend(); i++)
        os << " " << **i;
    os << "]";
}

void Param::codegen(std::ostream & os) const {
    os << "[" << *name << "]";
}

void Block::codegen(std::ostream & os) const {
    os << "[block";
    for (auto d = vars->rbegin(); d != vars->rend(); d++)
        os << " " << **d;
    for (auto d = stmts->rbegin(); d != stmts->rend(); d++)
        os << " " << **d;
    os << "]";
}

void Assign::codegen(std::ostream & os) const {
    os << "[assign [" << *lhs << "] " << *rhs << "]"; 
}

void If::codegen(std::ostream & os) const {
    os << "[if " << *expr << " " << *if_block;
    if (else_block)
        os << " " << *else_block;
    os << "]";
}

void Return::codegen(std::ostream & os) const {
    os << "[return";
    if (expr)
        os << " " << *expr;
    os << "]";
}

void Continue::codegen(std::ostream & os) const {
    os << "[continue]";
}

void Break::codegen(std::ostream & os) const {
    os << "[break]";
}

void While::codegen(std::ostream & os) const {
    os << "[while " << *expr << " " << *block << "]";
}

void DecVar::codegen(std::ostream & os) const {
    os << "[decvar [" << *name << "]";
    if (rhs)
        os << " " << *rhs;
    os << "]";
}

void DecFunc::codegen(std::ostream & os) const {
    os << "[decfunc [" << *name << "] [paramlist";
    if (paramlist)
        for (auto param = paramlist->rbegin(); param != paramlist->rend(); param++)
            os << " " << *param;
    os << "] " << *block << "]";
}

void BinOp::codegen(std::ostream & os) const {
    os << " " << *left << " " << *right << "]";
}

void Add::codegen(std::ostream & os) const {
    os << "[+";
    BinOp::codegen(os);
}

void Sub::codegen(std::ostream & os) const {
    os << "[-";
    BinOp::codegen(os);
}

void Or::codegen(std::ostream & os) const {
    os << "[||";
    BinOp::codegen(os);
}

void And::codegen(std::ostream & os) const {
    os << "[&&";
    BinOp::codegen(os);
}

void Times::codegen(std::ostream & os) const {
    os << "[*";
    BinOp::codegen(os);
}

void Div::codegen(std::ostream & os) const {
    os << "[/";
    BinOp::codegen(os);
}

void UnOp::codegen(std::ostream & os) const {
     os << " " << *expr << "]";
}

void Not::codegen(std::ostream & os) const {
    os << "[!";
    UnOp::codegen(os);
}

void Opp::codegen(std::ostream & os) const {
    os << "[-";
    UnOp::codegen(os);
}

void Less::codegen(std::ostream & os) const {
    os << "[<";
    BinOp::codegen(os);
}

void Leq::codegen(std::ostream & os) const {
    os << "[<=";
    BinOp::codegen(os);
}

void Great::codegen(std::ostream & os) const {
    os << "[>";
    BinOp::codegen(os);
}

void Geq::codegen(std::ostream & os) const {
    os << "[>=";
    BinOp::codegen(os);
}

void Eq::codegen(std::ostream & os) const {
    os << "[==";
    BinOp::codegen(os);
}

void Diff::codegen(std::ostream & os) const {
    os << "[!=";
    BinOp::codegen(os);
}

void Number::codegen(std::ostream & os) const {
    os << "[" << val << "]";
}

void Var::codegen(std::ostream & os) const {
    os << "[" << *name << "]";
}

void FuncCall::codegen(std::ostream & os) const {
    os << "[funccall [" << *name << "] [arglist";
    if (args) {
        for (auto arg = args->rbegin(); arg != args->rend(); arg++)
            os << " " << **arg;
    }
    os << "]]";
}
