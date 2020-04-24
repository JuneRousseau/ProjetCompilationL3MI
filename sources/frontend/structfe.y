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

%start program_start

%%

primary_expression
: '(' expression ')' { $$.code = init_code($$.code);
     $$.code = concatener($$.code, $2.code, NULL);
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
$$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "()", ";\n", NULL);}


| postfix_expression '(' argument_expression_list ')'
	{
$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
 $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res,"(", $3.res, $3.code,")", ";\n", NULL);
}


| postfix_expression '.' IDENTIFIER {printf("NORMALEMENT ON PEUT PAS UTILISER CA"); $$.code=NULL; $$.res=NULL;}

| postfix_expression PTR_OP IDENTIFIER /* ATTENTION, les structures n'existent pas dans le backend, il faudra modifier cet routine sémantique */
{$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "->", strdup($3->nom), ";\n", NULL);
}
;





argument_expression_list
        : expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}

| argument_expression_list ',' expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.code = concatener($$.code, $1.code, ",", $3.res, NULL);
}
        ;





unary_expression
        : postfix_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
| unary_operator unary_expression
{ $$.code = init_code($$.code);
$$.res = strdup(new_var($$.res)); /* stockage du resultat*/
$$.code = concatener($$.code, $2.code, $$.res, " = ", $1.code, $2.res,";\n", NULL); 
/* on ecrit le code deja généré*/
/*creer une nouvelle variable, stocke le resultat*/
/*on ecrit l'operateur*/
/*ecrit la variable ou est stockée le resultat calculé*/
}

| SIZEOF unary_expression
{$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $$.res, " = sizeof(",$2.res , ");\n", NULL);}
;

unary_operator
: '&' { $$.code = init_code($$.code); $$.code = ajouter_code($$.code, "&");}
        | '*' { $$.code = init_code($$.code); $$.code = ajouter_code($$.code, "*");}
        | '-'{ $$.code = init_code($$.code); $$.code = ajouter_code($$.code, "-");}
        ;

multiplicative_expression
: unary_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}

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
        : multiplicative_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
        | additive_expression '+' multiplicative_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "+", $3.res, ";\n",  NULL); }

        | additive_expression '-' multiplicative_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "-", $3.res, ";\n", NULL); }
        ;

relational_expression
        : additive_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
        | relational_expression '<' additive_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<", $3.res, ";\n", NULL); }
        | relational_expression '>' additive_expression  {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">", $3.res, ";\n", NULL); }
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
        : relational_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
        | equality_expression EQ_OP relational_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "==", $3.res, ";\n", NULL); }
        | equality_expression NE_OP relational_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "!=", $3.res, ";\n",  NULL); }
        ;

/* il faut scinder les && et || en if */
logical_and_expression
        : equality_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}

| logical_and_expression AND_OP equality_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
/*$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "&&", $3.res, ";\n", NULL);*/
char* label_suite;
 char* label_falsee;
char* label_truee;
label_suite= strdup(new_label(label_suite));
label_falsee= strdup(new_label(label_falsee));
label_truee= strdup(new_label(label_truee));

 $$.code = concatener($$.code, $1.code, "if ", $1.res, " goto ", label_suite,";\n", NULL);
 $$.code = concatener($$.code, "goto ", label_falsee, ";\n", NULL);
 $$.code = concatener($$.code,"\n",  label_suite, ":\n", NULL);
 $$.code = concatener($$.code, $3.code, "if ", $3.res, " goto ", label_truee,";\n", NULL);
 $$.code = concatener($$.code,"goto ", label_falsee, ";\n", NULL);
 $$.code = concatener($$.code,"\n",  label_truee,":\n", $$.res, "= 1;\n", NULL);
 $$.code = concatener($$.code,"\n", label_falsee,":\n", $$.res, "= 0;\n", NULL);
 }
        ;

