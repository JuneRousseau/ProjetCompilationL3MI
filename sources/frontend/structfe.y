%{
#include "structfe.h"
#define SEMANTICERROR 2
#define SYNTAXERROR 1

    extern int yylineno;
    arbre_t *type_retour;
    %}

%token <attributs> SIZEOF
%token <attributs> PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token <attributs> AND_OP OR_OP
%token <attributs> EXTERN
%token <attributs> INT VOID
%token <attributs> STRUCT 
%token <attributs> IF ELSE WHILE FOR RETURN
%token <attributs> '(' ')' '{' '}' ';' '&' '*' '-' ',' '.' '+' '>' '<' '='
%token <name> IDENTIFIER
%token <number> CONSTANT

%type <attributs> primary_expression postfix_expression argument_expression_list unary_expression unary_operator multiplicative_expression additive_expression relational_expression equality_expression logical_and_expression logical_or_expression expression declaration declaration_specifiers type_specifier struct_specifier struct_declaration_list struct_declaration declarator direct_declarator parameter_list parameter_declaration statement compound_statement  declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement program external_declaration function_definition

%nonassoc "then"
%nonassoc ELSE


%union {
    char *number;
    attributs_t attributs;
    char *name;
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
    $$.is_struc_member= $2.is_struc_member;
    $$.id= $2.id;
}

| CONSTANT
{
    $$.code = init_code($$.code);
    $$.res = strdup($1);
    $$.declarations=strdup("");

    $$.type= basic_type(INT_T, "");
    $$.is_struc_member= 0;
    $$.id=NULL;
}


| IDENTIFIER
{
    $$.code = init_code($$.code);
    $$.res = strdup($1);
    symbole_t *s=find(get_pile_id(),$1);
    if(s)
	{$$.type=s->type;}
    else
	{
	    identifier_unkonwn_error($1, yylineno, &$$);
	}
	
    $$.declarations=strdup("");
    $$.is_struc_member= 0;
    $$.id= s;
} ;

postfix_expression
: primary_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.declarations= strdup($1.declarations);

    $$.type= $1.type;
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}


