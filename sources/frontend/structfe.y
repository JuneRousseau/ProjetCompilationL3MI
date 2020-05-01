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
%token <number> CONSTANT

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
: '(' expression ')'
{
$$.code = init_code($$.code);
$$.code = concatener($$.code, $2.code, NULL);
$$.res = strdup($2.res);

$$.type= $2.type;
}

|	CONSTANT
{
$$.code = init_code($$.code);
$$.res = $1;

$$.type= INT_T;
}


| IDENTIFIER
{
$$.code = init_code($$.code);
$$.res = strdup($1->nom);

$$.type = $1->type;
} ;

postfix_expression
: primary_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);

$$.type= $1.type;
}

| postfix_expression '(' ')'
{
$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "()", ";\n", NULL);

$$.type= VOID_T ; /* attention au type d'arrivée de la fonction*/
}


| postfix_expression '(' argument_expression_list ')'
{
$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res,"(", $3.res, ")", ";\n", NULL);

$$.type= VOID_T; /* attention au type d'arrivée de la fonction*/
}

| postfix_expression PTR_OP IDENTIFIER /* ATTENTION, les structures n'existent pas dans le backend, il faudra modifier cet routine sémantique */
{
$$.code = strdup($1.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "->", strdup($3->nom), ";\n", NULL);

$$.type= VOID_T; /*type du champs de structure....*/
}
;


argument_expression_list
        : expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| argument_expression_list ',' expression
{
$$.code = init_code($$.code);
$$.code = concatener($$.code, $1.code, $3.code, NULL);
$$.res = init_code($$.res);
$$.res = concatener($$.res, $1.res, ",", $3.res, NULL);
$$.type = VOID_T; /* faire le produit des type */
}
;



unary_expression
        : postfix_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type= $1.type;
}

| unary_operator unary_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res)); /* stockage du resultat*/
$$.code = concatener($$.code, $2.code, $$.res, " = ", $1.code, $2.res,";\n", NULL);


if(strcmp($1.code, "-")) {$$.type = INT_T;}
else if(strcmp($1.code, "&")) {$$.type = VOID_T; /* retourne un pointeur sur $2.type*/}
else {$$.type = VOID_T; /* retourne le type de l'objet pointé par $2*/}

$$.type = $1.type; /*on associe le type voulu à l'opérateur cf unary_operator*/
}

| SIZEOF '(' type_specifier ')'
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $$.res, " = sizeof(", $3.code , ");\n", NULL);
$$.type= INT_T;
}

| SIZEOF unary_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $$.res, " = sizeof(",$2.res , ");\n", NULL);
$$.type= INT_T;
}

       
; 

unary_operator
: '&'
{
$$.code = init_code($$.code);
$$.code = ajouter_code($$.code, "&");
}

| '*'
{
$$.code = init_code($$.code);
$$.code = ajouter_code($$.code, "*");
}
| '-'
{
$$.code = init_code($$.code);
$$.code = ajouter_code($$.code, "-");
}
;

multiplicative_expression
: unary_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| multiplicative_expression '*' unary_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "*", $3.res, ";\n", NULL); 
$$.type = INT_T;
}

| multiplicative_expression '/' unary_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "/", $3.res, ";\n", NULL);
$$.type = INT_T;
}

        ;

additive_expression
        : multiplicative_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| additive_expression '+' multiplicative_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "+", $3.res, ";\n",  NULL);

if(($1.type == INT_T) && ($3.type == INT_T)) {$$.type = INT_T;}
else if ($1.type == INT_T) { $$.type= VOID_T; /*verifier qu'on a bien un pointeur -> renvoie un pointeur*/}
else { $$.type= VOID_T; /*verifier qu'on a bien un int pour $3 -> renvoie un pointeur*/}
}

| additive_expression '-' multiplicative_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "-", $3.res, ";\n", NULL);

if(($1.type == INT_T) && ($3.type == INT_T)) {$$.type = INT_T;}
else if ($1.type == INT_T) { $$.type= ERROR_T; /*verifier qu'on a bien un pointeur -> renvoie un pointeur*/}
else if ($3.type == INT_T) {$$.type= VOID_T;} /*pointeur*/
else {$$.type= INT_T;} /* ptr - ptr = int*/
}
        ;

