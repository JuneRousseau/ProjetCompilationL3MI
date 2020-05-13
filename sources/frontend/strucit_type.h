#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strucit_utils.h"

int is_leaf(arbre_t *arbre);

int compare_arbre_t(arbre_t *arbre1, arbre_t *arbre2);
int cmp_arbre_t(arbre_t *arbre1, arbre_t *arbre2);
int cmp_arbre_struct(arbre_t *arbre1, arbre_t *arbre2);
int cmp_ptr_t(arbre_t *ptr1, arbre_t *ptr2);

arbre_t *basic_type(type_t t, char* name); /* creer type de base (int_t ou void_t) */
arbre_t *fct_type(arbre_t *depart, arbre_t *arrivee, char* name);
arbre_t *ptr_type(arbre_t *t, char* name);
arbre_t *prod_type(arbre_t *t1, arbre_t *t2, char* name);
arbre_t *struc_type(arbre_t *champs, char* name);

int sizeof_type(arbre_t *type);

int verif_type(arbre_t *expr_type, type_t expected_type);

char* get_type_readable(type_t type);
char *draw_type_expr(arbre_t *type_expr);
