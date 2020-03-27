#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 103

int yylex();
int yyerror(char* s);

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
