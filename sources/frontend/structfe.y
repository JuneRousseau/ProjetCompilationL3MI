%{
#include "structfe.h"
#define SEMANTICERROR 2
#define SYNTAXERROR 1

extern int yylineno;
int cpt;
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

%type <attributs> primary_expression postfix_expression argument_expression_list unary_expression unary_operator multiplicative_expression additive_expression relational_expression equality_expression logical_and_expression logical_or_expression expression declaration declaration_specifiers type_specifier struct_specifier struct_declaration_list struct_declaration declarator direct_declarator parameter_list parameter_declaration statement compound_statement  declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement program external_declaration function_definition

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
    $$.declarations= strdup($2.declarations);
    $$.type= $2.type;
}

| CONSTANT
{
    $$.code = init_code($$.code);
    $$.res = strdup($1);
    $$.declarations=strdup("");

    $$.type= basic_type(INT_T, "");
}


| IDENTIFIER
{
    $$.code = init_code($$.code);
    $$.res = strdup($1->nom);
    
    $$.type = $1->type;
    $$.declarations=strdup("");
} ;

postfix_expression
: primary_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.declarations= strdup($1.declarations);

    $$.type= $1.type;
}


| postfix_expression '(' ')'
{
/* on vérifie que le type de postfix_expression est une fonction qui prend void en entrée*/
    if(verif_type($1.type, FCT_T)) /*on a bien une fonction*/
	{
	    arbre_t *depart= $1.type->fils_gauche;
	    if (verif_type(depart, VOID_T)) /*l'espace de départ est bien VOID_T*/ /* VOID OU NULL??*/
		{$$.type = $1.type->fils_droit;}
	    else
		{type_error_function_arguments(basic_type(VOID_T, ""), depart, yylineno, &$$);}
	}
    else
	{type_error(FCT_T, $1.type, yylineno, &$$);}

    $$.code = strdup($1.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "()", ";\n", NULL);
    $$.declarations= add_declaration($$.res, $$.type, $1.declarations);
}



| postfix_expression '(' argument_expression_list ')'
{

    /* on vérifie que le type de postfix_expression est une fonction qui prend le bon type en entrée*/
    if(verif_type($1.type, FCT_T)) /*on a bien une fonction*/
	{
	    arbre_t *depart= $1.type->fils_gauche;
	    if (compare_arbre_t(depart, $3.type)) /*l'espace de départ est bien du bon type*/
		{$$.type = $1.type->fils_droit;}
	    else
		{type_error(VOID_T, depart, yylineno, &$$);}
	}
    else
	{ type_error(FCT_T, $1.type, yylineno, &$$);}

    $$.code = strdup($1.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res,"(", $3.res, ")", ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}



| postfix_expression PTR_OP IDENTIFIER /* ATTENTION, les structures n'existent pas dans le backend, il faudra modifier cet routine sémantique */
{
    $$.code = strdup($1.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "->", strdup($3->nom), ";\n", NULL);
    $$.type= basic_type(VOID_T, ""); /*type du champs de structure....*/
    $$.declarations=strdup("");
}
;


argument_expression_list
: expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
}

| argument_expression_list ',' expression
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res = init_code($$.res);
    $$.res = concatener($$.res, $1.res, ",", $3.res, NULL);
    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);

    $$.type= prod_type($1.type, $3.type, ""); /*c'est un arbre "recursif a gauche"*/
}
;



unary_expression
: postfix_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type= $1.type;
    $$.declarations= strdup($1.declarations);
}


| unary_operator unary_expression
{
    if(!(strcmp($1.code, "-")))
	{
	    if(verif_type($2.type, INT_T)) {$$.type = basic_type(INT_T, "");}
	    else {type_error(INT_T, $2.type, yylineno, &$$);}
	}

    else if(!(strcmp($1.code, "&")))
	{
	    if($2.type == NULL) {fprintf(stderr, "Type error line %d > Expected type: not NULL , Found_type: NULL \n", yylineno); $$.type=basic_type(ERROR_T, ""); }
	    else{$$.type = ptr_type($2.type, ""); }
	}

    else
	{
	    if(verif_type($2.type, PTR_T)) {$$.type= $2.type->fils_gauche;}
	    else {type_error(PTR_T, $2.type, yylineno, &$$);}
	}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res)); /* stockage du resultat*/
    $$.code = concatener($$.code, $2.code, $$.res, " = ", $1.code, $2.res,";\n", NULL);
    $$.declarations= add_declaration($$.res, $$.type, $2.declarations);
}


