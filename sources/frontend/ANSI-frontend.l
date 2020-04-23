D                       [0-9]
L                       [a-zA-Z_]

%option yylineno

%{
#include <stdio.h>
#include "structfe.h"
#include "structfe.tab.h"
#define TAILLE 103

pile_t *pile;
int cpt_var;
int cpt_label;
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

{L}({L}|{D})*           { yylval.symbol= ajouter(top(), yytext); return IDENTIFIER; } /*identificateurs de variable*/
{D}+                    { yylval.number= strdup(yytext); return CONSTANT; } /* constance numérique */

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

char *ajouter_code(char *code_genere, char *str){
	char *new_code = (char *)malloc(strlen(code_genere)+strlen(str));
	strcpy(new_code, strdup(code_genere));
	strcat(new_code, strdup(str));
	free(code_genere);
      	return new_code;
}

char *init_code(char *code_genere){
    code_genere = (char *) malloc(0);
    return code_genere;
}

char *concatener(char *strs, ...)
    {
	char *dest = strs;
	va_list ap;
	va_start(ap, strs);
	/*printf("init %s\n", strs);*/
	strs = va_arg(ap, char*);

	while(strs != NULL) {
	    /*printf("concat: %s", strs);*/
	    dest = ajouter_code(dest, strdup(strs));
	    /*printf("suivantttttt %s\n", strs);*/
	    strs = va_arg(ap, char*);
	    /*printf("suivant %s\n", strs);*/
	};

	/*printf("On retourne : %s \n", dest);*/

	va_end(ap);
	return dest;
    }

void init_cpt_var(){
    cpt_var = 0;
    }

char *new_var(char *var){
    var = malloc(32);
    sprintf(var, "t_%d", cpt_var);
    cpt_var++;

    return var;
}

void init_cpt_label(){
    cpt_label = 0;
    }

char *new_label(char *label){
    label = malloc(32);
    sprintf(label, "label_%d", cpt_label);
    cpt_label++;

    return label;
}


char *concatener_nulle(char *cs, ...)
{
   va_list va;
   const char *ct;
   char *s = NULL;
   size_t size = 0;

   va_start (va, cs);
/* (1) */
   while ((ct = va_arg (va, char *)) != NULL)
   {
      void *tmp = NULL;

/* (2) */
      size += strlen (ct) + strlen (cs);
      tmp = realloc (s, sizeof (*s) * (size + 1));
      if (tmp != NULL)
      {
         if (s == NULL)
         {
/* (3) */
            s = tmp;
            strcpy (s, ct);
         }
         else
         {
/* (4) */
             s = tmp;
             strcat (s, cs);
             strcat (s, ct);
         }
      }
      else
      {
         fprintf (stderr, "Memoire insuffisante\n");
         free (s);
         s = NULL;
         exit (EXIT_FAILURE);
      }
   }
   return s;
}
