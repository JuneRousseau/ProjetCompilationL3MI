#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 103

int yylex();
int yyerror(char* s);

typedef enum { INT_T, STRUCT_T, VOID_T, PTR_INT_T, PTR_STRUCT_T, PTR_FCT_T, PTR_VOID_T, FCT_T } type_t;

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

symbole_t *ajouter( table_t *table, char *nom);
symbole_t *rechercher( table_t *table, char *nom );
table_t *nouvelle_table();
void supprimer_table();
int hash(char *nom);

typedef struct _pile_t {
    table_t *premier;
    } pile_t;

pile_t *init_pile();
pile_t *push(table_t *table);
pile_t *pop();
table_t *top();
symbole_t *find( char *nom);

void afficher_pile();
void afficher_table();

typedef struct _attributs{
	type_t type;
	char *code;
}attributs_t;

char *init_code();
char *ajouter_code(char *code, char *str);

char *new_var();