| SIZEOF '(' type_specifier ')'
{
    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $$.res, " = sizeof(", $3.code , ");\n", NULL);
    $$.type= basic_type(INT_T, "");
    $$.declarations= add_declaration($$.res, $$.type, strdup(""));
}

| SIZEOF unary_expression
{
    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $$.res, " = sizeof(",$2.res , ");\n", NULL);
    $$.type= basic_type(INT_T, "");
    $$.declarations= add_declaration($$.res, $$.type, $2.declarations);
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
    $$.declarations= strdup($1.declarations);
}


| multiplicative_expression '*' unary_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "*", $3.res, ";\n", NULL);
    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);

}


| multiplicative_expression '/' unary_expression
{

    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "/", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}
;


additive_expression
: multiplicative_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
}


| additive_expression '+' multiplicative_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type = basic_type(INT_T, "");}
	    else if (verif_type($3.type, PTR_T)) {$$.type= $3.type;}
	    else {type_error(INT_T, $3.type, yylineno, &$$); /*int_t ou ptr_t*/}
	} 
    else if (verif_type($1.type, PTR_T))
	{
	    if (verif_type($3.type, INT_T)) {$$.type= $1.type;}
	    else {type_error(INT_T, $3.type, yylineno, &$$); /*int_t */}
	}
    else {type_error(INT_T, $3.type, yylineno, &$$); /*int_t ou ptr_t*/}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "+", $3.res, ";\n",  NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}


| additive_expression '-' multiplicative_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type = basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	} 
    else if (verif_type($1.type, PTR_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type = $1.type;}
	    else if (verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$); /*int_t ou ptr_t*/}
	}
    else {type_error(INT_T, $3.type, yylineno, &$$); /*int_t ou ptr_t*/}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "-", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}
;

relational_expression
: additive_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
}

| relational_expression '<' additive_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}

| relational_expression '>' additive_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}


    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}

| relational_expression LE_OP additive_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "<=", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}

| relational_expression GE_OP additive_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, ">=", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}
;

equality_expression
: relational_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
}

