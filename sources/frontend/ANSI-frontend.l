D                       [0-9]
L                       [a-zA-Z_]
l                       [a-zA-Z]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%option yylineno

%{
#include <stdio.h>
#include "structfe.tab.h"


/* Ne gère pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

%%
"else"                  { printf("%s ", yytext); return ELSE; }
"extern"                { printf("%s ", yytext); return EXTERN; }
"for"                   { printf("%s ", yytext); return FOR; }
"if"                    { printf("%s ", yytext); return IF; }
"int"                   { printf("int "); return INT; }
"return"                { printf("%s ", yytext); return RETURN; }
"sizeof"                { printf("%s ", yytext); return SIZEOF; }
"struct"                { printf("%s ", yytext); return STRUCT; }
"void"                  { printf("%s ", yytext); return VOID; }
"while"                 { printf("%s ", yytext); return WHILE; }

{L}({L}|{D})*           { printf("%s ", yytext); return IDENTIFIER; } /*identificateurs de variable*/
{D}+               { printf("%s ", yytext); return CONSTANT; } /* constance numérique */

"/*"[.\n]*"*/"         {printf("COMMENTAIRE OUI OU NON?");} /* Commentaires */

"->"                    { printf("%s ", yytext); return PTR_OP; }
"&&"                    { printf("%s ", yytext); return AND_OP; }
"||"                    { printf("%s ", yytext); return OR_OP; }
"<="                    { printf("%s ", yytext); return LE_OP; }
">="                    { printf("%s ", yytext); return GE_OP; }
"=="                    { printf("%s ", yytext); return EQ_OP; }
"!="                    { printf("%s ", yytext); return NE_OP; }

[ \t\v\f]               ;
\n                      {printf(" RetourChariot ", yylineno);}
.                       { printf("%s", yytext); return yytext[0]; }

%%
