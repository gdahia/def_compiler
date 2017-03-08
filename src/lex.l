%{
#include <iostream>
#include <memory>
#include <string>

#include <ast.hpp>
#include <parser.hpp>
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

"int" return yylval.token = INT;

"void" return yylval.token = VOID;

[a-zA-Z][a-zA-Z0-9_]* yylval.lexeme = std::make_shared<std::string>(yytext, yyleng); return ID;

[0-9]+ yylval.lexeme = std::make_shared<std::string>(yytext, yyleng); return DEC;

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
    throw std::runtime_error("Unrecognized token \"" + std::string(yytext) + "\" in line " + std::to_string(yylineno));
}

%%
