#include <ast.hpp>
#include <parser.hpp>

using namespace AST;

void Program::codegen(std::ostream & os, SymbolTable & table) {
}

void Program::codegen(std::ostream & os) {
    codegen(os, table);
}

void Param::codegen(std::ostream & os, SymbolTable & table) {
}

void Block::codegen(std::ostream & os, SymbolTable & table) {
}

void Assign::codegen(std::ostream & os, SymbolTable & table) {
}

void If::codegen(std::ostream & os, SymbolTable & table) {
    // adjust symbol table
    table.add_if();
    const unsigned int label = table.get_current_if();
    
    // get expr result
    expr->codegen(os, table);
    
    // if true, jump to begin if
    os << "bne $a0, $0, _if_" << label << std::endl;
    
    // else block
    if (else_block)
        else_block->codegen(os, table);
    
    // jump to endif
    os << "b _fi_" << label << std::endl;
    
    // if block
    os << "_if_" << label << ":" << std::endl;
    if_block->codegen(os, table);
    
    // end if
    os << "_fi_" << label << ":" << std::endl;
}

void Return::codegen(std::ostream & os, SymbolTable & table) {
}

void Continue::codegen(std::ostream & os, SymbolTable & table) {
    os << "b _while_" << table.get_current_while() << std::endl;
}

void Break::codegen(std::ostream & os, SymbolTable & table) {
    os << "b _end_while_" << table.get_current_while() << std::endl;
}

void While::codegen(std::ostream & os, SymbolTable & table) {
    // adjust symbol table
    table.add_while();
    const unsigned int label = table.get_current_while();
    
    // begin while
    os << "_while_" << label << ":" << std::endl;
    
    // get expr result
    expr->codegen(os, table);
    
    // if false, jump to end while
    os << "beq $a0, $0, _end_while_" << label << std::endl;
    
    // while block
    block->codegen(os, table);
    
    // end while
    os << "_end_while_" << label << ":" << std::endl;
}

void DecVar::codegen(std::ostream & os, SymbolTable & table) {
}

void DecFunc::codegen(std::ostream & os, SymbolTable & table) {
}

void BinOp::codegen(std::ostream & os, SymbolTable & table) {
    left->codegen(os, table);
    os << "sw $a0, 0($sp)" << std::endl;
    os << "addiu $sp, $sp, -4" << std::endl;
    right->codegen(os, table);
    os << "lw $t1, 4($sp)" << std::endl;
}

void Add::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "add $a0, $t1, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Sub::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "sub $a0, $t1, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Or::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "sltu $a0, $0, $a0" << std::endl;
    os << "sltu $t1, $0, $t1" << std::endl;
    os << "or $a0, $t1, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void And::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "sltu $a0, $0, $a0" << std::endl;
    os << "sltu $t1, $0, $t1" << std::endl;
    os << "and $a0, $t1, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Times::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "mul $a0, $t1, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Div::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "div $t1, $a0" << std::endl;
    os << "mflo $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Not::codegen(std::ostream & os, SymbolTable & table) {
    expr->codegen(os, table);
    os << "sltu $a0, $0, $a0" << std::endl;
    os << "xori $a0, $a0, 1" << std::endl;
}

void Opp::codegen(std::ostream & os, SymbolTable & table) {
    expr->codegen(os, table);
    os << "li $t1, -1" << std::endl;
    os << "mul $a0, $t1, $a0" << std::endl;
}

void Less::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "slt $a0, $t1, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Leq::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "slt $a0, $a0, $t1" << std::endl;
    os << "xori $a0, $a0, 1" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Great::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "slt $a0, $a0, $t1" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Geq::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "slt $a0, $t1, $a0" << std::endl;
    os << "xori $a0, $a0, 1" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Eq::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "sltu $a0, $0, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Diff::codegen(std::ostream & os, SymbolTable & table) {
    BinOp::codegen(os, table);
    os << "sub $a0, $t1, $a0" << std::endl;
    os << "movn $a0, $0, $a0" << std::endl;
    os << "addiu $sp, $sp, 4" << std::endl;
}

void Number::codegen(std::ostream & os, SymbolTable & table) {
    os << "li $a0, " << val << std::endl;
}

void Var::codegen(std::ostream & os, SymbolTable & table) {
    os << "lw $a0, " << table.var_lookup(*name) << std::endl;
}

void FuncCall::codegen(std::ostream & os, SymbolTable & table) {
}
