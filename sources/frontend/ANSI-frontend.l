D                       [0-9]
L                       [a-zA-Z_]

%option yylineno

%{
#include <stdio.h>
#include "structfe.tab.h"
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
{D}+                    { return CONSTANT; } /* constance numérique */

"/*"([^*]|(\*+[^*/]))*\*+\/    ; /* Commentaires */

"->"                    { return PTR_OP; }
"&&"                    { return AND_OP; }
"||"                    { return OR_OP; }
"<="                    { return LE_OP; }
">="                    { return GE_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NE_OP; }


[\n\t\r\v\f ]           ;

.                       { return yytext[0]; }

%%