relational_expression
        : additive_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| relational_expression '<' additive_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<", $3.res, ";\n", NULL);
$$.type = INT_T;
}

| relational_expression '>' additive_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">", $3.res, ";\n", NULL);
$$.type = INT_T;
}

| relational_expression LE_OP additive_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<=", $3.res, ";\n", NULL);
$$.type = INT_T;
}

| relational_expression GE_OP additive_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">=", $3.res, ";\n", NULL);
$$.type = INT_T;
}
;

equality_expression
        : relational_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| equality_expression EQ_OP relational_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "==", $3.res, ";\n", NULL);
$$.type = INT_T;
}

| equality_expression NE_OP relational_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
$$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "!=", $3.res, ";\n",  NULL);
$$.type = INT_T;
}
        ;

logical_and_expression
        : equality_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| logical_and_expression AND_OP equality_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
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

$$.type = INT_T;
}
        ;

logical_or_expression
        : logical_and_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type = $1.type;
}

| logical_or_expression OR_OP logical_and_expression
{
$$.code = init_code($$.code);
$$.res = strdup(new_var($$.res));
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

$$.type = INT_T;
}
        ;

expression
: logical_or_expression
{
$$.code = strdup($1.code);
$$.res = strdup($1.res);
$$.type= $1.type;
}

| unary_expression '=' expression
{
$$.code = init_code($$.code);
$$.res = strdup($1.res);
$$.code = concatener($$.code, $1.code, $3.code, $1.res, " = ", $3.res, ";\n", NULL);
$$.type = $3.type;
}
;

declaration
        : declaration_specifiers declarator ';'
{
$$.code=init_code($$.code);
$$.code=concatener($$.code, $1.code, " ", $2.code, ";\n", NULL);
$$.type= $2.type;
}

| struct_specifier ';'
{
$$.code= strdup("not yet implemented: struct specifier");
$$.type= VOID_T; /*type structure*/
}
;


declaration_specifiers
        : EXTERN type_specifier
{
$$.code=init_code($$.code);
$$.code= concatener($$.code, "extern ", $2.code, NULL);
$$.type = $2.type;
}

| type_specifier
{
$$.code= strdup($1.code);
$$.type= $1.type;
}
        ;


type_specifier
        : VOID
{
$$.code= strdup("void");
$$.type= VOID_T;
}

| INT
{
$$.code= strdup("int");
$$.type= INT_T;
}

| struct_specifier
{
$$.code= strdup("not yet implemented: struct_specifier");
$$.type= VOID_T; /* type structure*/
}
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
$$.type= VOID_T;
}

| direct_declarator
{
$$.code= strdup($1.code);
$$.type=VOID_T;
}
        ;

direct_declarator
:  '(' declarator ')'
{
$$.code = init_code($$.code); $$.code = concatener($$.code, "(", $3.code, ")", NULL);
$$.type=VOID_T;
}

| IDENTIFIER
{
$$.code = strdup($1->nom);
$1->type= VOID_T;
}

| direct_declarator '(' parameter_list ')'
{
$$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "(",$3.code,")", NULL);
/*ON VERIFIE QUE LE TYPE DE DIRECT_DECLARATOR EST UNE FONCTION OUI OU NON?!*/
$$.type= VOID_T; /*type fonction*/
}	      

| direct_declarator '(' ')'
{
$$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "()", NULL);
/* J'ACHETE !!!!!!*/
$$.type= VOID_T; /*type fonction*/
}
        ;

parameter_list
        : parameter_declaration
{
$$.code = strdup($1.code);
$$.type = $1.type;
}

| parameter_list ',' parameter_declaration
{
$$.code = init_code($$.code);
$$.code = concatener($$.code, $1.code, "," , $3.code, NULL);
$$.type = VOID_T; /*produit cartesien des types*/
}
        ;