| equality_expression EQ_OP relational_expression
{
    //$$.res = init_code($$.res);
    //$$.res = concatener($$.res, $$.res, " = ", $1.res, "==", $3.res);

    if(compare_arbre_t($1.type, $3.type)) {$$.type= basic_type(INT_T, "");}
    else { type_error_relational($1.type, $3.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "==", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}

| equality_expression NE_OP relational_expression
{
    if(compare_arbre_t($1.type, $3.type)) {$$.type= basic_type(INT_T, "");}
    else { type_error_relational($1.type, $3.type, yylineno, &$$); }

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "!=", $3.res, ";\n",  NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}
;

logical_and_expression
: equality_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
}

| logical_and_expression AND_OP equality_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    char* label_suite;
    char* label_falsee;
    char* label_truee;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));

    $$.code = concatener($$.code, $1.code, "if (", $1.res, ") goto ", label_suite,";\n", NULL);
    $$.code = concatener($$.code, "goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code,"\n",  label_suite, ":\n", NULL);
    $$.code = concatener($$.code, $3.code, "if (", $3.res, ") goto ", label_truee,";\n", NULL);
    $$.code = concatener($$.code,"goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code,"\n",  label_truee,":\n", $$.res, "= 1;\n", NULL);
    $$.code = concatener($$.code,"\n", label_falsee,":\n", $$.res, "= 0;\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}
;

logical_or_expression
: logical_and_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
}

| logical_or_expression OR_OP logical_and_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $1.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    char* label_suite;
    char* label_falsee;
    char* label_truee;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
 
    $$.code = concatener($$.code,"", $1.code, "if (", $1.res, ") goto ", label_truee,";\n", NULL);
    $$.code = concatener($$.code,"", "goto ", label_suite, ";\n", NULL);
    $$.code = concatener($$.code,"", label_suite, ":\n", NULL);
    $$.code = concatener($$.code,"", $3.code, "if (", $3.res, ") goto ", label_truee,";\n", NULL);
    $$.code = concatener($$.code,"", "goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code,"", label_truee,":\n", $$.res, "= 1;\n", NULL);
    $$.code = concatener($$.code,"", label_falsee,":\n", $$.res, "= 0;\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
}
;

expression
: logical_or_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type= $1.type;
    $$.declarations= strdup($1.declarations);
}

| unary_expression '=' expression
{
    if(compare_arbre_t($1.type, $3.type)) {
	$$.type= $1.type;}
    else {type_error_affect($1.type, $3.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup($1.res);
    $$.code = concatener($$.code, $1.code, $3.code, $1.res, " = ", $3.res, ";\n", NULL);
    $$.declarations= strdup($3.declarations);
}
;

declaration
: declaration_specifiers declarator ';'
{
    $$.code=init_code($$.code);
    $$.code=concatener($$.code, $1.code, " ", $2.code, ";\n", NULL);
    $$.type= $2.type;
    fprintf(stderr, "%d: DECLARATION: %s %s\n\n", cpt++, draw_type_expr($$.type), $2.id->nom);
    $$.declarations=strdup("");
}

| struct_specifier ';'
{
    $$.code= strdup("not yet implemented: struct specifier");
    $$.type= basic_type(VOID_T, ""); /*type structure*/
    $$.declarations=strdup("");
}
;


declaration_specifiers
: EXTERN type_specifier
{
    $$.code=init_code($$.code);
    $$.code= concatener($$.code, "extern ", $2.code, NULL);
    $$.type = $2.type;
$$.declarations=strdup("");
}

| type_specifier
{
    $$.code= strdup($1.code);
    $$.type= $1.type;
    $$.declarations=strdup("");
}
;


type_specifier
: VOID
{
    $$.code= strdup("void");
    $$.type= basic_type(VOID_T, "");
$$.declarations=strdup("");
}

| INT
{
    $$.code= strdup("int");
    $$.type= basic_type(INT_T, "");
$$.declarations=strdup("");
}

| struct_specifier
{
    $$.code= strdup("not yet implemented: struct_specifier");
    $$.type= basic_type(VOID_T, ""); /* type structure*/
$$.declarations=strdup("");
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
: '*' {$<attributs>$.type= ptr_type($<attributs>0.type, ""); fprintf(stderr, "* %s\n", draw_type_expr($<attributs>$.type));} direct_declarator
//: '*' {$<attributs>$.type= $<attributs>0.type; fprintf(stderr, "%d: * %s\n", cpt++, draw_type_expr($<attributs>$.type));} direct_declarator 
{
    $$.code= init_code($$.code);
    $$.code= concatener($$.code, "*", $3.code, NULL);
    //$$.type= ptr_type($3.type, "");
    $$.id = $3.id;
    $$.id->type= $3.type;
$$.type= $$.id->type;
    fprintf(stderr, "type de l'id??? %s\n", (draw_type_expr($$.id->type)));
    fprintf(stderr, "%d: ****%s %s\n",cpt++, ($$.id->nom), draw_type_expr($$.type));
    $$.declarations=strdup("");
}

| {$<attributs>$.type= $<attributs>0.type;} direct_declarator
{
    $$.code= strdup($2.code);
    $$.type= $2.type;
    $$.id = $2.id;
    fprintf(stderr, "%d: %s %s\n",cpt++, ($$.id->nom), draw_type_expr($$.type));
    $$.declarations=strdup("");
}
;

direct_declarator
:  '(' {$<attributs>$.type= $<attributs>0.type; fprintf(stderr, "%d: (dans decla)  %s\n", cpt++, draw_type_expr($<attributs>$.type));} declarator ')'
{
    $$.code = init_code($$.code); $$.code = concatener($$.code, "(", $3.code, ")", NULL);
    $$.type= $<attributs>0.type;
    $$.type= $3.type;
    //$$.type=basic_type(VOID_T, "");
    $$.id= $3.id;
    fprintf(stderr, "%d: (decla)  %s\n", cpt++, draw_type_expr($$.type));
$$.declarations=strdup("");
}

| IDENTIFIER
{
    $$.code = strdup($1->nom);
    $1->type= $<attributs>0.type;
    $$.type= $1->type;
    $$.id= $1;
    fprintf(stderr, "%d: IDENT:%s %s\n",cpt++, $1->nom,  draw_type_expr($$.type));
$$.declarations=strdup("");
}


|  direct_declarator '(' parameter_list ')'
{
    $$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "(",$3.code,")", NULL);
    //if($1.type != NULL) {fprintf(stderr, "TYPE DE DIRECT DECLA: %s\n", get_type_readable( ($1.type)->root) );}
    $$.type= fct_type($3.type, $1.type, "");
    ($1.id)->type= $$.type;
    fprintf(stderr, "%d: direct(...) %s\n", cpt++, draw_type_expr($$.type));
$$.declarations=strdup("");
}	      

| direct_declarator '(' ')'
{
    $$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "()", NULL);
    $$.type= fct_type(basic_type(VOID_T, ""), $1.type, "");
    ($1.id)->type= $$.type;
    //fprintf(stderr, "%s\n", draw_type_expr($$.type));
    $$.declarations=strdup("");
}
;

parameter_list
: parameter_declaration
{
    $$.code = strdup($1.code);
    $$.type = $1.type;
$$.declarations=strdup("");
}

| parameter_list ',' parameter_declaration
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, "," , $3.code, NULL);
    $$.type= prod_type($1.type, $3.type, ""); /*c'est un arbre "recursif a gauche"*/
    $$.declarations=strdup("");
}
;

parameter_declaration
: declaration_specifiers declarator
{
    $$.code=init_code($$.code); $$.code=concatener($$.code, $1.code, " ", $2.code," ", NULL);
    $$.type= $1.type;
    $$.declarations=strdup("");
}
;

statement
: compound_statement
{
$$.code = strdup($1.code);
$$.type= $1.type;
$$.declarations= strdup($1.declarations);
}

| expression_statement
{
$$.code = strdup($1.code);
$$.type= $1.type;
$$.declarations= strdup($1.declarations);
}

| selection_statement
{
$$.code = strdup($1.code);
$$.type= $1.type;
$$.declarations= strdup($1.declarations);
}

| iteration_statement
{
$$.code = strdup($1.code);
$$.type= $1.type;
$$.declarations= strdup($1.declarations);
}

| jump_statement
{
$$.code = strdup($1.code);
$$.type= $1.type;
$$.declarations= strdup($1.declarations);
}
;

compound_statement
: '{' '}'
{
    $$.code = init_code($$.code); $$.code= ajouter_code($$.code, "{ }\n");
    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup("\n");
}


| '{' statement_list '}'
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, "{\n", $2.declarations, $2.code ,"}\n", NULL);
    $$.type = $2.type;
    $$.declarations= strdup("\n");
