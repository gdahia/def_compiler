%{
#include <vector>
#include <string>

#include <ast.hpp>

std::vector<AST::Instr *> program;

extern int yylex();

void yyerror(const char * s) {
    // throw std::runtime_error("Error: " + std::string
    printf("ERROR: %s\n", s);
}

%}

%union {
    AST::Expr * expr;
    std::vector<AST::Expr *> * args;
    AST::FuncCall * funccall;
    AST::Stmt * stmt;
    AST::Block * block;
    std::vector<AST::Stmt *> * stmts;
    std::vector<AST::DecVar *> * decvars;
    std::vector<AST::Param> * params;
    AST::DecVar * decvar;
    AST::DecFunc * decfunc;
    std::string * lexeme;
    int token;
}

%token <token> INT VOID
%token <lexeme> ID DEC
%token DEF IF WHILE RETURN CONTINUE BREAK ELSE
%token LEQ GEQ AND OR EQ DIFF MINUS PLUS STAR SLASH ASS
%token LPAR RPAR LBRAC RBRAC COMMA SCOLON

%type <expr> expr
%type <token> type
%type <args> args arglist
%type <funccall> funccall
%type <block> block
%type <stmt> stmt decl assign
%type <stmts> stmts
%type <decvars> decvars
%type <decvar> decvar
%type <params> params paramlist
%type <decfunc> decfunc

%left OR
%left AND
%left EQ DIFF
%left LESS LEQ GEQ GREAT
%left PLUS MINUS
%left STAR SLASH
%left NOT
%left UMINUS

%%

program     : instr
            ;
instr       : decvar instr { program.push_back($1); }
            | decfunc instr { program.push_back($1); }
            | /*empty*/
            ;
decvar      : type ID SCOLON { $$ = new AST::DecVar($1, $2); }
            | type ID SCOLON ASS expr { $$ = new AST::DecVar($1, $2, $5); }
            ;
decfunc     : DEF type ID LPAR paramlist RPAR block { $$ = new AST::DecFunc($2, $3, $5, $7); }
            | DEF type ID LPAR RPAR block { $$ = new AST::DecFunc($2, $3, $6); }
            ;
paramlist   : type ID params { $3->emplace_back($1, $2); $$ = $3; }
            ;
params      : COMMA type ID params { $4->emplace_back($2, $3); $$ = $4; }
            | /*empty*/ { $$ = new std::vector<AST::Param>(); }
            ;
block       : LBRAC decvars stmts RBRAC { $$ = new AST::Block($2, $3); }
            ;
decvars     : decvar decvars { $2->push_back($1); $$ = $2; }
            | /*empty*/ { $$ = new std::vector<AST::DecVar *>(); }
            ;
stmts       : stmt stmts { $2->push_back($1); $$ = $2; }
            | /*empty*/ { $$ = new std::vector<AST::Stmt *>(); }
            ;
stmt        : decl SCOLON { $$ = $1; }
            | IF LPAR expr RPAR block { $$ = new AST::If($3, $5); }
            | IF LPAR expr RPAR block ELSE block { $$ = new AST::If($3, $5, $7); }
            | WHILE LPAR expr RPAR block { $$ = new AST::While($3, $5); }
            | RETURN expr SCOLON { $$ = new AST::Return($2); }
            | RETURN SCOLON { $$ = new AST::Return(); }
            | BREAK SCOLON { $$ = new AST::Break(); }
            | CONTINUE SCOLON { $$ = new AST::Continue(); }
            ;
decl        : assign { $$ = $1; }
            | funccall { $$ = $1; }
            ;
assign      : ID ASS expr { $$ = new AST::Assign($1, $3); }
            ;
funccall    : ID LPAR arglist RPAR { $$ = new AST::FuncCall($1, $3); }
            | ID LPAR RPAR { $$ = new AST::FuncCall($1); }
            ;
arglist     : expr args { $2->push_back($1); $$ = $2; }
            ;
args        : COMMA expr args { $3->push_back($2); $$ = $3; }
            | /*empty*/ { $$ = new std::vector<AST::Expr *>(); }
            ;
expr        : expr PLUS expr { $$ = new AST::Add($1, $3); }
            | expr MINUS expr { $$ = new AST::Sub($1, $3); }
            | expr STAR expr { $$ = new AST::Times($1, $3); }
            | expr SLASH expr { $$ = new AST::Div($1, $3); }
            | expr LESS expr { $$ = new AST::Less($1, $3); }
            | expr LEQ expr { $$ = new AST::Leq($1, $3); }
            | expr GREAT expr { $$ = new AST::Great($1, $3); }
            | expr GEQ expr { $$ = new AST::Geq($1, $3); }
            | expr EQ expr { $$ = new AST::Eq($1, $3); }
            | expr DIFF expr { $$ = new AST::Diff($1, $3); }
            | expr AND expr { $$ = new AST::And($1, $3); }
            | expr OR expr { $$ = new AST::Or($1, $3); }
            | MINUS expr %prec UMINUS { $$ = new AST::Opp($2); }
            | NOT expr { $$ = new AST::Not($2); }
            | LPAR expr RPAR { $$ = $2; }
            | funccall { $$ = $1; }
            | DEC { $$ = new AST::Number($1); }
            | ID { $$ = new AST::Var($1); }
            ;
type        : INT { $$ = $1; }
            | VOID { $$ = $1; }
            ;
%%