parameter_declaration
: declaration_specifiers declarator
{
$$.code=init_code($$.code); $$.code=concatener($$.code, $1.code, " ", $2.code," ", NULL);
$$.type= VOID_T;
}
        ;

statement
        : compound_statement {$$.code = strdup($1.code); $$.type= $1.type;}
        | expression_statement {$$.code = strdup($1.code); $$.type= $1.type;}
        | selection_statement {$$.code = strdup($1.code); $$.type= $1.type;}
        | iteration_statement {$$.code = strdup($1.code); $$.type= $1.type;}
        | jump_statement {$$.code = strdup($1.code); $$.type= $1.type;}
        ;

compound_statement
: '{' '}'
{
$$.code = init_code($$.code); $$.code= ajouter_code($$.code, "{ }\n");
$$.type = VOID_T;
}


| '{' statement_list '}'
{
$$.code = init_code($$.code);
$$.code = concatener($$.code, "{\n", $2.code ,"}\n", NULL);
$$.type = $2.type;
}


| '{' declaration_list '}' {
$$.code = init_code($$.code);
$$.code = concatener($$.code, "{\n", $2.code ,"}\n", NULL);
$$.type = $2.type;
}


| '{' declaration_list statement_list '}' {
$$.code = init_code($$.code);
$$.code = concatener($$.code, "{\n", $2.code, $3.code ,"}\n", NULL);
$$.type = $3.type;
}
        ;

declaration_list
        : declaration
{
$$.code= strdup($1.code); /*verifier qu'on a pas une erreur de type*/
$$.type= $1.type;
}

| declaration_list declaration
{
$$.code= init_code($$.code);
$$.code= concatener($$.code, $1.code, $2.code, NULL);
$$.type= $2.type;
}
        ;

statement_list
        : statement
{
$$.code=strdup($1.code);
$$.type=$1.type;
}

| statement_list statement
{
$$.code=init_code($$.code);
$$.code=concatener($$.code, $1.code, $2.code, NULL);
$$.type= $2.type;
}
        ;

expression_statement
        : ';'
{
$$.code = init_code($$.code);
$$.code=ajouter_code($$.code, ";\n"); $$.res= NULL;
$$.type= VOID_T;
}

| expression ';'
{
$$.code= strdup($1.code);
$$.res= strdup($1.res);
$$.type= $1.type;
}
        ;

