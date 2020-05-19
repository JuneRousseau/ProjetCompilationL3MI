#include "strucit_symbols.h"
#include <time.h>
#define RANDMAX 100000000

int cpt_label;
int cpt_var;
pile_t *pile_id;
pile_t *pile_type;

/* Fonction de generation de nom pour les labels et les variables temporaires */
char *generate_name(char* var, char* name, int *cpt)
{
  int random_part;
  var = malloc(0);

  do {
    random_part= rand() % RANDMAX;
    //sprintf(var, "%s_%d_%d", name, *cpt, random_part);
    sprintf(var, "_%s%d", name, *cpt);
  } while(find(pile_id, var) != NULL);

  *cpt= *cpt+1;
   
  return var;
}

void init_cpt_var()
{
  cpt_var = 0;
  srand((unsigned) time(NULL));
}

char *new_var(char *var){
  return generate_name(var, "t", &(cpt_var));
}

void init_cpt_label(){
  cpt_label = 0;
  srand((unsigned) time(NULL));
}

char *new_label(char *label)
{
  return generate_name(label, "label", &(cpt_label));
}


/* Gestion tables des symboles */


/* Fonction de hashage pour la table des symboles */
int hash( char *nom ) {
  int i, r;
  int taille = strlen(nom);
  r = 0;
  for ( i = 0; i < taille; i++ )
    r = ((r << 8) + nom[i]) % TAILLE;
  return r;
}

/* Creation d'une table des symboles */
table_t *nouvelle_table(){
  table_t *p = (table_t *) malloc(sizeof(table_t));
  p->suivant = NULL;
  p->precedent = NULL;
  for(int i=0; i<TAILLE; i++)
    {
      p->table[i]=NULL;
	    
    }
  return p;
}

/* Suppression d'un table des symboles (avec free) */
void supprimer_table(table_t *t)
{
  for(int i=0; i<TAILLE; i++)
    {
      free(t->table[i]);
      t->table[i]=NULL;
    }
  free(t->table);
}

/* Ajout d'un symbole par son nom dans la table donnée */
symbole_t *ajouter(table_t *tableSymbole, char *nom)
{
  int h;
  symbole_t *s;
  symbole_t *precedent;
  h = hash(nom);
  s = tableSymbole->table[h];
  precedent = NULL;
  while ( s != NULL )
    {
      if ( strcmp( s->nom, nom ) == 0 )
	return s; /* Si l'identifiant existe déjà, on retourne NULL */
      precedent = s;
      s = s->suivant;
    }
  if ( precedent == NULL )
    {
      tableSymbole->table[h] = (symbole_t *) malloc(sizeof(symbole_t));
      s = tableSymbole->table[h];
    }
  else
    {
      precedent->suivant = (symbole_t *) malloc(sizeof(symbole_t));
      s = precedent->suivant;
    }
  s->nom = strdup(nom);
  s->suivant = NULL;
  s->type= NULL;
  s->is_arg=0;
  return s;
}

/* Initialise la pile */
void init_piles()
{
  pile_id = (pile_t *) malloc(sizeof(pile_t));
  pile_id->premier= nouvelle_table();

  pile_type = (pile_t *) malloc(sizeof(pile_t));
  pile_type->premier= nouvelle_table();
}

/* Retourne la table sur le top de la pile */
table_t *top(pile_t *pile)
{
  return pile->premier;
}

/* Ajout de la table donnée sur la pile */
pile_t *push(pile_t *pile, table_t *table)
{
  table_t *t= top(pile);
  t->precedent= table;
  table->suivant=t;
  table->precedent=NULL;
  pile->premier= table;
  return pile;
}

/* Suppression de la table présente sur le top de la pile */
pile_t *pop(pile_t *pile)
{
  table_t *last_top= top(pile);
  table_t *new_top = last_top->suivant;
  new_top->precedent = NULL;
  pile->premier= new_top;
  supprimer_table(last_top);
  return pile;
}

/* Recherche d'un symbole par son nom dans la table donnée */
symbole_t *rechercher(table_t *tableSymbole, char *nom)
{
  symbole_t *s;
  s = tableSymbole->table[hash(nom)];
  while ( s != NULL )
    {
      if ( strcmp( s->nom, nom ) == 0 )
	return s;
      s = s->suivant;
    }
  return s;
}


/* Recherche d'un symbole dans l'ensemble de la pile */
symbole_t *find(pile_t *pile, char *nom)
{
  table_t *table_courante= top(pile);
  symbole_t *symbole= NULL;
  while(table_courante != NULL && symbole == NULL){
    symbole = rechercher(table_courante, nom);
    table_courante = table_courante->suivant;
  }

  return symbole;
}