| postfix_expression '(' ')'
{
    /* on vérifie que le type de postfix_expression est une fonction qui prend void en entrée*/

    if($1.type!= NULL && (verif_type($1.type, FCT_T) || (verif_type($1.type, PTR_T) && verif_type($1.type->fils_gauche, FCT_T)) )) /*on a bien une fonction ou pointeur sur fonction*/
	{
	    arbre_t *type_fct= verif_type($1.type, PTR_T) ? $1.type->fils_gauche : $1.type;
	    arbre_t *depart= type_fct->fils_gauche;
	    if (verif_type(depart, VOID_T)) /*l'espace de départ est bien VOID_T*/ /* VOID OU NULL??*/
		{$$.type = type_fct->fils_droit;}
	    else
		{type_error_function_arguments(depart, basic_type(VOID_T, ""), yylineno, &$$);}
	}
    else
	{type_error(FCT_T, $1.type, yylineno, &$$);}

    $$.code = strdup($1.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $$.res, " = ", $1.res, "()", ";\n", NULL);
    $$.declarations= add_declaration($$.res, $$.type, $1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}



| postfix_expression '(' argument_expression_list ')'
{

    /* on vérifie que le type de postfix_expression est une fonction qui prend le bon type en entrée*/
    if($1.type!= NULL && (verif_type($1.type, FCT_T) || (verif_type($1.type, PTR_T) && verif_type($1.type->fils_gauche, FCT_T)) )) /*on a bien une fonction ou pointeur sur fonction*/
	{
	    arbre_t *type_fct= verif_type($1.type, PTR_T) ? $1.type->fils_gauche : $1.type;
	    arbre_t *depart= type_fct->fils_gauche;
	    if (compare_arbre_t(depart, $3.type)) /*l'espace de départ est bien du bon type*/
		{$$.type = type_fct->fils_droit;}
	    else
		{type_error_function_arguments(depart, $3.type, yylineno, &$$);}
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
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}



| postfix_expression PTR_OP IDENTIFIER
{
    int offset;
    if(verif_type($1.type, PTR_T))
	{
	    if(verif_type($1.type->fils_gauche, STRUCT_T)) {offset= get_offset_member($1.type->fils_gauche, $3);}
	    else{offset= -2;}
	}
    else {offset= -2;}
   
    if(offset < 0) /*il y a une erreur*/
	{
	    char* error_msg= malloc(0);
	    if (offset == -1)
		{
		    member_error(strdup($1.type->fils_gauche->name), strdup($3), yylineno, &$$);
		}
	    else {type_error_pointer_struc( $1.type, yylineno, &$$);}
	}
    else
	{
	    arbre_t *type= get_type_member($1.type->fils_gauche, $3);
	    $$.type= type;
	}
    $$.code = strdup($1.code);
    $$.res = strdup(new_var($$.res));
    char* offset_c;
    offset_c= malloc(0);
    sprintf(offset_c, "%d", offset);
    $$.code = concatener($$.code, $1.code, $$.res, " = ",$1.res, "+", offset_c, ";\n", NULL);
    $$.declarations= add_declaration($$.res, ptr_type(basic_type(VOID_T,""),""), $1.declarations);
    $$.is_struc_member= 1;
    $$.id= $1.id;
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
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
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
	    if($2.type == NULL) {address_error(yylineno, &$$);}
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
    $$.is_struc_member= $2.is_struc_member;
    $$.id= $2.id;
}


| SIZEOF '(' type_specifier ')'
{
    $$.code = init_code($$.code);
    $$.res=init_code($$.res);
    sprintf($$.res, "%d", sizeof_type($3.type));
    $$.type= basic_type(INT_T, "");
    $$.declarations = strdup("");
    $$.is_struc_member= 0;
    $$.id= NULL;
}

| SIZEOF unary_expression
{
    $$.code = init_code($$.code);
    $$.res=init_code($$.res);
    sprintf($$.res, "%d", sizeof_type($2.type));
    $$.type= basic_type(INT_T, "");
    $$.declarations = strdup("");
    $$.is_struc_member= 0;
    $$.id= NULL;
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
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}


| multiplicative_expression '*' unary_expression
{
    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "*", $3.res, ";\n", NULL);
    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
    $$.is_struc_member= 0;
    $$.id= NULL;
}


| multiplicative_expression '/' unary_expression
{

    if(verif_type($1.type, INT_T))
	{
	    if(verif_type($3.type, INT_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.res = strdup(new_var($$.res));
    $$.code = concatener($$.code, $1.code, $3.code, $$.res, " = ", $1.res, "/", $3.res, ";\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
$$.is_struc_member= 0;
}
;


additive_expression
: multiplicative_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
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
$$.is_struc_member= 0;
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
    $$.is_struc_member= 0;
}
;

relational_expression
: additive_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}

| relational_expression '<' additive_expression
{
    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T))
	{
	    if(verif_type($3.type, INT_T)  || verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res= init_code($$.res);
    $$.res= concatener($$.res, $1.res, "<", $3.res, NULL);

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);
$$.is_struc_member= 0;
}

| relational_expression '>' additive_expression
{
    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T))
	{
	    if(verif_type($3.type, INT_T)  || verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}


    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res= init_code($$.res);
    $$.res= concatener($$.res, $1.res, ">", $3.res, NULL);

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);
$$.is_struc_member= 0;
}

| relational_expression LE_OP additive_expression
{
    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T))
	{
	    if(verif_type($3.type, INT_T)  || verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res= init_code($$.res);
    $$.res= concatener($$.res, $1.res, "<=", $3.res, NULL);

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);
$$.is_struc_member= 0;
}

| relational_expression GE_OP additive_expression
{
    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T))
	{
	    if(verif_type($3.type, INT_T) || verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
	    else {type_error(INT_T, $3.type, yylineno, &$$);}
	}
    else {type_error(INT_T, $1.type, yylineno, &$$);}

    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res= init_code($$.res);
    $$.res= concatener($$.res, $1.res, ">=", $3.res, NULL);

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);
$$.is_struc_member= 0;
}
;

equality_expression
: relational_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}

| equality_expression EQ_OP relational_expression
{
    if(compare_arbre_t($1.type, $3.type)) {$$.type= basic_type(INT_T, "");}
    else
	{
	    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T))
		{
		    if(verif_type($3.type, INT_T)  || verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
		    else {type_error_relational($1.type, $3.type, yylineno, &$$);}
		}
	    else {type_error_relational($1.type, $3.type, yylineno, &$$);}
	}

    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res= init_code($$.res);
    $$.res= concatener($$.res, $1.res, "==", $3.res, NULL);

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);
    $$.is_struc_member= 0;
}

