D                       [0-9]
L                       [a-zA-Z_]

%option yylineno

%{
#include <stdio.h>
#include "structfe.h"
#include "structfe.tab.h"
#define TAILLE 103

pile_t *pile;
%}

%%
"else"                  { return ELSE; }
"extern"                { return EXTERN; }
"for"                   { return FOR; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"sizeof"                { return SIZEOF; }
"struct"                { return STRUCT; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

{L}({L}|{D})*           { yylval.symbol= ajouter(top(pile), yytext); return IDENTIFIER; } /*identificateurs de variable*/
{D}+                    { yylval.number= atoi(yytext); return CONSTANT; } /* constance numérique */

"/*"([^*]|(\*+[^*/]))*\*+\/    ; /* Commentaires */

"->"                    { return PTR_OP; }
"&&"                    { return AND_OP; }
"||"                    { return OR_OP; }
"<="                    { return LE_OP; }
">="                    { return GE_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NE_OP; }


[\n\t\r\v\f ]           ;

.                       { return yytext[0]; }

%%

/* Gestion tables des symboles */

table_t *nouvelle_table(){
    table_t *p = (table_t *) malloc(sizeof(table_t));
    p->suivant = NULL;
    p->precedent = NULL;
    return p;
    }

void supprimer_table(table_t *table)
{
    free(table);
}

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
	table_t *last_top= top(pile);
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
		printf("---- Table %i : ----\n", i);
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
		    printf("%d: ", i);
		    while(s != NULL)
			{
			    printf("%s -> ", s->nom);
			    s= s->suivant;
			}
		    printf("NULL\n");
		    }
	    }
    }