//    $$.declarations= strdup($2.declarations);
}


| '{' declaration_list '}'
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, "{\n", $2.code ,"}\n", NULL);
    $$.type = $2.type;
    $$.declarations= strdup("\n");
}


| '{' declaration_list statement_list '}'
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, "{\n", $3.declarations,  $2.code, $3.code ,"}\n", NULL);
    $$.type = $3.type;
    $$.declarations= strdup("\n");
    //$$.declarations= strdup($3.declarations);
    //fprintf(stderr, "DECLAAAAA [ %s ]\n", $3.declarations);
}
;

declaration_list
: declaration
{
    $$.code= strdup($1.code); /*verifier qu'on a pas une erreur de type*/
    $$.type= $1.type;
    $$.declarations=strdup("");
}

| declaration_list declaration
{
    $$.code= init_code($$.code);
    $$.code= concatener($$.code, $1.code, $2.code, NULL);
    $$.type= $2.type;
    $$.declarations=strdup("");
}
;

statement_list
: statement
{
    $$.code=strdup($1.code);
    $$.type=$1.type;
    $$.declarations= strdup($1.declarations);
}

| statement_list statement
{
    $$.code=init_code($$.code);
    $$.code=concatener($$.code, $1.code, $2.code, NULL);
    $$.type= $2.type;
    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $2.declarations, NULL);
}
;