| equality_expression NE_OP relational_expression
{
    if(compare_arbre_t($1.type, $3.type)) {$$.type= basic_type(INT_T, "");}
    else
	{
	    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T))
		{
		    if(verif_type($3.type, INT_T)  || verif_type($3.type, PTR_T)) {$$.type= basic_type(INT_T, "");}
		    else {type_error_relational($1.type, $3.type, yylineno, &$$);}
		}
	    else {type_error_relational($1.type, $3.type, yylineno, &$$);}
	}

    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $3.code, NULL);
    $$.res= init_code($$.res);
    $$.res= concatener($$.res, $1.res, "!=", $3.res, NULL);

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);
$$.is_struc_member= 0;
}
;

logical_and_expression
: equality_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
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
    char* label_end;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    label_end= strdup(new_label(label_end));

    $$.code = concatener($$.code, $1.code, "if (", $1.res, ") goto ", label_suite,";\n", NULL);
    $$.code = concatener($$.code, "goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code,"\n",  label_suite, ":\n", NULL);
    $$.code = concatener($$.code, $3.code, "if (", $3.res, ") goto ", label_truee,";\n", NULL);
    $$.code = concatener($$.code,"goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code,"\n",  label_truee,":\n", $$.res, "= 1;\n", NULL);
    $$.code = concatener($$.code,"goto ", label_end, ";\n", NULL);
    $$.code = concatener($$.code,"\n", label_falsee,":\n", $$.res, "= 0;\n", NULL);
    $$.code = concatener($$.code,"\n",  label_end,": ;\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
$$.is_struc_member= 0;
}
;

logical_or_expression
: logical_and_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type = $1.type;
    $$.declarations= strdup($1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
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
    char* label_end;
    label_suite= strdup(new_label(label_suite));
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    label_end= strdup(new_label(label_end));
 
    $$.code = concatener($$.code,"", $1.code, "if (", $1.res, ") goto ", label_truee,";\n", NULL);
    $$.code = concatener($$.code,"", "goto ", label_suite, ";\n", NULL);
    $$.code = concatener($$.code,"", label_suite, ":\n", NULL);
    $$.code = concatener($$.code,"", $3.code, "if (", $3.res, ") goto ", label_truee,";\n", NULL);
    $$.code = concatener($$.code,"", "goto ", label_falsee, ";\n", NULL);
    $$.code = concatener($$.code,"\n", label_truee,":\n", $$.res, "= 1;\n", NULL);
    $$.code = concatener($$.code,"goto ", label_end, ";\n", NULL);
    $$.code = concatener($$.code,"\n", label_falsee,":\n", $$.res, "= 0;\n", NULL);
    $$.code = concatener($$.code,"\n",  label_end,": ;\n", NULL);

    char* tmp_decla;
    tmp_decla= init_code(tmp_decla);
    tmp_decla= concatener(tmp_decla, $1.declarations, $3.declarations, NULL);
    $$.declarations= add_declaration($$.res, $$.type, tmp_decla);
$$.is_struc_member= 0;
}
;

expression
: logical_or_expression
{
    $$.code = strdup($1.code);
    $$.res = strdup($1.res);
    $$.type= $1.type;
    $$.declarations= strdup($1.declarations);
    $$.is_struc_member= $1.is_struc_member;
    $$.id= $1.id;
}

| unary_expression '=' expression
{
    if(compare_arbre_t($1.type, $3.type)){$$.type= $1.type;}
    else
	{
	    if(verif_type($1.type, PTR_T) && verif_type($3.type, INT_T)){$$.type= $1.type;}
	    else {type_error_affect($1.type, $3.type, yylineno, &$$);}
	}

    $$.code = init_code($$.code);
    $$.res = strdup($1.res);
	
    char *ptr_1=strdup("");
    char *ptr_3=strdup("");

    if($1.is_struc_member)
	{
	    ptr_1=strdup("*");
	}

    $$.declarations= init_code($$.declarations);
    $$.declarations= concatener($$.declarations, $1.declarations, $3.declarations, NULL);

    if($3.is_struc_member){

	char *tmp;
	tmp=new_var(tmp);
	ptr_3=strdup("*");

	$$.code = concatener($$.code, $1.code, $3.code, tmp, " = ", "*", $3.res, ";\n", ptr_1, $1.res, " = ", tmp, ";\n", NULL);

	$$.declarations= add_declaration(tmp, $3.type, $$.declarations);
    }

    else {
	$$.code = concatener($$.code, $1.code, $3.code, ptr_1, $1.res, " = ", ptr_3, $3.res, ";\n", NULL);}
 
    
   
}
;

declaration
: declaration_specifiers declarator ';'
{
    $$.code=init_code($$.code);

    if(verif_type($2.type, INT_T) || verif_type($2.type, VOID_T))
	{$$.code=concatener($$.code, $1.code, " ", $2.id->nom, ";\n", NULL);}
    else
	{
	    if(type_retour == NULL && verif_type($2.type, FCT_T)){$$.code=concatener($$.code, $1.code, " ", $2.code, ";\n", NULL);}
	    else{

		if(verif_type($2.type, PTR_T))
		    {
			if(verif_type($2.type->fils_gauche, FCT_T)) {$$.code=concatener($$.code, $1.code, " ", $2.code, ";\n", NULL);}//si c'est un pointeur sur fonction
			else {$$.code=concatener($$.code, "void *", $2.id->nom, ";\n", NULL);}
		    }
	    }
	}



    $$.declarations=strdup("");

    if($2.type!= NULL && (verif_type($2.type, FCT_T) || (verif_type($2.type, PTR_T) && verif_type($2.type->fils_gauche, FCT_T)) ))
	{
	    pop(get_pile_id());
	    arbre_t *type_ret;
	    if(verif_type($2.type, FCT_T)){type_ret= $2.type->fils_droit;}
	    else {type_ret= ($2.type->fils_gauche)->fils_droit;}

	    switch(type_ret->root)
		{
		case INT_T:
		case VOID_T:
		    break;
		case PTR_T:
		    //if( !verif_type(type_ret->fils_gauche, STRUCT_T) ) {bad_definition_function_retour_error(yylineno, type_ret);}
		    break;
		default:
		    bad_definition_function_retour_error(yylineno, type_ret);
		    $$.type=basic_type(ERROR_T, "");
		    break;
		}
 
	}
    if($2.type!= NULL && verif_type($2.type, PTR_T) && verif_type($2.type->fils_gauche, PTR_T)){doubl_pointeur_error(yylineno, &$<attributs>$);} /*si on a un pointeur de pointeur*/

    if(verif_type($2.type, STRUCT_T)){structure_declaration_error(yylineno, &$$);}
    else{$$.type=$2.type;}

}

| struct_specifier ';'
{
    $$.code= strdup("");
    $$.type= $1.type; /*type structure*/
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
    $$.code= strdup($1.code);
    $$.type= $1.type;
    $$.declarations=strdup("");
}
;


struct_specifier
: STRUCT IDENTIFIER '{'
{
    char *id=$<name>2;
    symbole_t *s=rechercher(top(get_pile_type()), id);
    if(s)
	{
	    structure_known_error(id, yylineno, &$<attributs>$);
	}
    else
	{ symbole_t *n= ajouter(top(get_pile_type()), strdup(id)); n->type= struc_type(NULL, id); }
    push(get_pile_id(), nouvelle_table());
} struct_declaration_list '}'
{
    pop(get_pile_id());
    symbole_t *s=rechercher(top(get_pile_type()), $2);
    if(s)
	{
	    if(verif_type(s->type, STRUCT_T))
		{
		    (s->type)= struc_type($5.type, strdup($2));
		}
	    $$.type= s->type;
	}
    else {$$.type= basic_type(ERROR_T, strdup($2));}

    $$.code=strdup("");
    $$.declarations=strdup("");
}


| STRUCT '{' {push(get_pile_id(), nouvelle_table());} struct_declaration_list '}'
{
    pop(get_pile_id());
    $$.code=strdup("");
    $$.type=struc_type($4.type, "");
    $$.declarations=strdup("");
}


| STRUCT IDENTIFIER
{
    $$.code= strdup("void");
    symbole_t *s_id= find(get_pile_type(), $2);
    if(s_id){$$.type=s_id->type;}
    else{structure_error($2, yylineno, &$$);}
}
;

struct_declaration_list
: struct_declaration
{
    $$.code = strdup("");
    $$.type = $1.type;
    $$.declarations=strdup("");
}


| struct_declaration_list struct_declaration
{
    $$.code = strdup("");
    $$.type= prod_type($1.type, $2.type, ""); /*c'est un arbre "recursif a gauche"*/
    $$.declarations=strdup("");
}
;

struct_declaration
: type_specifier declarator ';'
{
    $$.code=strdup("");
    $2.type->name= strdup($2.id->nom); //modif ici
    $$.type= $2.type;
    $$.declarations=strdup("");
    if($$.type!= NULL && (verif_type($$.type, FCT_T) || (verif_type($$.type, PTR_T) && verif_type($$.type->fils_gauche, FCT_T)) )){pop(get_pile_id());} /*on a bien une fonction ou pointeur sur fonction*/
}
;

declarator
: '*' {$<attributs>$.type= ptr_type($<attributs>0.type, "");} direct_declarator
{
    $$.code= init_code($$.code);
    $$.code= concatener($$.code, "*", $3.code, NULL);
    $$.id = $3.id;
    $$.type= $3.type;
    $$.id->type= $$.type;
    $$.declarations=strdup("");
}

| {$<attributs>$.type= $<attributs>0.type;} direct_declarator
{
    $$.code= strdup($2.code);
    $$.type= $2.type;
    $$.id = $2.id;
    $$.id->type= $$.type;
    $$.declarations=strdup("");
}
;

direct_declarator
:  '(' {$<attributs>$.type= $<attributs>0.type;} declarator ')'
{
    $$.code = init_code($$.code); $$.code = concatener($$.code, "(", $3.code, ")", NULL);
    if(verif_type($3.type, PTR_T)){ $$.type= ptr_type(fct_type(NULL, $3.type->fils_gauche, ""), "");} //si c'est un pointeur, c'est qu'on a en fait un type fonction
    else {$$.type= $3.type;}
    $$.id= $3.id;
    $$.declarations=strdup("");
}

| IDENTIFIER
{
    symbole_t *s;
    s= rechercher(top(get_pile_id()), $1);
    if(s){identifier_known_error($1, yylineno, &$$); s->type=basic_type(ERROR_T, $1);}
    else
	{
	    if(top(get_pile_id())->suivant)
		{
		    s= rechercher(top(get_pile_id())->suivant, $1);
		    if(s)
			{ if(s->is_arg)
				{
				    identifier_argument_error($1, yylineno, &$$);
				}
			    else
				{$$.type= $<attributs>0.type;
				    s= ajouter(top(get_pile_id()), $1);}

			}
		    else
			{
			    $$.type= $<attributs>0.type;
			    s= ajouter(top(get_pile_id()), $1);
			}
		    
		}
	    else
		{
		    $$.type= $<attributs>0.type;
		    s= ajouter(top(get_pile_id()), $1);
		}
	}
    $$.id=s;
    $$.id->is_arg=0;
    $$.code = strdup($1);
    $$.declarations=strdup("");
}


| direct_declarator '(' {push(get_pile_id(), nouvelle_table());}  parameter_list ')'
{
    $$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "(",$4.code,")", NULL);
    if(verif_type($1.type, PTR_T) && verif_type($1.type->fils_gauche, FCT_T)){$1.type->fils_gauche->fils_gauche= $4.type; $1.type->fils_gauche->name= $1.id->nom; $$.type= $1.type;}
    else{$$.type= fct_type($4.type, $1.type, $1.id->nom);}
    $$.id= $1.id;
    $$.declarations=strdup("");
}	      

| direct_declarator '(' {push(get_pile_id(), nouvelle_table());} ')'
{
    $$.code=init_code($$.code); $$.code= concatener($$.code, $1.code, "()", NULL);
    if(verif_type($1.type, PTR_T) && verif_type($1.type->fils_gauche, FCT_T)){$1.type->fils_gauche->fils_gauche= basic_type(VOID_T, ""); $1.type->fils_gauche->name= $1.id->nom; $$.type= $1.type;}
    else{$$.type= fct_type(basic_type(VOID_T, ""), $1.type, $1.id->nom);}
    $$.id= $1.id;
    $$.declarations=strdup("");
}
    ;

parameter_list: parameter_declaration
{
    $$.code = strdup($1.code);
    if(verif_type($1.type, INT_T) || verif_type($1.type, PTR_T)){$$.type = $1.type;}
    else { bad_type_parameter_error($1.type, yylineno, &$$);}
    $$.declarations=strdup("");
}

| parameter_list ',' parameter_declaration
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, "," , $3.code, NULL);
    if(verif_type($3.type, INT_T) || verif_type($3.type, PTR_T)){$$.type=prod_type($1.type, $3.type, "");}/*c'est un arbre "recursif a gauche"*/
    else { bad_type_parameter_error($3.type, yylineno, &$$);}
    $$.declarations=strdup("");
}
;

