D                       [0-9]
L                       [a-zA-Z_]
l                       [a-zA-Z]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

com_s "/*"
com_e "*/"

%option yylineno

%{
#include <stdio.h>
#include "structfe.tab.h"


/* Ne gère pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */
%}

%%
"else"                  { return ELSE; }
"extern"                { return EXTERN; }
"for"                   { return FOR; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"sizeof"                { return SIZEOF; }
"struct"                { return STRUCT; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

{L}({L}|{D})*           { return IDENTIFIER; } /*identificateurs de variable*/
{D}+               { return CONSTANT; } /* constance numérique */

"/*"(.|\n|\r)*"*/"        ; /* Commentaires */

"->"                    { return PTR_OP; }
"&&"                    { return AND_OP; }
"||"                    { return OR_OP; }
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
