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
"else"                  { printf("reconnu:%s \n", yytext); return ELSE; }
"extern"                { printf("reconnu:%s \n", yytext); return EXTERN; }
"for"                   { printf("reconnu:%s \n", yytext); return FOR; }
"if"                    { printf("reconnu:%s \n", yytext); return IF; }
"int"                   { printf("reconnu:%s \n", yytext); return INT; }
"return"                { printf("reconnu:%s \n", yytext); return RETURN; }
"sizeof"                { printf("reconnu:%s \n", yytext); return SIZEOF; }
"struct"                { printf("reconnu:%s \n", yytext); return STRUCT; }
"void"                  { printf("reconnu:%s \n", yytext); return VOID; }
"while"                 { printf("reconnu:%s \n", yytext); return WHILE; }

{L}({L}|{D})*           { printf("reconnu:%s \n", yytext); return IDENTIFIER; } /*identificateurs de variable*/
{D}+               { printf("reconnu:%s \n", yytext); return CONSTANT; } /* constance numérique */

"/*"[.\n]*"*/"         {printf("COMMENTAIRE OUI OU NON?");} /* Commentaires */

"->"                    { printf("reconnu:%s \n", yytext); return PTR_OP; }
"&&"                    { printf("reconnu:%s \n", yytext); return AND_OP; }
"||"                    { printf("reconnu:%s \n", yytext); return OR_OP; }
"<="                    { printf("reconnu:%s \n", yytext); return LE_OP; }
">="                    { printf("reconnu:%s \n", yytext); return GE_OP; }
"=="                    { printf("reconnu:%s \n", yytext); return EQ_OP; }
"!="                    { printf("reconnu:%s \n", yytext); return NE_OP; }
"("                     { printf("reconnu:%s \n", yytext); return '(';}
")"                     { printf("reconnu:%s \n", yytext); return ')';}
";"                     { printf("reconnu:%s \n", yytext); return ';';}
[\n\t ]             {printf("reconnu:%d (ascii) \n", yytext[0]);}

.                       { printf("wtf: %d ", yytext[0]); return yytext[0]; }

%%
