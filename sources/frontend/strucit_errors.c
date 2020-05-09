#include "strucit_errors.h"
#define SEMANTICERROR 1

/* Gestions du message d'erreur de type */ 
void type_error_custom(char* error_message, attributs_t *attribut )
{
  fprintf(stderr, "%s", error_message); //On affiche le message d'erreur
  attribut->type= basic_type(ERROR_T, ""); //Le type de l'attribut est donc un ERROR_T
  set_error_code(SEMANTICERROR); //On change le code d'erreur
}

/* Erreur de type */
void type_error(type_t expected_type, arbre_t *found_type, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur de type ligne %d ~ Type attendu: %s, Type obtenu: %s \n", line, get_type_readable(expected_type), draw_type_expr(found_type));
  if(found_type != NULL && found_type->root == ERROR_T){msg=strdup("");}
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur de type sur les arguments d'une fonction */
void type_error_function_arguments(arbre_t *expected_depart, arbre_t *found_depart, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur de type ligne %d ~ Types des arguments attendus: %s, Type des arguments obtenus: %s \n", line, draw_type_expr(expected_depart), draw_type_expr(found_depart));
  if( (expected_depart != NULL && expected_depart->root == ERROR_T) || (found_depart != NULL && found_depart->root == ERROR_T)){msg=strdup("");}
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur de type sur le retour de la fonction */
void type_error_function_definition(arbre_t *expected_arrivee, arbre_t *found_arrivee, int line, attributs_t *attribut)
{
  //char *msg= (char *)malloc(0);
  char msg[550];
  sprintf(msg, "Erreur de type ligne %d ~ Type de retour attendu: %s, Type de retour obtenu: %s \n", line, draw_type_expr(expected_arrivee), draw_type_expr(found_arrivee));
  if( (expected_arrivee != NULL && expected_arrivee->root == ERROR_T) || (found_arrivee != NULL && found_arrivee->root == ERROR_T)){sprintf(msg, "%s", strdup(""));}
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur de type sur l'affectation */
void type_error_affect(arbre_t *expected_type, arbre_t *found_type, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur de type ligne %d ~ Type attendu: %s, Type obtenu: %s \n", line, draw_type_expr(expected_type), draw_type_expr(found_type));
  if( (expected_type != NULL && expected_type->root == ERROR_T) || (found_type != NULL && found_type->root == ERROR_T)){msg=strdup("");}
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur de type sur une expression relationelle */
void type_error_relational(arbre_t *left_type, arbre_t *right_type, int line, attributs_t *attribut )
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur de type ligne %d ~ Expression relationnelle ~ Type gauche: %s, Type droit: %s \n", line, draw_type_expr(left_type), draw_type_expr(right_type));
  if( (right_type != NULL && right_type->root == ERROR_T) || (left_type != NULL && left_type->root == ERROR_T)){msg=strdup("");}
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur sur le champs de la structure */
void member_error(char *structure, char* member, int line, attributs_t *attribut)
{
  char msg[150];
  sprintf(msg, "Erreur ligne %d ~ La structure %s ne possede pas de champs %s\n", line, structure, member);
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur pointeur sur structure */
void type_error_pointer_struc(arbre_t *found_type, int line, attributs_t *attribut )
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur de type ligne %d ~ Type attendue: PTR_T( STRUCT_T ), Type obtenu: %s \n", line, draw_type_expr(found_type));
  type_error_custom(msg, attribut);
  return ;
}

/* Erreur identifiant non declare */
void identifier_unkonwn_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur ligne %d ~ l'identifiant %s n'a jamais ete declare\n", line, id);
  type_error_custom(msg, attribut);
  return;
}

/* Erreur structure non declaree */
void structure_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur ligne %d ~ la structure %s n'a jamais ete declaree\n", line, id);
  type_error_custom(msg, attribut);
  return;
}

/* Erreur structure deja declaree */
void structure_known_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur ligne %d ~ la structure %s a deja ete declaree\n", line, id);
  type_error_custom(msg, attribut);
  return;
}

void address_error(int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur ligne %d ~ on peut pas obtenir l'adresse d'une variable NULL\n", line);
  type_error_custom(msg, attribut);
  return;
}

void identifier_known_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur ligne %d ~ l'identifiant %s a deja ete declare\n", line, id);
  type_error_custom(msg, attribut);
  return;
}

void identifier_argument_error(char *id, int line, attributs_t *attribut)
  {
  char *msg= (char *)malloc(0);
  sprintf(msg, "Erreur ligne %d ~ l'identifiant %s est un parametre de fonction\n", line, id);
  type_error_custom(msg, attribut);
  return;
}