logical_or_expression
        : logical_and_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
        | logical_or_expression OR_OP logical_and_expression {
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
/*$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "||", $3.res, ";\n", NULL);*/
char* label_suite;
char* label_falsee;
char* label_truee;
label_suite= strdup(new_label(label_suite));
label_falsee= strdup(new_label(label_falsee));
label_truee= strdup(new_label(label_truee));
 
 $$.code = concatener($$.code,"", $1.code, "if ", $1.res, "goto ", label_truee,";\n", NULL);
 $$.code = concatener($$.code,"", "goto ", label_suite, ";\n", NULL);
 $$.code = concatener($$.code,"", label_suite, ":\n", NULL);
 $$.code = concatener($$.code,"", $3.code, "if ", $3.res, "goto ", label_truee,";\n", NULL);
 $$.code = concatener($$.code,"", "goto ", label_falsee, ";\n", NULL);
 $$.code = concatener($$.code,"", label_truee,":\n", $$.res, "= 1;\n", NULL);
 $$.code = concatener($$.code,"", label_falsee,":\n", $$.res, "= 0;\n", NULL);
}
        ;

expression
: logical_or_expression {$$.code = strdup($1.code); $$.res = strdup($1.res);}
        | unary_expression '=' expression  {
$$.code = init_code($$.code);
$$.res = strdup($1.res);
 $$.code = concatener($$.code, $1.code, $3.code, $1.res, " = ", $3.res, ";\n", NULL);}
        ;

declaration
        : declaration_specifiers declarator ';'
{
$$.code=init_code($$.code);
$$.code=concatener($$.code, $1.code, " ", $2.code, ";\n", NULL);
}

        | struct_specifier ';'
{
$$.code=strdup("not yet implemented: struct specifier");
}
        ;


declaration_specifiers
        : EXTERN type_specifier
{
$$.code=init_code($$.code);
 $$.code= concatener($$.code, "extern ", $2.code, NULL);
}

| type_specifier {$$.code= strdup($1.code);}
        ;


type_specifier
        : VOID {$$.code= strdup("void");}
        | INT {$$.code= strdup("int");}
        | struct_specifier {$$.code= strdup("not yet implemented: struct_specifier");}
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
{
$$.code= init_code($$.code);
$$.code= concatener($$.code, "*", $2.code, NULL);
}
        | direct_declarator {$$.code= strdup($1.code);}
        ;

direct_declarator
:  '(' declarator ')' { $$.code = init_code($$.code); $$.code = concatener($$.code, "(", $2.code, ")", NULL);}

| IDENTIFIER {$$.code = strdup($1->nom);}

| direct_declarator '(' parameter_list ')'
{$$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "(",$3.code,")", NULL);}	      

| direct_declarator '(' ')'
{$$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "()", NULL);}
        ;

parameter_list
        : parameter_declaration
{$$.code = strdup($1.code);}
        | parameter_list ',' parameter_declaration
{
$$.code = init_code($$.code);
$$.code = concatener($$.code, $1.code, "," , $3.code, NULL);
}
        ;

parameter_declaration
: declaration_specifiers declarator {$$.code=init_code($$.code); $$.code=concatener($$.code, $1.code, " ", $2.code," ", NULL);}
        ;

statement
        : compound_statement {$$.code = strdup($1.code); /*printf("%s", $$.code);*/}
        | expression_statement {$$.code = strdup($1.code); /*printf("%s", $$.code);*/}
        | selection_statement {$$.code = strdup($1.code); /*printf("%s", $$.code);*/}
        | iteration_statement {$$.code = strdup($1.code); /*printf("%s", $$.code);*/}
        | jump_statement {$$.code = strdup($1.code); /*printf("%s", $$.code);*/}
        ;

compound_statement
: '{' '}' {$$.code = init_code($$.code); $$.code= ajouter_code($$.code, "{ }\n");}


| '{' statement_list '}'{$$.code = init_code($$.code);
     $$.code= concatener($$.code, "{\n", $2.code ,"}\n", NULL);

}


| '{' declaration_list '}' {$$.code = init_code($$.code);
     $$.code= concatener($$.code, "{\n", $2.code ,"}\n", NULL);}


| '{' declaration_list statement_list '}' {$$.code = init_code($$.code);
     $$.code= concatener($$.code, "{\n", $2.code, $3.code ,"}\n", NULL);}
        ;

declaration_list
        : declaration
{$$.code= strdup($1.code);}

