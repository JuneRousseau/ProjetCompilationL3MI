#include "strucit_errors.h"
#define SEMANTICERROR 2

/* Gestions du message d'erreur de type */ 
void type_error_custom(char* error_message, arbre_t *type )
{
  fprintf(stderr, "%s", error_message); //On affiche le message d'erreur
  type= basic_type(ERROR_T, ""); //Le type de l'attribut est donc un ERROR_T
  set_error_code(SEMANTICERROR); //On change le code d'erreur
  free(error_message);
}

/* Erreur de type */
void type_error(type_t expected_type, arbre_t *found_type, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur de type ligne ", itos(line)," ~ Type attendu: ", get_type_readable(expected_type),", Type obtenu: ", draw_type_expr(found_type), " \n", NULL);
  if(found_type != NULL && found_type->root == ERROR_T){msg=strdup("");}
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur de type sur les arguments d'une fonction */
void type_error_function_arguments(arbre_t *expected_depart, arbre_t *found_depart, int line, attributs_t *attribut)
{
  char *msg=(char *)malloc(0);
  msg= concatener(msg, "Erreur de type ligne ", itos(line), " ~ Types des arguments attendus: ", draw_type_expr(expected_depart), ", Type des arguments obtenus: ", draw_type_expr(found_depart), "\n", NULL);
  if( (expected_depart != NULL && expected_depart->root == ERROR_T) || (found_depart != NULL && found_depart->root == ERROR_T)){msg=strdup("");}
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur de type sur le retour de la fonction */
void type_error_function_definition(arbre_t *expected_arrivee, arbre_t *found_arrivee, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg= concatener(msg, "Erreur de type ligne ", itos(line), " ~ Types de retour attendu: ", draw_type_expr(expected_arrivee), ", Type de retour obtenus: ", draw_type_expr(found_arrivee), "\n", NULL);
  if( (expected_arrivee != NULL && expected_arrivee->root == ERROR_T) || (found_arrivee != NULL && found_arrivee->root == ERROR_T)){sprintf(msg, "%s", strdup(""));}
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur de type sur l'affectation */
void type_error_affect(arbre_t *expected_type, arbre_t *found_type, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur de type ligne ",itos(line)," ~ Type attendu: ",draw_type_expr(expected_type),", Type obtenu: ",draw_type_expr(found_type)," \n", NULL);
  if( (expected_type != NULL && expected_type->root == ERROR_T) || (found_type != NULL && found_type->root == ERROR_T)){msg=strdup("");}
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur de type sur une expression relationelle */
void type_error_relational(arbre_t *left_type, arbre_t *right_type, int line, attributs_t *attribut )
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur de type ligne ", itos(line)," ~ Expression relationnelle ~ Type gauche: ", draw_type_expr(left_type), ", Type droit: ", draw_type_expr(right_type)," \n", NULL);
  if( (right_type != NULL && right_type->root == ERROR_T) || (left_type != NULL && left_type->root == ERROR_T)){msg=strdup("");}
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur sur le champs de la structure */
void member_error(char *structure, char* member, int line, attributs_t *attribut)
{
  char *msg=(char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ La structure ", structure, " ne possede pas de champs ", member, "\n", NULL);
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur pointeur sur structure */
void type_error_pointer_struc(arbre_t *found_type, int line, attributs_t *attribut )
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur de type ligne ",itos(line)," ~ Type attendue: PTR_T( STRUCT_T ), Type obtenu: ",line, draw_type_expr(found_type)," \n", NULL);
  type_error_custom(msg, attribut->type);
  return ;
}

/* Erreur identifiant non declare */
void identifier_unkonwn_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ l'identifiant ", id, " n'a jamais ete declare\n", NULL);
  type_error_custom(msg, attribut->type);
  return;
}

/* Erreur structure non declaree */
void structure_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ la structure ", id, " n'a jamais ete declare\n", NULL);
  type_error_custom(msg, attribut->type);
  return;
}

/* Erreur structure deja declaree */
void structure_known_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ la structure ", id, " a deja ete declare\n", NULL);
  type_error_custom(msg, attribut->type);
  return;
}

void address_error(int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line)," ~ on peut pas obtenir l'adresse d'une variable NULL\n", line);
  type_error_custom(msg, attribut->type);
  return;
}

void identifier_known_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ l'identifiant ", id, " a deja ete declare\n", NULL);
  type_error_custom(msg, attribut->type);
  return;
}

void identifier_argument_error(char *id, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ l'identifiant ", id, " est un parametre de fonction\n", NULL);
  type_error_custom(msg, attribut->type);
  return;
}

/* Mauvaise declaration des parametres d'une fonction */
void bad_type_parameter_error(arbre_t *found_type, int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ les parametres de fonctions ne peuvent etre que des INT_T ou des PTR_T, mais pas ", draw_type_expr(found_type),"\n",NULL);
  type_error_custom(msg, attribut->type);
  return;
}

void doubl_pointeur_error(int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ Les pointeurs de pointeurs sont interdits\n",NULL);
  type_error_custom(msg, attribut->type);
  return;
}

/* Declaration d'une structure sans passer par un pointeur */
void structure_declaration_error(int line, attributs_t *attribut)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ Il est interdit de declarer une structure sans passer par un pointeur\n",NULL);
  type_error_custom(msg, attribut->type);
  return;
}


/* Declaration d'une fonction avec mauvaise valeur de retour */
void bad_definition_function_retour_error(int line, arbre_t *type)
{
  char *msg= (char *)malloc(0);
  msg=concatener(msg, "Erreur ligne ", itos(line), " ~ Le type de retour d'une fonction doit etre un type de base ou un pointeur sur structure. Type obtenu: ",draw_type_expr(type),"\n", NULL);
  type_error_custom(msg, type);
  return;
}
