%{
#include <vector>
#include <string>

#include <ast.hpp>

std::vector<std::shared_ptr<AST::Instr>> program;

extern int yylex();

void yyerror(const char * s) {
    // throw std::runtime_error("Error: " + std::string
    printf("ERROR: %s\n", s);
}

%}

%code requires {
#include <holder.hpp>

#define YYSTYPE Holder
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
decvar      : type ID SCOLON { $$ = std::make_shared<AST::DecVar>($1, $2); }
            | type ID SCOLON ASS expr { $$ = std::make_shared<AST::DecVar>($1, $2, $5); }
            ;
decfunc     : DEF type ID LPAR paramlist RPAR block { $$ = std::make_shared<AST::DecFunc>($2, $3, $5, $7); }
            | DEF type ID LPAR RPAR block { $$ = std::make_shared<AST::DecFunc>($2, $3, $6); }
            ;
paramlist   : type ID params { $3->emplace_back($1, $2); $$ = $3; }
            ;
params      : COMMA type ID params { $4->emplace_back($2, $3); $$ = $4; }
            | /*empty*/ { $$ = std::make_shared<std::vector<AST::Param>>(); }
            ;
block       : LBRAC decvars stmts RBRAC { $$ = std::make_shared<AST::Block>($2, $3); }
            ;
decvars     : decvar decvars { $2->push_back($1); $$ = $2; }
            | /*empty*/ { $$ = std::make_shared<std::vector<std::shared_ptr<AST::DecVar>>>(); }
            ;
stmts       : stmt stmts { $2->push_back($1); $$ = $2; }
            | /*empty*/ { $$ = std::make_shared<std::vector<std::shared_ptr<AST::Stmt>>>(); }
            ;
stmt        : decl SCOLON { $$ = $1; }
            | IF LPAR expr RPAR block { $$ = std::make_shared<AST::If>($3, $5); }
            | IF LPAR expr RPAR block ELSE block { $$ = std::make_shared<AST::If>($3, $5, $7); }
            | WHILE LPAR expr RPAR block { $$ = std::make_shared<AST::While>($3, $5); }
            | RETURN expr SCOLON { $$ = std::make_shared<AST::Return>($2); }
            | RETURN SCOLON { $$ = std::make_shared<AST::Return>(); }
            | BREAK SCOLON { $$ = std::make_shared<AST::Break>(); }
            | CONTINUE SCOLON { $$ = std::make_shared<AST::Continue>(); }
            ;
decl        : assign { $$ = $1; }
            | funccall { $$ = $1; }
            ;
assign      : ID ASS expr { $$ = std::make_shared<AST::Assign>($1, $3); }
            ;
funccall    : ID LPAR arglist RPAR { $$ = std::make_shared<AST::FuncCall>($1, $3); }
            | ID LPAR RPAR { $$ = std::make_shared<AST::FuncCall>($1); }
            ;
arglist     : expr args { $2->push_back($1); $$ = $2; }
            ;
args        : COMMA expr args { $3->push_back($2); $$ = $3; }
            | /*empty*/ { $$ = std::make_shared<std::vector<std::shared_ptr<AST::Expr>>>(); }
            ;
expr        : expr PLUS expr { $$ = std::make_shared<AST::Add>($1, $3); }
            | expr MINUS expr { $$ = std::make_shared<AST::Sub>($1, $3); }
            | expr STAR expr { $$ = std::make_shared<AST::Times>($1, $3); }
            | expr SLASH expr { $$ = std::make_shared<AST::Div>($1, $3); }
            | expr LESS expr { $$ = std::make_shared<AST::Less>($1, $3); }
            | expr LEQ expr { $$ = std::make_shared<AST::Leq>($1, $3); }
            | expr GREAT expr { $$ = std::make_shared<AST::Great>($1, $3); }
            | expr GEQ expr { $$ = std::make_shared<AST::Geq>($1, $3); }
            | expr EQ expr { $$ = std::make_shared<AST::Eq>($1, $3); }
            | expr DIFF expr { $$ = std::make_shared<AST::Diff>($1, $3); }
            | expr AND expr { $$ = std::make_shared<AST::And>($1, $3); }
            | expr OR expr { $$ = std::make_shared<AST::Or>($1, $3); }
            | MINUS expr %prec UMINUS { $$ = std::make_shared<AST::Opp>($2); }
            | NOT expr { $$ = std::make_shared<AST::Not>($2); }
            | LPAR expr RPAR { $$ = $2; }
            | funccall { $$ = $1; }
            | DEC { $$ = std::make_shared<AST::Number>($1); }
            | ID { $$ = std::make_shared<AST::Var>($1); }
            ;
type        : INT { $$ = $1; }
            | VOID { $$ = $1; }
            ;
%%