| declaration_list declaration {
$$.code= init_code($$.code);
$$.code= concatener($$.code, $1.code, $2.code, NULL);
}
        ;

statement_list
        : statement {$$.code=strdup($1.code);}
        | statement_list statement {
$$.code=init_code($$.code);
$$.code=concatener($$.code, $1.code, $2.code, NULL);}
        ;

expression_statement
        : ';' { $$.code = init_code($$.code);
     $$.code=ajouter_code($$.code, ";\n"); $$.res= NULL;}


| expression ';' {$$.code= strdup($1.code);
$$.res= strdup($1.res);
/*$$.code= ajouter_code($$.code, ";\n"); */}
        ;

selection_statement
        : IF '(' expression ')' statement %prec "then" {
char* label_falsee;
char* label_truee;
label_falsee= strdup(new_label(label_falsee));
label_truee= strdup(new_label(label_truee));
$$.code= strdup($3.code);
$$.code= concatener($$.code, "if ", $3.res, " goto ", label_truee, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
$$.code = concatener($$.code, label_truee, ":\n", $5.code, label_falsee, ":\n", NULL);
$$.res = NULL;
}

| IF '(' expression ')' statement ELSE statement
{
char* label_falsee;
char* label_truee;
label_falsee= strdup(new_label(label_falsee));
label_truee= strdup(new_label(label_truee));
$$.code= strdup($3.code);
$$.code= concatener($$.code, "if ", $3.res, " goto ", label_truee, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
$$.code = concatener($$.code, label_truee, ":\n", $5.code, NULL);
$$.code = concatener($$.code, label_falsee, ":\n", $7.code,  NULL);
$$.res= NULL;
}
        ;

iteration_statement
        : WHILE '(' expression ')' statement
{
char* label_loop;
char* label_end;
label_loop  = strdup(new_label(label_loop));
label_end= strdup(new_label(label_end));

$$.code=init_code($$.code);
$$.code= concatener($$.code, $3.code, "\n", NULL);
$$.code= concatener($$.code, "if ", $3.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n", NULL);
$$.code = concatener($$.code, label_loop, ":\n", $5.code, "\n", $3.code, "\n", NULL);
$$.code= concatener($$.code, "if ", $3.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,":\n", NULL);
$$.res= NULL;
}


| FOR '(' expression_statement expression_statement expression ')' statement
{
char* label_loop;
char* label_end;
label_loop  = strdup(new_label(label_loop));
label_end= strdup(new_label(label_end));

$$.code=init_code($$.code);
$$.code= concatener($$.code, $3.code, NULL);
$$.code= concatener($$.code, $4.code, NULL);
$$.code= concatener($$.code, "if ", $4.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n", NULL);
$$.code = concatener($$.code, label_loop, ":\n", $7.code, "\n", $5.code, "\n", $4.code, NULL);
$$.code= concatener($$.code, "if ", $4.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,":\n", NULL);
$$.res= NULL;
}
        ;

jump_statement
: RETURN ';' {$$.code= init_code($$.code); $$.code= ajouter_code($$.code, "return ;\n");}

| RETURN expression ';' {$$.code= strdup($2.code);
$$.code= concatener($$.code, "return ", $2.res," ;\n", NULL);}
        ;
program_start
: program {printf("%s",$1.code);}

program
        : external_declaration
{
$$.code= strdup($1.code);
}
        | program external_declaration
{
$$.code = init_code($$.code);
 $$.code = concatener($$.code, $1.code, $2.code, NULL);
}
        ;

external_declaration
        : function_definition
{

}
        | declaration
{
$$.code = strdup($1.code);
}
        ;

function_definition
        : declaration_specifiers declarator compound_statement
	{
$$.code = init_code($$.code);
 $$.code = concatener($$.code, $1.code, " " ,$2.code, $3.code, NULL);
}
        ;

%%
	 
int main()
{

    init_pile();
    init_cpt_var();
    init_cpt_label();

    int c = yyparse();
    while(c)
    {
	c=yyparse();
    }

    /*afficher_pile();*/
    printf("\n\n\nAccepted\n");
}

extern int yylineno;
int yyerror(char* s)
{
    printf("line %d: %s\n", yylineno, s);
  exit(1);

}
