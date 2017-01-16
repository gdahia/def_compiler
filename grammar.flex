%option noyywrap
ID [a-zA-Z][[a-zA-Z0-9_]*
DECIMAL [0-9]+
COMMENT \/\/.*$
WHITESPACE [ \t\n]+
SYM \(|\{|\[|\]|\}|\)|\,|\;|\=\=?|\+|\-|\*|\/|\<\=?|\>\=?|\!\=?|\&\&|\|\|s
KEY def|if|else|while|return|break|continue|int|void

%%

{KEY} printf( "KEY \"%s\"\n", yytext);

{ID} printf("ID \"%s\"\n", yytext);

{DECIMAL} printf("DECIMAL \"%d\"\n", atoi(yytext));

{SYM} printf("SYM \"%s\"\n", yytext);

{COMMENT} /* eat up one-line comments */

{WHITESPACE} /* eat up whitespace */

. {
    printf("ERROR %s\n", yytext);
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
