%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 103

int yylex();
int yyerror(char* s);
%}

%token IDENTIFIER CONSTANT SIZEOF
%token PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP
%token EXTERN
%token INT VOID
%token STRUCT 
%token IF ELSE WHILE FOR RETURN

%union {
    char* name;
    int number;
    }

%start program

%%

primary_expression
        : IDENTIFIER
        | CONSTANT
        | '(' expression ')'
        ;

postfix_expression
        : primary_expression
        | postfix_expression '(' ')'
        | postfix_expression '(' argument_expression_list ')'
        | postfix_expression '.' IDENTIFIER
        | postfix_expression PTR_OP IDENTIFIER
        ;

argument_expression_list
        : expression
        | argument_expression_list ',' expression
        ;

unary_expression
        : postfix_expression
        | unary_operator unary_expression
        | SIZEOF unary_expression
        ;

unary_operator
        : '&'
        | '*'
        | '-'
        ;

multiplicative_expression
        : unary_expression
        | multiplicative_expression '*' unary_expression
        | multiplicative_expression '/' unary_expression
        ;

additive_expression
        : multiplicative_expression
        | additive_expression '+' multiplicative_expression
        | additive_expression '-' multiplicative_expression
        ;

relational_expression
        : additive_expression
        | relational_expression '<' additive_expression
        | relational_expression '>' additive_expression
        | relational_expression LE_OP additive_expression
        | relational_expression GE_OP additive_expression
        ;

equality_expression
        : relational_expression
        | equality_expression EQ_OP relational_expression
        | equality_expression NE_OP relational_expression
        ;

logical_and_expression
        : equality_expression
        | logical_and_expression AND_OP equality_expression
        ;

logical_or_expression
        : logical_and_expression
        | logical_or_expression OR_OP logical_and_expression
        ;

expression
        : logical_or_expression
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
        : IF '(' expression ')' statement
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

/* Gestion tables des symboles */

/*mettre les declarations dans un fichier .h*/
typedef enum { INT_T, STRUCT_T } type_t;

typedef struct _symbole_t {
 char *nom;
 type_t type;
 struct _symbole_t *suivant;
 } symbole_t;

typedef struct _table_t {
    symbole_t *table[TAILLE];
    struct _table_t *suivant;
    struct _table_t *precedent;
    } table_t;

symbole_t *ajouter( table_t *table, char * nom );
symbole_t *rechercher( table_t *table, char * nom );
table_t *nouvelle_table();
void supprimer_table();
int hash(char *nom);

typedef struct _pile_t {
    table_t *premier;
    } pile_t;

pile_t *init_pile();
pile_t *push(pile_t *pile, table_t *table);
pile_t *pop(pile_t *pile);
table_t *top(pile_t *pile);


/*jusqu'ici*/




table_t *nouvelle_table(){
    table_t *p = (table_t *) malloc(sizeof(table_t));
    p->suivant = NULL;
    p->precedent = NULL;
    return p;
    }

void supprimer_table(table_t *table)
{
    free(table);
}

symbole_t *rechercher(table_t *tableSymbole, char *nom)
    {
	int h;
	symbole_t *s;
	symbole_t *precedent;
	h = hash(nom);
	s = tableSymbole->table[h];
	precedent = NULL;
	while ( s != NULL )
	{
	    if ( strcmp( s->nom, nom ) == 0 )
		return s;
	    precedent = s;
	    s = s->suivant;
	}
	return s;
    }

symbole_t *ajouter(table_t *tableSymbole, char *nom)
    {
	int h;
	symbole_t *s;
	symbole_t *precedent;
	h = hash(nom);
	s = tableSymbole->table[h];
	precedent = NULL;
	while ( s != NULL )
	{
	    if ( strcmp( s->nom, nom ) == 0 )
		return s;
	    precedent = s;
	    s = s->suivant;
	}
	if ( precedent == NULL )
	{
	    tableSymbole->table[h] = (symbole_t *) malloc(sizeof(symbole_t));
	    s = tableSymbole->table[h];
	}
	else
	    {
		precedent->suivant = (symbole_t *) malloc(sizeof(symbole_t));
		s = precedent->suivant;
	    }
    s->nom = strdup(nom);
    s->suivant = NULL;
    return s;
    }


int hash( char *nom ) {
 int i, r;
 int taille = strlen(nom);
 r = 0;
 for ( i = 0; i < taille; i++ )
 r = ((r << 8) + nom[i]) % TAILLE;
 return r;
}

pile_t *push(pile_t *pile, table_t *table)
    {
	table_t *t= top(pile);
	t->precedent= table;
	table->suivant=t;
	table->precedent=NULL;
	pile->premier= table;
	return pile;
    }

pile_t *pop(pile_t *pile)
    {
	table_t *last_top= top(pile);
	table_t *new_top = last_top->suivant;
	new_top->precedent = NULL;
	pile->premier= new_top;
	supprimer_table(last_top);
	return pile;
    }



table_t *top(pile_t *pile)
    {
	return pile->premier;
    }

pile_t *init_pile()
    {
	pile_t *pile = malloc(sizeof(pile_t));
	pile->premier= nouvelle_table();
	return pile;
    }

int main()
{
    int c = yyparse();
    while(c)
    {
	c=yyparse();
    }
  
    printf("Accepted\n");
}

extern int yylineno;
int yyerror(char* s)
{
    printf("line %d: %s\n", yylineno, s);
  exit(1);

}
