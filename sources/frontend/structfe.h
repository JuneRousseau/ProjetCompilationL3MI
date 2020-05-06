#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define TAILLE 103

int yylex();
int yyerror(char* s);

typedef enum { INT_T, VOID_T, ERROR_T, FCT_T, PTR_T, PROD_T, STRUCT_T} type_t;

typedef struct _arbre_t {
  type_t root;
  struct _arbre_t *fils_gauche;
  struct _arbre_t *fils_droit;
  char* name;
} arbre_t;

typedef struct _symbole_t {
  char *nom;
  arbre_t *type;
  int is_arg;
  struct _symbole_t *suivant;
} symbole_t;

typedef struct _attributs_t {
  char *code;
  char *declarations;
  arbre_t *type;
  char *res;
  symbole_t *id;
  int is_ptr_fct;
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


void init_cpt_var();
char *new_var(char *str);
char *add_declaration(char* var, arbre_t *type, char* declarations);

void init_cpt_label();
char *new_label(char *str);

char *concatener(char *cs, ...);

int compare_arbre_struct(arbre_t *arbre1, arbre_t *arbre2);
int compare_arbre_t(arbre_t *arbre1, arbre_t *arbre2);
int cmp_arbre_t(arbre_t *arbre1, arbre_t *arbre2, int cmp_strct);/*si cmp_strct!=0, on compare le nom des feuilles*/
int is_leaf(arbre_t *arbre);

arbre_t *basic_type(type_t t, char* name); /* creer type de base (int_t ou void_t) */
arbre_t *fct_type(arbre_t *depart, arbre_t *arrivee, char* name);
arbre_t *ptr_type(arbre_t *t, char* name);
arbre_t *prod_type(arbre_t *t1, arbre_t *t2, char* name);
arbre_t *struct_type(arbre_t *champs, char* name);

int sizeof_type(arbre_t *type);
int sizeof_type_t(arbre_t *type, int ptr);

int verif_type(arbre_t *expr_type, type_t expected_type);
void type_error(type_t expected_type, arbre_t *found_type, int line, attributs_t *attribut);
void type_error_function_arguments(arbre_t *expected_depart, arbre_t *found_depart, int line, attributs_t *attribut);
void type_error_function_definition(arbre_t *expected_arrivee, arbre_t *found_arrivee, int line, attributs_t *attribut);
void type_error_affect(arbre_t *expected_type, arbre_t *found_type, int line, attributs_t *attribut);
void type_error_relational(arbre_t *found_left_type, arbre_t *found_right_type, int line, attributs_t *attribut);
  
char* get_type_readable(type_t type);
char *draw_type_expr(arbre_t *type_expr);


void init_error();
int get_error_code();
