%{
#include "structfe.h"

%}

%token <attributs> SIZEOF
%token <attributs> PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token <attributs> AND_OP OR_OP
%token <attributs> EXTERN
%token <attributs> INT VOID
%token <attributs> STRUCT 
%token <attributs> IF ELSE WHILE FOR RETURN
%token <attributs> '(' ')' '{' '}' ';' '&' '*' '-' ',' '.' '+' '>' '<' '='
%token <symbol> IDENTIFIER
%token	<number>	CONSTANT

%type <attributs> primary_expression postfix_expression argument_expression_list unary_expression unary_operator multiplicative_expression additive_expression relational_expression equality_expression logical_and_expression logical_or_expression expression declaration declaration_specifiers type_specifier  struct_specifier struct_declaration_list struct_declaration declarator direct_declarator parameter_list parameter_declaration statement compound_statement  declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement program external_declaration function_definition
			
%nonassoc "then"
%nonassoc ELSE


%union {
    char *number;
    attributs_t attributs;
    symbole_t *symbol;
    }

%start program

%%

primary_expression
: '(' expression ')' { $$.code = init_code($$.code);
     $$.code = ajouter_code($$.code, "(");
     $$.code = ajouter_code($$.code, $2.code);
     $$.code = ajouter_code($$.code, ")");
$$.res = strdup($2.res);

}


|	CONSTANT {
$$.code = init_code($$.code);
$$.res = $1;
}


|	IDENTIFIER {
$$.code = init_code($$.code);
$$.res = strdup($1->nom);} ;

postfix_expression
: primary_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
| postfix_expression '(' ')' {$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "();\n", NULL);}
        | postfix_expression '(' argument_expression_list ')'
	{$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "(", $3.res,");\n", NULL);}
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER
{$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "->", strdup($3->nom),";\n", NULL);}
        ;

argument_expression_list
        : expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
| argument_expression_list ',' expression {$$.code = strdup($1.code); $$.res = strdup($1.res); $$.code = concatener($$.code, $1.code, ",", $3.res, NULL);}
        ;

unary_expression
        : postfix_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
| unary_operator unary_expression
{ $$.code = init_code($$.code);
$$.res = strdup(new_var($$.res)); /* stockage du resultat*/
 $$.code = concatener($$.code, $2.code, $$.res, " = ", $1.code, $2.res, ";\n", NULL); 
/* on ecrit le code deja généré*/
/*creer une nouvelle variable, stocke le resultat*/
/*on ecrit l'operateur*/
/*ecrit la variable ou est stockée le resultat calculé*/
}
        | SIZEOF unary_expression  {$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
 $$.code = concatener($$.code,$$.res, " = sizeof(",$2.res , ");\n");
$$.res = strdup($2.res);}
        ;

unary_operator
: '&' { $$.code = init_code($$.code); $$.code = ajouter_code($$.code, "&");}
        | '*' { $$.code = init_code($$.code); $$.code = ajouter_code($$.code, "*");}
        | '-'{ $$.code = init_code($$.code); $$.code = ajouter_code($$.code, "-");}
        ;

multiplicative_expression
: unary_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);}
        | multiplicative_expression '*' unary_expression
{$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
 $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "*", $3.res, ";\n", NULL); 
/*code de multiplicative expression*/
/*code de unary expression*/
/*creer une nouvelle variable, stocke le resultat*/
/*resultat de multiplicative*/
/*on ecrit l'operateur*/
/*resultat de unary*/
}
        | multiplicative_expression '/' unary_expression
{$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "/", $3.res, ";\n", NULL); 
/*code de multiplicative expression*/
/*code de unary expression */
/*creer une nouvelle variable, stocke le resultat*/
/*resultat de multiplicative*/
/*on ecrit l'operateur*/
/*resultat de unary*/}

        ;

additive_expression
        : multiplicative_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);}
        | additive_expression '+' multiplicative_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "+", $3.res, ";\n", NULL); }
        | additive_expression '-' multiplicative_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "-", $3.res, ";\n", NULL); }
        ;

relational_expression
        : additive_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);}
        | relational_expression '<' additive_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">", $3.res, ";\n", NULL); }
        | relational_expression '>' additive_expression  {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<", $3.res, ";\n", NULL); }
        | relational_expression LE_OP additive_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<=", $3.res, ";\n", NULL); }
        | relational_expression GE_OP additive_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">=", $3.res, ";\n", NULL); }
        ;

equality_expression
        : relational_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);}
        | equality_expression EQ_OP relational_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "==", $3.res, ";\n", NULL); }
        | equality_expression NE_OP relational_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "!=", $3.res, ";\n", NULL); }
        ;

/* il faut scinder les && et || en if */
logical_and_expression
        : equality_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);}
        | logical_and_expression AND_OP equality_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "&&", $3.res, ";\n", NULL); }
        ;

logical_or_expression
        : logical_and_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);}
        | logical_or_expression OR_OP logical_and_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "||", $3.res, ";\n", NULL); }
        ;

expression
: logical_or_expression {$$.code = strdup($1.code); $$.res = strdup($$.res);
printf("%s\n", $$.code);}
        | unary_expression '=' expression  {
$$.code = init_code($$.code);
$$.res = strdup($1.res);
$$.code = concatener($$.code, $1.code, $3.code, $1.res, " = ", $3.res, ";\n", NULL);
printf("%s", $$.code);}
        ;

declaration
        : declaration_specifiers declarator ';'
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier
        | type_specifier
        ;

type_specifier
        : VOID
        | INT
        | struct_specifier
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}'
        | STRUCT '{' struct_declaration_list '}'
        | STRUCT IDENTIFIER
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'
        ;

declarator
        : '*' direct_declarator
        | direct_declarator
        ;

direct_declarator
:  '(' declarator ')' { $$ = $1;}
	|	IDENTIFIER {$$.code = strdup($1->nom);}
        | direct_declarator '(' parameter_list ')'
        | direct_declarator '(' ')'
        ;

parameter_list
        : parameter_declaration
        | parameter_list ',' parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        ;

statement
        : compound_statement
        | expression_statement
        | selection_statement
        | iteration_statement
        | jump_statement 
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}' 
        | '{' declaration_list '}' 
        | '{' declaration_list statement_list '}' 
        ;

declaration_list
        : declaration
        | declaration_list declaration
        ;

statement_list
        : statement
        | statement_list statement
        ;

expression_statement
        : ';'
        | expression ';'
        ;

selection_statement
        : IF '(' expression ')' statement %prec "then" 
	| IF '(' expression ')' statement ELSE statement
        ;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : RETURN ';'
        | RETURN expression ';'
        ;

program
        : external_declaration
        | program external_declaration
        ;

external_declaration
        : function_definition
        | declaration
        ;

function_definition
        : declaration_specifiers declarator compound_statement
        ;

%%
	 
int main()
{

    init_pile();
    init_cpt_var();

    
    int c = yyparse();
    while(c)
    {
	c=yyparse();
    }

    afficher_pile();
    printf("Accepted\n");
}

extern int yylineno;
int yyerror(char* s)
{
    printf("line %d: %s\n", yylineno, s);
  exit(1);

}