parameter_declaration
: declaration_specifiers declarator
{
    $$.id=$2.id;
    $2.id->is_arg=1;
    
    if($2.type!= NULL && (verif_type($2.type, PTR_T) && verif_type($2.type->fils_gauche, FCT_T)))
	{
	    pop(get_pile_id());
	    arbre_t *type_ret;
	    if(verif_type($2.type, FCT_T)){type_ret= $2.type->fils_droit;}
	    else {type_ret= ($2.type->fils_gauche)->fils_droit;}

	    switch(type_ret->root)
		{
		case INT_T:
		case VOID_T:
		    break;
		case PTR_T:
		    //if( !verif_type(type_ret->fils_gauche, STRUCT_T) ) {bad_definition_function_retour_error(yylineno, type_ret);}
		    break;
		default:
		    bad_definition_function_retour_error(yylineno, type_ret);
		    $$.type=basic_type(ERROR_T, "");
		    break;
		}
 
	}
    if($2.type!= NULL && verif_type($2.type, PTR_T) && verif_type($2.type->fils_gauche, PTR_T)){doubl_pointeur_error(yylineno, &$<attributs>$);} /*si on a un pointeur de pointeur*/
    if(verif_type($2.type, STRUCT_T)){structure_declaration_error(yylineno, &$$);}
    if(!verif_type($2.type, INT_T) && !verif_type($2.type, PTR_T)){bad_type_parameter_error($2.type, yylineno, &$$);}
    else{$$.type=$2.type;}

    $$.code=init_code($$.code);
    if(verif_type($$.type, PTR_T)){$$.code=concatener($$.code, "void *", $$.id->nom," ", NULL);}
    else{$$.code=concatener($$.code, $1.code, " ", $2.code," ", NULL);}
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

entree
: '{' {push(get_pile_id(), nouvelle_table()); push(get_pile_type(), nouvelle_table());} ;

sortie
: '}' {pop(get_pile_id()); pop(get_pile_type());} ;

compound_statement
: '{' '}'
{
    $$.code = init_code($$.code); $$.code= ajouter_code($$.code, "{ }\n");
    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup("");
}


| entree statement_list sortie
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, "{\n", $2.declarations, $2.code ,"}\n", NULL);
    $$.type = $2.type;
    $$.declarations= strdup("");
}


