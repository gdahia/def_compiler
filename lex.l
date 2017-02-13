%option noyywrap
ID [a-zA-Z][[a-zA-Z0-9_]*
DECIMAL [0-9]+
COMMENT \/\/.*$
WHITESPACE [ \t\n]+
SYM \(|\{|\[|\]|\}|\)|\,|\;|\=\=?|\+|\-|\*|\/|\<\=?|\>\=?|\!\=?|\&\&|\|\|
KEY def|if|else|while|return|break|continue|int|void

%%

{KEY} printf( "KEY\t\"%s\"\n", yytext);

{ID} printf("ID\t\"%s\"\n", yytext);

{DECIMAL} printf("DEC\t\"%s\"\n", yytext);

{SYM} printf("SYM\t\"%s\"\n", yytext);

{COMMENT} /* eat up one-line comments */

{WHITESPACE} /* eat up whitespace */

. {
    fprintf(stderr, "ERROR\t\"%s\"\n", yytext);
    exit(1);
}

%%

int main(int argc, char **argv ) {
    if (argc > 0)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;
    if (argc > 1)
        stdout = fopen(argv[2], "w");
    yylex();
    return 0;
}