expression_statement
: ';'
{
    $$.code = init_code($$.code);
    $$.code=ajouter_code($$.code, ";\n"); $$.res= NULL;
    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup("\n");
}

| expression ';'
{
    $$.code= strdup($1.code);
    $$.res= strdup($1.res);
    $$.type= $1.type;
    $$.declarations= strdup($1.declarations);
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
    $$.code= concatener($$.code, "if (", $3.res, ") goto ", label_truee, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code, label_truee, ":\n", $5.code, label_falsee, ":\n", NULL);
    $$.res = NULL;

    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup($3.declarations);
}

| IF '(' expression ')' statement ELSE statement
{
    char* label_falsee;
    char* label_truee;
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    $$.code= init_code($$.code);
    $$.code= concatener($$.code, $3.code,"\n", NULL);
    $$.code= concatener($$.code, "if (", $3.res, ") goto ", label_truee, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code, label_truee, ":\n", $5.code, NULL);
    $$.code = concatener($$.code, label_falsee, ":\n", $7.code,  NULL);
    $$.res= NULL;

    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup($3.declarations);
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
    $$.code= concatener($$.code, "if (", $3.res , ") goto ", label_loop, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_end, ";\n", NULL);
    $$.code= concatener($$.code, label_loop, ":\n", $5.code, "\n", $3.code, "\n", NULL);
    $$.code= concatener($$.code, "if (", $3.res , ") goto ", label_loop, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,":\n", NULL);
    $$.res= NULL;
    $$.declarations=init_code($$.declarations);
    $$.declarations=concatener($$.declarations, $3.declarations, $5.declarations);

    $$.type= basic_type(VOID_T, "");
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
    $$.code= concatener($$.code, "if (", $4.res , ") goto ", label_loop, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_end, ";\n", NULL);
    $$.code= concatener($$.code, label_loop, ":\n", $7.code, "\n", $5.code, "\n", $4.code, NULL);
    $$.code= concatener($$.code, "if (", $4.res , ") goto ", label_loop, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,":\n", NULL);
    $$.res= NULL;
    
    $$.declarations=init_code($$.declarations);
    $$.declarations=concatener($$.declarations, $3.declarations, $4.declarations, $5.declarations, $7.declarations);
fprintf(stderr, "declarations du corps du for: %s", $7.declarations);

    $$.type= basic_type(VOID_T, "");
}
;

jump_statement
: RETURN ';'
{
    $$.code= init_code($$.code);
    $$.code= ajouter_code($$.code, "return ;\n");
    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup("\n");
}

| RETURN expression ';'
{
    $$.code= strdup($2.code);
    $$.code= concatener($$.code, "return ", $2.res," ;\n", NULL);
    $$.type= $2.type;
    $$.declarations= strdup($2.declarations);
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
    $$.type = $1.type;
}
| declaration
{
    $$.code = strdup($1.code);
    $$.type = $1.type;
}
;

function_definition
: declaration_specifiers declarator compound_statement
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, " " ,$2.code, $3.code, NULL);
    $$.type = $2.type;
}
;

%%
	 
int main()
{
    cpt=0;
    init_pile();
    init_cpt_var();
    init_cpt_label();
    init_error();
    int c = yyparse();
    
    while(c)
	{
	    c=yyparse();
	}

    /*afficher_pile();*/
    exit(get_error_code());
    
}

int yyerror(char* s)
{
    fprintf(stderr, "line %d: %s\n", yylineno, s);
    exit(SYNTAXERROR);
}