| entree declaration_list sortie
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, "{\n", $2.code ,"}\n", NULL);
    $$.type = $2.type;
    $$.declarations= strdup("");
}


| entree declaration_list statement_list sortie
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, "{\n", $2.code, $3.declarations, $3.code ,"}\n", NULL);
    $$.type = $3.type;
    $$.declarations= strdup("");
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
    $$.code = concatener($$.code, label_truee, ":\n", $5.code, label_falsee, ": ;\n", NULL);
    $$.res = NULL;

    if(verif_type($3.type, ERROR_T) || verif_type($5.type, ERROR_T)){$$.type= basic_type(ERROR_T, "");}
    else {$$.type= basic_type(VOID_T, "");}
    $$.declarations= strdup($3.declarations);
}

| IF '(' expression ')' statement ELSE statement
{
    char* label_falsee;
    char* label_truee;
    char* label_end;
    label_falsee= strdup(new_label(label_falsee));
    label_truee= strdup(new_label(label_truee));
    label_end= strdup(new_label(label_end));
    $$.code= init_code($$.code);
    $$.code= concatener($$.code, $3.code,"\n", NULL);
    $$.code= concatener($$.code, "if (", $3.res, ") goto ", label_truee, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_falsee, ";\n", NULL);
    $$.code= concatener($$.code, "\n",  label_truee, ":\n", $5.code, NULL);
    $$.code= concatener($$.code, "goto ", label_end, ";\n", NULL);
    $$.code= concatener($$.code, "\n", label_falsee, ":\n", $7.code,  NULL);
    $$.code= concatener($$.code, "\n", label_end, ": ;\n", NULL);
    $$.res= NULL;

    if(verif_type($3.type, ERROR_T) || verif_type($5.type, ERROR_T) || verif_type($7.type, ERROR_T)){$$.type= basic_type(ERROR_T, "");}
    else {$$.type= basic_type(VOID_T, "");}
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
    $$.code= concatener($$.code, "\n", label_loop, ":\n", $5.code, "\n", $3.code, "\n", NULL);
    $$.code= concatener($$.code, "if (", $3.res , ") goto ", label_loop, ";\n", NULL);
    $$.code= concatener($$.code, "goto ", label_end, ";\n\n",label_end,": ;\n", NULL);
    $$.res= strdup("");
    $$.declarations=init_code($$.declarations);
    $$.declarations=concatener($$.declarations, $3.declarations, $5.declarations, NULL);

    if(verif_type($3.type, ERROR_T) || verif_type($5.type, ERROR_T)){$$.type= basic_type(ERROR_T, "");}
    else {$$.type= basic_type(VOID_T, "");}
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
    $$.code= concatener($$.code, "goto ", label_end, ";\n",label_end,": ;\n", NULL);
    $$.res= NULL;
    
    $$.declarations=init_code($$.declarations);
    $$.declarations=concatener($$.declarations, $3.declarations, $4.declarations, $5.declarations, $7.declarations, NULL);

   if(verif_type($3.type, ERROR_T) || verif_type($4.type, ERROR_T) || verif_type($5.type, ERROR_T) || verif_type($7.type, ERROR_T)){$$.type= basic_type(ERROR_T, "");}
    else {$$.type= basic_type(VOID_T, "");}
}
;

