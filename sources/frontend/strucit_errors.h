#include "strucit_symbols.h"

void type_error_custom(char* error_message, arbre_t *type );
void type_error(type_t expected_type, arbre_t *found_type, int line, attributs_t *attribut);
void type_error_function_arguments(arbre_t *expected_depart, arbre_t *found_depart, int line, attributs_t *attribut);
void type_error_function_definition(arbre_t *expected_arrivee, arbre_t *found_arrivee, int line, attributs_t *attribut);
void type_error_affect(arbre_t *expected_type, arbre_t *found_type, int line, attributs_t *attribut);
void type_error_relational(arbre_t *left_type, arbre_t *right_type, int line, attributs_t *attribut );
void member_error(char *structure, char* member, int line, attributs_t *attribut);
void type_error_pointer_struc(arbre_t *found_type, int line, attributs_t *attribut );
void identifier_unkonwn_error(char *id, int line, attributs_t *attribut);
void address_error(int line, attributs_t *attribut);
void structure_error(char *id, int line, attributs_t *attribut);
void structure_known_error(char *id, int line, attributs_t *attribut);
void identifier_known_error(char *id, int line, attributs_t *attribut);
void identifier_argument_error(char *id, int line, attributs_t *attribut);
void bad_type_parameter_error(arbre_t *found_type, int line, attributs_t *attribut);
void doubl_pointeur_error(int line, attributs_t *attribut);
void structure_declaration_error(int line, attributs_t *attribut);
void bad_definition_function_retour_error(int line, arbre_t *type);
void not_allocated_struc_error(char* id, int line);