/* Ajoute aux déclarations courantes la déclaration d'une nouvelle variable du type donné (qui ne peut être que int ou void*) */
/* Attention, le type passé en paramètre ne DOIT pas être NULL */
char *add_declaration(char* var, arbre_t *type, char* declarations)
{
    char *new_declarations;
    new_declarations= strdup(declarations);
    if(type != NULL)
	{
	    if(type->root == INT_T)
		{new_declarations=concatener(new_declarations, "int ", var, ";\n", NULL);}
	    else
		{
		    {new_declarations=concatener(new_declarations, "void *", var, ";\n", NULL);}
		}
	}
    else
	{fprintf(stderr, "Erreur de type: ca ne peut pas être NULL"); exit(42);}
    return new_declarations;
}

/* Fonction de debug pour afficher la pile et les tables de symboles */
void afficher_pile(pile_t *pile)
    {
	table_t *table_courante = pile->premier;
	int i=0;
	while(table_courante)
	    {
		fprintf(stderr, "---- Table %i : ----\n", i);
		afficher_table(table_courante);
		table_courante= table_courante->suivant;
		i++;
		printf("\n\n");
	    }
    }

void afficher_table(table_t *t)
    {
	for(int i=0; i<TAILLE ; i++)
	    {
	        symbole_t *s = t->table[i];
		if(s != NULL) {
		    fprintf(stderr, "%d (%p): ", i, s);
		    while(s != NULL)
			{
			    fprintf(stderr, "(%s, %s, %d) -> ", s->nom, draw_type_expr(s->type), s->is_arg);
			    s= s->suivant;
			}
		    fprintf(stderr, "NULL\n");
		    }
	    }
	fprintf(stderr, "\n");
    }


pile_t *get_pile_id() {return pile_id;}
pile_t *get_pile_type() {return pile_type;}


/* Retourne le decalage du pointeur pour le champs recherche */
int get_offset_member(arbre_t *structure, char* member_name)
{
  if(!(verif_type(structure, STRUCT_T))){return -2;} 
  
  int size_of_struc=sizeof_type(structure);
  int offset= size_of_struc;
  arbre_t *prod_member= structure->fils_gauche;
  
  //if (prod_member == NULL) {return -1;}
  if (prod_member == NULL) {
    arbre_t *new_structure= find(get_pile_type(), structure->name)->type;
    prod_member= new_structure->fils_gauche;}
  if (!(verif_type(prod_member, PROD_T))) {if((!strcmp(prod_member->name, member_name))) {return 0;} else {return -1;}}
  while(prod_member && strcmp(prod_member->fils_droit->name, member_name) )
    {
      offset-= sizeof_type(prod_member->fils_droit);
      prod_member=prod_member->fils_gauche;
if (!(verif_type(prod_member, PROD_T))) {if((!strcmp(prod_member->name, member_name))) {return 0;} else {return -1;}}
      //if(!verif_type(prod_member, PROD_T)) {break;}
    }
  
  if(prod_member == NULL){return -1;} //on a pas trouvé le champs demandé
  else
    {
      if(verif_type(prod_member, PROD_T)) {offset-= sizeof_type(prod_member->fils_droit);}
      else {offset-= sizeof_type(prod_member);}
      return offset;
    }
}


/* Retourne le type du champs recherché */
arbre_t *get_type_member(arbre_t *structure, char* member_name)
{
  if(!(verif_type(structure, STRUCT_T))){return basic_type(ERROR_T, "");}

  arbre_t *prod_member= structure->fils_gauche; //soit c'est une produit cartesien, soit c'est un directement un champs
  if (prod_member == NULL) {
    arbre_t *new_structure= find(get_pile_type(), structure->name)->type;
    prod_member= new_structure->fils_gauche;}
    //return basic_type(ERROR_T, "");} //la structure n'a pas de champs (etrange)
  if (!(verif_type(prod_member, PROD_T))){if(!(strcmp(prod_member->name, member_name))) {return prod_member;} else {return basic_type(ERROR_T, "");}} //la structure n'a qu'un champs, donc on retourne son type si les noms correspondent
  
  while(prod_member && strcmp(prod_member->fils_droit->name, member_name) ) //tant que la structure possède encore des champs et que les noms du champs ne correspond pas a celui recherché
    {
      prod_member=prod_member->fils_gauche;
      if(!verif_type(prod_member, PROD_T)) {break;}
    }
  if(prod_member == NULL){return basic_type(ERROR_T, "");} //on a pas trouvé le champs demandé
  if(verif_type(prod_member, PROD_T)){ prod_member=prod_member->fils_droit;} //le champs n'est pas le dernier, il se trouve dans le fils droit du produit cartésien
  return prod_member;
}