/* verifier que le type de retour de la fonction courante est bien celle du return*/
jump_statement
: RETURN ';'
{
    $$.code= init_code($$.code);
    $$.code= ajouter_code($$.code, "return ;\n");
    $$.type= basic_type(VOID_T, "");
    $$.declarations= strdup("\n");
    if(!verif_type(type_retour, VOID_T)){type_error_function_definition(type_retour, basic_type(VOID_T,""), yylineno, &$$);}
}

| RETURN expression ';'
{
    $$.code= strdup($2.code);
    $$.code= concatener($$.code, "return ", $2.res," ;\n", NULL); 
    $$.declarations= strdup($2.declarations);;
    if(!compare_arbre_t(type_retour, $2.type)){type_error_function_definition(type_retour, $2.type, yylineno, &$$);}
    else{$$.type= $2.type;}

}
;

program_start
: program
{
    if(!(verif_type($1.type, ERROR_T)) && get_error_code()==0)
	{printf("%s", $1.code);}
    else{printf("%s", strdup(""));}
}

program
: external_declaration
{
    $$.code= strdup($1.code);
    $$.type= $1.type;
}

| program external_declaration
{
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, $2.code, NULL);
    $$.type= prod_type($1.type, $2.type, "");
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
: declaration_specifiers declarator
{
    type_retour= ($<attributs>2.type)->fils_droit;
    if(type_retour==NULL) {type_retour=basic_type(ERROR_T, "");}
    else
	{
	    switch(type_retour->root)
		{
		case INT_T:
		case VOID_T:
		    break;
		case PTR_T:
		    //if( !verif_type(type_retour->fils_gauche, STRUCT_T) ) {bad_definition_function_retour_error(yylineno, type_retour);}
		    break;
		default:
		    bad_definition_function_retour_error(yylineno, type_retour);
		    break;
		}
	}
} compound_statement
{
    pop(get_pile_id()); /*on pop la table des symboles des parametres*/
    $$.code = init_code($$.code);
    $$.code = concatener($$.code, $1.code, " " ,$2.code, $4.code, NULL);
    $$.type = $2.type;
    type_retour=NULL;
}
;

%%
	 
int main()
{
    init_piles();
      init_cpt_var();
      init_cpt_label();
      init_error();
      int c = yyparse();
    
      while(c)
      {
      c=yyparse();
      }

    exit(get_error_code());    
}

int yyerror(char* s)
{
    fprintf(stderr, "syntax line %d: %s\n", yylineno, s);
    exit(SYNTAXERROR);
}
