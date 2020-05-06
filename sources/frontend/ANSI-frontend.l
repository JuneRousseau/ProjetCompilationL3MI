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
#define SEMANTICERROR 2
#define SYNTAXERROR 1

pile_t *pile;
int cpt_var;
int cpt_label;
int error;
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

{L}({L}|{D})*           { yylval.name=strdup(yytext); return IDENTIFIER; } /*identificateurs de variable*/
{D}+                    { yylval.number= strdup(yytext); return CONSTANT; } /* constance numérique */

"/*"([^*]|(\*+[^*/]))*\*+\/    ; /* Commentaires */
"//"([^\n\r]*)[\n\r]

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
    return p;
    }

void supprimer_table(table_t *t)
{
    //fprintf(stderr, "on libere le pointeur %p\n", t);
    for(int i=0; i<TAILLE; i++)
	{
	    free(t->table[i]);
	    t->table[i]=NULL;
	}
    free(t->table);
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
	//free(last_top);
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
		    fprintf(stderr, "%d: ", i);
		    while(s != NULL)
			{
			    fprintf(stderr, "(%s, %s, %d) -> ", s->nom, draw_type_expr(s->type), s->is_arg);
			    s= s->suivant;
			}
		    fprintf(stderr, "NULL\n");
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
	sprintf(var, "temp_%d_%d", cpt_var, random_part);
    } while(find(var) != NULL);
    
    cpt_var++;
    return var;
}

