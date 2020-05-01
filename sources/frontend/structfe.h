#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define TAILLE 103

int yylex();
int yyerror(char* s);

/*typedef enum { INT_T, STRUCT_T, VOID_T, PTR_INT_T, PTR_STRUCT_T, PTR_FCT_T, PTR_VOID_T, FCT_T } type_t;*/

typedef enum { INT_T, VOID_T, ERROR_T, FCT_T, PTR_T, PROD_T, STRUCT_T} type_t;

typedef struct _arbre_t {
  type_t root;
  struct _arbre_t *fils_gauche;
  struct _arbre_t *fils_droit;
  char* name;
} arbre_t;

typedef struct _symbole_t {
 char *nom;
 type_t type;
 struct _symbole_t *suivant;
 } symbole_t;

typedef struct _attributs_t {
  char *code;
  type_t type;
  char *res;
} attributs_t;

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

char *init_code(char *code);
char *ajouter_code(char *code, char *str);
char *concatener_nulle(char *strs, ...);


void init_cpt_var();
char *new_var(char *str);

void init_cpt_label();
char *new_label(char *str);

char *concatener(char *cs, ...);

int compare_arbre_struct(arbre_t *arbre1, arbre_t *arbre2); /*si cmp_strct!=0, on compare le nom des feuilles*/
int compare_arbre_t(arbre_t *arbre1, arbre_t *arbre2);
int cmp_arbre_t(arbre_t *arbre1, arbre_t *arbre2, int cmp_strct);/*si cmp_strct!=0, on compare le nom des feuilles*/
int is_leaf(arbre_t *arbre);

arbre_t *basic_type(type_t t, char* name); /* creer type de base (int_t ou void_t) */
arbre_t *fct_type(arbre_t *depart, arbre_t *arrivee, char* name);
arbre_t *ptr_type(arbre_t *t, char* name);
arbre_t *prod_type(arbre_t *t1, arbre_t *t2, char* name);
arbre_t *struct_type(arbre_t *champs, char* name);