selection_statement
        : IF '(' expression ')' statement %prec "then"
{
char* label_falsee;
char* label_truee;
label_falsee= strdup(new_label(label_falsee));
label_truee= strdup(new_label(label_truee));
$$.code= init_code($$.code);
$$.code= concatener($$.code, $3.code, NULL);
$$.code= concatener($$.code, "if ", $3.res, " goto ", label_truee, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
$$.code = concatener($$.code, label_truee, ":\n", $5.code, label_falsee, ":\n", NULL);
$$.res = NULL;

$$.type = VOID_T;
}

| IF '(' expression ')' statement ELSE statement
{
char* label_falsee;
char* label_truee;
label_falsee= strdup(new_label(label_falsee));
label_truee= strdup(new_label(label_truee));
$$.code= init_code($$.code);
$$.code= concatener($$.code, $3.code,"\n", NULL);
$$.code= concatener($$.code, "if ", $3.res, " goto ", label_truee, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
$$.code = concatener($$.code, label_truee, ":\n", $5.code, NULL);
$$.code = concatener($$.code, label_falsee, ":\n", $7.code,  NULL);
$$.res= NULL;

$$.type = VOID_T;
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
$$.code= concatener($$.code, label_loop, ":\n", $5.code, "\n", $3.code, "\n", NULL);
$$.code= concatener($$.code, "if ", $3.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,":\n", NULL);
$$.res= NULL;

$$.type= VOID_T;
}


| FOR '(' expression_statement expression_statement expression ')' statement
{
char* label_loop;
char* label_end;
label_loop  = strdup(new_label(label_loop));
label_end= strdup(new_label(label_end));

$$.code= init_code($$.code);
$$.code= concatener($$.code, $3.code, NULL);
$$.code= concatener($$.code, $4.code, NULL);
$$.code= concatener($$.code, "if ", $4.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n", NULL);
$$.code= concatener($$.code, label_loop, ":\n", $7.code, "\n", $5.code, "\n", $4.code, NULL);
$$.code= concatener($$.code, "if ", $4.res , " goto ", label_loop, ";\n", NULL);
$$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,":\n", NULL);
$$.res= NULL;

$$.type= VOID_T;
}
        ;

jump_statement
: RETURN ';'
{
$$.code= init_code($$.code);
$$.code= ajouter_code($$.code, "return ;\n");
$$.type= VOID_T;
}

| RETURN expression ';'
{
$$.code= strdup($2.code);
$$.code= concatener($$.code, "return ", $2.res," ;\n", NULL);
$$.type= $2.type;
}
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
$$.code = strdup($1.code);
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
    /*
    init_pile();
    init_cpt_var();
    init_cpt_label();*/

    arbre_t *base_int1= basic_type(INT_T, "");
    arbre_t *base_int2= basic_type(INT_T, "");
    arbre_t *base_int3= basic_type(INT_T, "");
    arbre_t *base_int4= basic_type(INT_T, "");
    arbre_t *base_voidd= basic_type(VOID_T, "");
    arbre_t *ptr_int1= ptr_type(base_int1, "");
    arbre_t *ptr_int2= ptr_type(base_int2, "");
    arbre_t *ptr_voidd= ptr_type(base_voidd, "");

    arbre_t *prod_int1= prod_type(base_int1, base_int2, "");
    arbre_t *prod_int2= prod_type(base_int3, base_int4, "");
    arbre_t *prod_div= prod_type(base_int1, base_voidd, "");

    arbre_t *prod4= prod_type(ptr_int1, prod_int1, "");
    arbre_t *prod5= prod_type(ptr_int2, prod_int2, "");
    arbre_t *prod6= prod_type(ptr_int1, prod_div, "");

    arbre_t *fct1= fct_type(prod_int1, base_int3, "");
    arbre_t *fct2= fct_type(prod_int2, base_int4, "");
    arbre_t *fct3= fct_type(prod_div, base_int4, "");
    arbre_t *fct4= fct_type(prod_int2, base_voidd, "");
    arbre_t *fct5= fct_type(prod_int1, ptr_int1, "");
    arbre_t *fct6= fct_type(prod_int2, ptr_int2, "");
    arbre_t *fct7= fct_type(prod_int1, ptr_voidd, "");
    
    


    printf("int et int (1): %d\n", compare_arbre_t(base_int1, base_int2));
    printf("int et void (0): %d\n", compare_arbre_t(base_int1, base_voidd));
    printf("ptr_int et ptr_int (1): %d\n", compare_arbre_t(ptr_int1, ptr_int2));
    printf("ptr_int et ptr_void (0): %d\n", compare_arbre_t(ptr_int1, ptr_voidd));
    printf("prod_int et prod_int (1): %d\n", compare_arbre_t(prod_int1, prod_int2));

    printf("prod4 et prod5 (1): %d\n", compare_arbre_t(prod4, prod5));
    printf("prod5 et prod6 (0): %d\n", compare_arbre_t(prod5, prod6));
    
    printf("fct1 et fct2 (1): %d\n", compare_arbre_t(fct1, fct2));
    printf("fct1 et fct3 (0): %d\n", compare_arbre_t(fct1, fct3));
    printf("fct2 et fct4 (0): %d\n", compare_arbre_t(fct2, fct4));
    printf("fct5 et fct6 (1): %d\n", compare_arbre_t(fct5, fct6));
    printf("fct6 et fct7 (0): %d\n", compare_arbre_t(fct6, fct7));


    
    /*
    int c = yyparse();
    while(c)
    {
	c=yyparse();
	}*/

    /*afficher_pile();*/
    printf("\n\n\nAccepted\n");
}

extern int yylineno;
int yyerror(char* s)
{
    printf("line %d: %s\n", yylineno, s);
  exit(1);

}
