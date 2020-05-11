#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define TAILLE 103

/* Structures utilisés dans le compilateur */

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
  int is_malloc;
  struct _symbole_t *suivant;
} symbole_t;

typedef struct _table_t {
  symbole_t *table[TAILLE];
  struct _table_t *suivant;
  struct _table_t *precedent;
} table_t;

typedef struct _pile_t {
  table_t *premier;
} pile_t;

typedef struct _attributs_t {
  char *code;
  char *declarations;
  arbre_t *type;
  char *res;
  symbole_t *id;
  int is_ptr_fct;
  int is_struc_member; //est ce que l'expression est du type struct->champs
  int is_externn;
} attributs_t;

/* Fonctions utilitaires */

char *concatener(char *cs, ...);

char *init_code(char *code);
char *ajouter_code(char *code, char *str);

void init_error();
int get_error_code();
void set_error_code(int n);

char *itos(int n);
