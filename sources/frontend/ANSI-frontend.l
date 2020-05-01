D                       [0-9]
L                       [a-zA-Z_]

%option yylineno

%{
#include <stdio.h>
#include "structfe.h"
#include "structfe.tab.h"
#include <time.h>
#define TAILLE 103
#define RANDMAX 100000000

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
    int new_size= strlen(code_genere)+strlen(str)+1;
	char *new_code = (char *)malloc(new_size);
	strcpy(new_code, code_genere);
	strcat(new_code, str);
	/*free(code_genere);*/
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
	strs = va_arg(ap, char*);

	while(strs != NULL) {
	    dest = ajouter_code(dest, strdup(strs));
	    strs = va_arg(ap, char*);
	};

	va_end(ap);
	return dest;
    }

void init_cpt_var(){
    cpt_var = 0;
    srand((unsigned) time(NULL));
    }


char *new_var(char *var){
    var = malloc(50);
    int random_part;

    do {
    random_part= rand() % RANDMAX;
    sprintf(var, "temp_%d_%d", random_part, cpt_var);
    } while(find(var) != NULL);

    cpt_var++;

    return var;
}

void init_cpt_label(){
    cpt_label = 0;
    srand((unsigned) time(NULL));
    }

char *new_label(char *label){
    label = malloc(50);
    int random_part;

    do {
    random_part= rand() % RANDMAX;
    sprintf(label, "label_%d_%d", random_part, cpt_label);
    } while(find(label) != NULL);
    
    cpt_label++;

    return label;
}


int is_leaf(arbre_t *arbre)
    {
	int g = (arbre->fils_gauche == NULL);
        int d = (arbre->fils_droit == NULL);

	return d && g;
    }


int cmp_arbre_t(arbre_t *arbre1, arbre_t *arbre2, int cmp_strct)
{
    if(arbre1 == NULL && arbre2 == NULL) {return 1;}
    else if(arbre1 == NULL || arbre2 == NULL) {return 0;}
    else
	{
	    if(arbre1->root == arbre2->root)
		{
		    if (is_leaf(arbre1) && is_leaf(arbre2))
			{
			    if(cmp_strct && !strcmp(arbre1->name, arbre2->name))
				{return 0;} /*verifier nom d'une feuille ou de tout les noeud intermediaire?*/
		return 1;
		}
		    else
			{
			    int g= cmp_arbre_t(arbre1->fils_gauche, arbre2->fils_gauche, cmp_strct);
			    if(g)
				{return cmp_arbre_t(arbre1->fils_droit, arbre2->fils_droit, cmp_strct);}
			    else {return 0;}
			}
		}
    else {
	return 0;}
    }
}

int compare_arbre_struct(arbre_t *arbre1, arbre_t *arbre2)
{return cmp_arbre_t(arbre1, arbre2, 1);}

int compare_arbre_t(arbre_t *arbre1, arbre_t *arbre2)
{return cmp_arbre_t(arbre1, arbre2, 0);}

arbre_t *basic_type(type_t t, char* name) /* creer type de base (int_t ou void_t) */
    {
	arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));

	
	if(t == INT_T || t == VOID_T || t== ERROR_T)
	    {
		arbre->root= t;
		arbre->fils_gauche= NULL;
		arbre->fils_droit= NULL;
		arbre->name= strdup(name);

		return arbre;
	    }
	else {return NULL;}
    }

arbre_t *fct_type(arbre_t *depart, arbre_t *arrivee, char* name)
    {
	arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
	arbre->root= FCT_T;
	arbre->fils_gauche= depart;
	arbre->fils_droit= arrivee;
	arbre->name= strdup(name);

	return arbre;
    }

arbre_t *ptr_type(arbre_t *t, char* name)
    {
	arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
	arbre->root= PTR_T;	
	arbre->fils_gauche= t;
	arbre->fils_droit= NULL;
	arbre->name= strdup(name);

	return arbre;
    }

arbre_t *prod_type(arbre_t *t1, arbre_t *t2, char* name)
    {
	arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
	arbre->root= PROD_T;
	arbre->fils_gauche= t1;
	arbre->fils_droit= t2;
	arbre->name= strdup(name);

	return arbre;
    }

arbre_t *struct_type(arbre_t *champs, char* name)
    {
	arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
	arbre->root= STRUCT_T;	
	arbre->fils_gauche= champs;
	arbre->fils_droit= NULL;
	arbre->name= strdup(name);

	return arbre;
    }


int verif_type(arbre_t *expr_type, type_t expected_type)
    {
	if(expr_type == NULL){return 0;}
	else
	    { return expr_type->root == expected_type; }
    }

void type_error(type_t expected_type, arbre_t *found_type, int line, attributs_t *attribut)
    {
	char *expected_type_readable= get_type_readable(expected_type);
       
	if(found_type==NULL)
	    {
		fprintf(stderr, "Type error line %d > Expected type: %s , Found_type: NULL \n", line, expected_type_readable);
	    }
	else
	    {
		fprintf(stderr, "Type error line %d > Expected type: %s , Found_type: %s \n", line, expected_type_readable, get_type_readable(found_type->root));
		}
	attribut->type= basic_type(ERROR_T, "");
	return ;
    }


char* get_type_readable(type_t type)
{
        switch(type)
	    {
	    case 0: 
	        return strdup("INT_T");
	        break;
	    case 1:
	        return strdup("VOID_T");
	        break;
	    case 2:
	        return strdup("ERROR_T");
	        break;
	    case 3:
	        return strdup("FCT_T");
	        break;
	    case 4:
	        return strdup("PTR_T");
	        break;
	    case 5:
	        return strdup("PROD_T");
	        break;
	    case 6:
	        return strdup("STRUCT_T");
	        break;
	    default:
		printf("ERREUUUUUUUUUUUUUR TYPE_ERROR\n");
		return NULL;
		break;
	    }
    }
