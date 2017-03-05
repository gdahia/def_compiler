%{
#include <iostream>
#include <string>

enum TokenType {
    ID = 0x0,
    DEC = 0x1,
    IF = 0x2,
    ELSE = 0x3,
    WHILE = 0x4,
    RETURN = 0x5,
    BREAK = 0x6,
    CONTINUE = 0x7,
    DEF = 0x8,
    INT = 0x9,
    VOID = 0xA,
    LPAR = 0xB,
    RPAR = 0xC,
    SCOLON = 0xD,
    COMMA = 0xE,
    LBRAC = 0xF,
    RBRAC = 0x10,
    PLUS = 0x11,
    MINUS = 0x12,
    STAR = 0x13,
    SLASH = 0x14,
    LESS = 0x15,
    LEQ = 0x16,
    GREAT = 0x17,
    GEQ = 0x18,
    ASS = 0x19,
    EQ = 0x1A,
    DIFF = 0x1B,
    AND = 0x1C,
    OR = 0x1D,
    NOT = 0x1E,
    COMMENT = 0x1F,
    ERROR = 0x20,
    EoF = 0x21
};

std::string lexeme;
%}

%option noyywrap

%%

"def" return DEF;

"if" return IF;

"else" return ELSE;

"while" return WHILE;

"return" return RETURN;

"break" return BREAK;

"continue" return CONTINUE;

"int" return INT;

"void" return VOID;

[a-zA-Z][a-zA-Z0-9_]* lexeme = yytext; return ID;

[0-9]+ lexeme = yytext; return DEC;

"(" return LPAR;

"{" return LBRAC;

"}" return RBRAC;

")" return RPAR;

"," return COMMA;

";" return SCOLON;

"=" return ASS;

"==" return EQ;

"+" return PLUS;

"-" return MINUS;

"*" return STAR;

"/" return SLASH;

"<" return LESS;

"<=" return LEQ;

">" return GREAT;

">=" return GEQ;

"!" return NOT;

"!=" return DIFF;

"&&" return AND;

"||" return OR;

\/\/.*$ /* eat up one-line comments */

[ \t\n]+ /* eat up whitespace */

<<EOF>> return EOF;

. {
    fprintf(stderr, "ERROR\t\"%s\"\n", yytext);
    yyterminate();
}

%%

int main(int argc, char **argv) {
    if (argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
    if (argc > 2)
        stdout = fopen(argv[2], "w");
    int t;
    while ((t = yylex()) != EOF) {
        switch (t) {
            case IF: std::cout << "KEY\t\"if\""; break;
            case ELSE: std::cout << "KEY\t\"else\""; break;
            case WHILE: std::cout << "KEY\t\"while\""; break;
            case BREAK: std::cout << "KEY\t\"break\""; break;
            case CONTINUE: std::cout << "KEY\t\"continue\""; break;
            case RETURN: std::cout << "KEY\t\"return\""; break;
            case INT: std::cout << "KEY\t\"int\""; break;
            case DEF: std::cout << "KEY\t\"def\""; break;
            case VOID: std::cout << "KEY\t\"void\""; break;
            case LPAR: std::cout << "SYM\t\"(\""; break;
            case RPAR: std::cout << "SYM\t\")\""; break;
            case LBRAC: std::cout << "SYM\t\"{\""; break;
            case RBRAC: std::cout << "SYM\t\"}\""; break;
            case NOT: std::cout << "SYM\t\"!\""; break;
            case EQ: std::cout << "SYM\t\"==\""; break;
            case ASS: std::cout << "SYM\t\"=\""; break;
            case SCOLON: std::cout << "SYM\t\";\""; break;
            case PLUS: std::cout << "SYM\t\"+\""; break;
            case MINUS: std::cout << "SYM\t\"-\""; break;
            case COMMA: std::cout << "SYM\t\",\""; break;
            case DIFF: std::cout << "SYM\t\"!=\""; break;
            case GEQ: std::cout << "SYM\t\">=\""; break;
            case LEQ: std::cout << "SYM\t\"<=\""; break;
            case GREAT: std::cout << "SYM\t\">\""; break;
            case LESS: std::cout << "SYM\t\"<\""; break;
            case STAR: std::cout << "SYM\t\"*\""; break;
            case SLASH: std::cout << "SYM\t\"/\""; break;
            case OR: std::cout << "SYM\t\"||\""; break;
            case AND: std::cout << "SYM\t\"&&\""; break;
            case ID: std::cout << "ID\t\"" << lexeme << "\""; break;
            case DEC: std::cout << "DEC\t\"" << lexeme << "\""; break;
            case ERROR: std::cout << "ERROR\t"; break;
            default: break;
        }
        std::cout << std::endl;
    }
    return 0;
}