char *add_declaration(char* var, arbre_t *type, char* declarations)
{
    char *new_declarations;
    new_declarations= strdup(declarations);
    if(type != NULL)
	{
	    if(type->root == INT_T)
		{new_declarations=concatener(new_declarations, "int ", var, ";\n", NULL);}
	    else if(type->root == PTR_T)
		{
		    if(verif_type(type->fils_gauche, INT_T))
			{new_declarations=concatener(new_declarations, "int *", var, ";\n", NULL);}
		    else
			{new_declarations=concatener(new_declarations, "void *", var, ";\n", NULL);}
		}
	}
    else
	{fprintf(stderr, "WTF POURQUOI C'EST NULL??"); exit(42);}
    return new_declarations;
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
	sprintf(label, "label_%d_%d", cpt_label, random_part);
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
				{
				    return 0;
				} /*verifier nom d'une feuille ou de tout les noeud intermediaire?*/
			    return 1;
			}
		    else
			{
			    if(arbre1->root == PTR_T)
				{
				    arbre_t *fils1= arbre1->fils_gauche;
				    arbre_t *fils2= arbre2->fils_gauche;
			    
				    if( fils1 != NULL && fils2 != NULL)
					{ if(fils1->root == VOID_T || fils2->root == VOID_T) {return 1;}} /* si un des pointeurs est un void *, alors c'est bon*/
				}
				
			    int g= cmp_arbre_t(arbre1->fils_gauche, arbre2->fils_gauche, cmp_strct);
			    if(g)
				{return cmp_arbre_t(arbre1->fils_droit, arbre2->fils_droit, cmp_strct);}
			    else {return 0;}
			}
			
			}
	    else {return 0;}
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
		if(found_type->root != ERROR_T){fprintf(stderr, "Type error line %d > Expected type: %s , Found_type: %s \n", line, expected_type_readable, draw_type_expr(found_type));}
	    }
	attribut->type= basic_type(ERROR_T, "");
	error=SEMANTICERROR;
	return ;
    }

    void type_error_function_arguments(arbre_t *expected_depart, arbre_t *found_depart, int line, attributs_t *attribut)
    {
	if(expected_depart==NULL)
	    {fprintf(stderr, "Type error line %d > Expected arguments type: NULL, Found arguments type: %s \n", line, draw_type_expr(found_depart)); }
	else if (found_depart == NULL)
	    {fprintf(stderr, "Type error line %d > Expected arguments type: %s, Found arguments type: NULL \n", line, draw_type_expr(expected_depart)); }
	else
	    {
		if(found_depart->root != ERROR_T)
		    {
			fprintf(stderr, "Type error line %d > Expected arguments type: %s, Found arguments type: %s \n", line, draw_type_expr(expected_depart), draw_type_expr(found_depart));
		    }
	    }
	attribut->type= basic_type(ERROR_T, "");
	error=SEMANTICERROR;
	return ;
    }

    void type_error_affect(arbre_t *expected_type, arbre_t *found_type, int line, attributs_t *attribut)
    {
	if(expected_type==NULL)
	    {fprintf(stderr, "Type error line %d > Expected type: NULL, Found type: %s \n", line, draw_type_expr(found_type)); }
	else if (found_type == NULL)
	    {fprintf(stderr, "Type error line %d > Expected type: %s, Found type: NULL \n", line, draw_type_expr(expected_type)); }
	else
	    {fprintf(stderr, "Type error line %d > Expected type: %s, Found type: %s \n", line, draw_type_expr(expected_type), draw_type_expr(found_type) ); }
	attribut->type= basic_type(ERROR_T, "");
	error=SEMANTICERROR;
	return ;
    }
	
    void type_error_relational(arbre_t *found_left_type, arbre_t *found_right_type, int line, attributs_t *attribut)
    {
	fprintf(stderr, "Type error line %d Relationnal expression > left type: %s, right type: %s \n", line, draw_type_expr(found_left_type), draw_type_expr(found_right_type) );
	attribut->type= basic_type(ERROR_T, "");
	error=SEMANTICERROR;
	return;
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


    char *draw_type_expr(arbre_t *type_expr)
    {

	if(type_expr== NULL){return strdup("NULL");}
	else
	    {
		char *s;
		s= init_code(s);
		type_t root= type_expr->root;
		switch(root)
		    {
		    case 0: //INT_T
			return strdup("INT_T");
			break;
		    case 1: //VOID_T
			return strdup("VOID_T");
			break;
		    case 2: //ERROR_T
			return strdup("ERROR_T");
			break;
		    case 3: //FCT_T		    
			return concatener(s, strdup("("), draw_type_expr(type_expr->fils_gauche), strdup(") -> "), draw_type_expr(type_expr->fils_droit), NULL);
			break;
		    case 4: //PTR_T
			return concatener(s, strdup("PTR("), draw_type_expr(type_expr->fils_gauche), strdup(")"), NULL);
			break;
		    case 5://PROD_T
			return concatener(s, draw_type_expr(type_expr->fils_gauche), strdup(" x "), draw_type_expr(type_expr->fils_droit), NULL);
			break;
		    case 6://STRUCT_T
			return strdup("STRUCT_T");
			break;
		    default:
			return NULL;
			break;
		    }
	    }
    }

int sizeof_type(arbre_t *type)
    {
	return sizeof_type_t(type, 0);
    }

int sizeof_type_t(arbre_t *type, int ptr)
    {
	if (type == NULL) {return 0;}
	else
	    {
		switch(type->root)
		    {
		    case 0: //INT_T
			return sizeof(int);
			break;
		    case 1: //VOID_T
			return sizeof(void);
			break;
		    case 2: //ERROR_T
			return sizeof(void);
			break;
		    case 3: //FCT_T		    
			return sizeof(int);
			break;
		    case 4: //PTR_T
			if (ptr)
			    {
				int *p;
				return sizeof(p);
			    }
			else
			    {
				return (sizeof_type_t(type->fils_gauche, 1));
			    }
			break;
		    case 5://PROD_T
			return (sizeof_type_t(type->fils_gauche, ptr) + sizeof_type_t(type->fils_droit, ptr));
			break;
		    case 6://STRUCT_T
			return sizeof_type_t(type->fils_gauche, ptr);
			break;
		    default:
			return 0;
			break;
		    }
	    }
    }

    void init_error() {error=0;}
    int get_error_code() {return error;}
