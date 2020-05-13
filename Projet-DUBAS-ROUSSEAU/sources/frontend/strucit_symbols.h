#include "strucit_type.h"

char *generate_name(char* var, char* name, int *cpt);

void init_cpt_var();
char *new_var(char *str);

void init_cpt_label();
char *new_label(char *str);

int hash(char *nom);
table_t *nouvelle_table();
void supprimer_table();
symbole_t *ajouter( table_t *table, char *nom);

void init_piles();
table_t *top(pile_t *pile);
pile_t *push(pile_t *pile, table_t *table);
pile_t *pop(pile_t *pile);

symbole_t *rechercher( table_t *table, char *nom );
symbole_t *find(pile_t *pile, char *nom);

char *add_declaration(char* var, arbre_t *type, char* declarations);

void afficher_pile();
void afficher_pile_t(pile_t *pile);
void afficher_pile_type();
void afficher_table();

pile_t *get_pile_id();
pile_t *get_pile_type();

int get_offset_member(arbre_t *structure, char* member_name);
arbre_t *get_type_member(arbre_t *structure, char* member_name);
