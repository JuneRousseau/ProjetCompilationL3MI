%{
#include "structfe.h"

%}

%token <attributs> SIZEOF CONSTANT
%token <attributs> PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token <attributs> AND_OP OR_OP
%token <attributs> EXTERN
%token <attributs> INT VOID
%token <attributs> STRUCT 
%token <attributs> IF ELSE WHILE FOR RETURN
%token <attributs> '(' ')' '{' '}' ';' '&' '*' '-' ',' '.' '+' '>' '<' '='
%token <symbol> IDENTIFIER

%type <attributs> primary_expression postfix_expression argument_expression_list unary_expression unary_operator multiplicative_expression additive_expression  relational_expression equality_expression logical_and_expression logical_or_expression expression declaration declaration_specifiers type_specifier  struct_specifier struct_declaration_list struct_declaration declarator direct_declarator parameter_list parameter_declaration statement compound_statement  declaration_list statement_list expression_statement selection_statement iteration_statement jump_statement program external_declaration function_definition

%nonassoc "then"
%nonassoc ELSE



%union {
    char* name;
    int number;
    symbole_t *symbol;
    attributs_t attributs;
    }

%start program

%%

primary_expression
        : IDENTIFIER {symbole_t *s = rechercher(top(), $1->nom); $$.type = s->type; $$.code = strdup($1->nom);}
        | CONSTANT {$$.type = INT_T;}
        | '(' expression ')'{$$.type = $1.type;}
        ;

postfix_expression
        : primary_expression {$$.type = $1.type;}
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')'
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER 
        ;

argument_expression_list
        : expression {$$.type = $1.type;}
        | argument_expression_list ',' expression
        ;

unary_expression
        : postfix_expression {$$.type = $1.type;}
        | unary_operator unary_expression {$$.type = $2.type;}
        | SIZEOF unary_expression {$$.type = INT_T;}
        ;

unary_operator
        : '&'
        | '*'
        | '-'
        ;

multiplicative_expression
        : unary_expression {$$.type = $1.type;}
        | multiplicative_expression '*' unary_expression
        | multiplicative_expression '/' unary_expression
        ;

additive_expression
        : multiplicative_expression {$$.type = $1.type;}
        | additive_expression '+' multiplicative_expression
        | additive_expression '-' multiplicative_expression
        ;

relational_expression
        : additive_expression {$$.type = INT_T;} /* verifier types*/
        | relational_expression '<' additive_expression {$$.type = INT_T;}
        | relational_expression '>' additive_expression {$$.type = INT_T;}
        | relational_expression LE_OP additive_expression {$$.type = INT_T;}
        | relational_expression GE_OP additive_expression {$$.type = INT_T;}
        ;

equality_expression
        : relational_expression {$$.type = INT_T;}
        | equality_expression EQ_OP relational_expression {$$.type = INT_T;}
        | equality_expression NE_OP relational_expression {$$.type = INT_T;}
        ;

logical_and_expression
        : equality_expression  {$$.type = INT_T;}
        | logical_and_expression AND_OP equality_expression {$$.type = INT_T;}
        ;

logical_or_expression
        : logical_and_expression {$$.type = INT_T;}
        | logical_or_expression OR_OP logical_and_expression {$$.type = INT_T;}
        ;

expression
        : logical_or_expression {$$.type = INT_T;}
        | unary_expression '=' expression
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
: IDENTIFIER
        | '(' declarator ')'
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

    char *code;
    code = init_code(code);
    code= ajouter_code(code, "test");
    printf("000: %s\n", code);
    code = ajouter_code(code, "test 2");
    printf("001: %s\n", code);
    
    init_pile();
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
