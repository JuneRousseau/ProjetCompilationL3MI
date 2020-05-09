#include "strucit_symbols.h"
#include <time.h>
#define RANDMAX 100000000

int cpt_label;
int cpt_var;
pile_t *pile;

void init_cpt_var(){
    cpt_var = 0;
    srand((unsigned) time(NULL));
    }

char *new_var(char *var){
    var = malloc(0);
    int random_part;

    do {
	random_part= rand() % RANDMAX;
	sprintf(var, "temp_%d_%d", cpt_var, random_part);
    } while(find(var) != NULL);
    
    cpt_var++;
    return var;
}

void init_cpt_label(){
    cpt_label = 0;
    srand((unsigned) time(NULL));
}

char *new_label(char *label)
{
    label = malloc(0);
    int random_part;

    do {
	random_part= rand() % RANDMAX;
	sprintf(label, "label_%d_%d", cpt_label, random_part);
    } while(find(label) != NULL);
    
    cpt_label++;

    return label;
}

/* Gestion tables des symboles */

symbole_t *rechercher(table_t *tableSymbole, char *nom)
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
		return s;
	    precedent = s;
	    s = s->suivant;
	}
    return s;
}

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
    return s;
}


int hash( char *nom ) {
 int i, r;
 int taille = strlen(nom);
 r = 0;
 for ( i = 0; i < taille; i++ )
 r = ((r << 8) + nom[i]) % TAILLE;
 return r;
}

table_t *nouvelle_table(){
    table_t *p = (table_t *) malloc(sizeof(table_t));
    //fprintf(stderr, "le pointeur vers la nouvelle table est %p\n", p);
    p->suivant = NULL;
    p->precedent = NULL;
    for(int i=0; i<TAILLE; i++)
	{
	    p->table[i]=NULL;
	    //fprintf(stderr, "Table[%d]: %p\n",i , p->table[i]);
	    
	}
    return p;
}

void supprimer_table(table_t *t)
{
    //fprintf(stderr, "on libere le pointeur %p\n", t);
    for(int i=0; i<TAILLE; i++)
	{
	    //fprintf(stderr, "Avant: %p\n", t->table[i]);
	    free(t->table[i]);
	    t->table[i]=NULL;
	    //fprintf(stderr, "Apres: %p\n", t->table[i]);
	    
	}
    free(t->table);
    //free(t);
    //fprintf(stderr, "on a libere le pointeur %p\n", t);
    //afficher_table(t);
}

pile_t *push(table_t *table)
    {
	table_t *t= top(pile);
	t->precedent= table;
	table->suivant=t;
	table->precedent=NULL;
	pile->premier= table;
	return pile;
    }

pile_t *pop()
    {
	table_t *last_top= top();
	table_t *new_top = last_top->suivant;
	new_top->precedent = NULL;
	pile->premier= new_top;
	supprimer_table(last_top);
	return pile;
    }


table_t *top()
    {
	return pile->premier;
    }

pile_t *init_pile()
    {
	pile = (pile_t *) malloc(sizeof(pile_t));
	pile->premier= nouvelle_table();
	return pile;
    }

symbole_t *find(char *nom)
    {
	table_t *table_courante= top(pile);
	symbole_t *symbole= NULL;
	while(table_courante != NULL && symbole == NULL){
	    symbole = rechercher(table_courante, nom);
	    table_courante = table_courante->suivant;
	    }

	return symbole;
    }
	   

void afficher_pile()
    {
	table_t *table_courante = top();
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
	{fprintf(stderr, "WTF POURQUOI C'EST NULL??"); exit(42);}
    return new_declarations;
}
