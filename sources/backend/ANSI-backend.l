D                       [0-9]
L                       [a-zA-Z_]

%{
#include <stdio.h>
#include "structbe.tab.h"

int yylex();
int yyerror(char* s);
%}

%option yylineno
			
%%
"extern"                { return EXTERN; }
"goto"                  { return GOTO; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"void"                  { return VOID; }

{L}({L}|{D})*           { return IDENTIFIER; }

{D}+                    { return CONSTANT; }

"/*"(.|\n|\r)*"*/" ; /*Commentaires*/
"//"([^\n\r]*)[\n\r]


"<="                    { return LE_OP; }
">="                    { return GE_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NE_OP; }
"("                     { return '(';}
")"                     { return ')';}
";"                     { return ';';}
"{"                     { return '{';}
"}"                     { return '}';}
"="                     { return '=';}
"+"                     { return '+';}
"-"                     { return '-';}
"*"                     { return '*';}
"/"                     { return '/';}
"&"                     { return '&';}


[\n\t\r\v\f ]           ;

.                       { return yytext[0]; }
%%
