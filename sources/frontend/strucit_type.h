#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "strucit_utils.h"

int compare_arbre_struct(arbre_t *arbre1, arbre_t *arbre2);
int compare_arbre_t(arbre_t *arbre1, arbre_t *arbre2);
int cmp_arbre_t(arbre_t *arbre1, arbre_t *arbre2, int cmp_strct);/*si cmp_strct!=0, on compare le nom des feuilles*/
int is_leaf(arbre_t *arbre);

arbre_t *basic_type(type_t t, char* name); /* creer type de base (int_t ou void_t) */
arbre_t *fct_type(arbre_t *depart, arbre_t *arrivee, char* name);
arbre_t *ptr_type(arbre_t *t, char* name);
arbre_t *prod_type(arbre_t *t1, arbre_t *t2, char* name);
arbre_t *struc_type(arbre_t *champs, char* name);

int sizeof_type(arbre_t *type);
int get_offset_member(arbre_t *structure, char* member_name);
arbre_t *get_type_member(arbre_t *structure, char* member_name);

int verif_type(arbre_t *expr_type, type_t expected_type);
void type_error(type_t expected_type, arbre_t *found_type, int line, attributs_t *attribut);
void type_error_function_arguments(arbre_t *expected_depart, arbre_t *found_depart, int line, attributs_t *attribut);
void type_error_function_definition(arbre_t *expected_arrivee, arbre_t *found_arrivee, int line, attributs_t *attribut);
void type_error_affect(arbre_t *expected_type, arbre_t *found_type, int line, attributs_t *attribut);
void type_error_relational(arbre_t *found_left_type, arbre_t *found_right_type, int line, attributs_t *attribut);
void type_error_custom(char* error_message, attributs_t *attribut );
  
char* get_type_readable(type_t type);
char *draw_type_expr(arbre_t *type_expr);
