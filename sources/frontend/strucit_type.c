#include "strucit_type.h"
#define SEMANTICERROR 2
#define SYNTAXERROR 1

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
			    if(arbre1->root == STRUCT_T)
				{
				    arbre_t *fils1= arbre1->fils_gauche;
				    arbre_t *fils2= arbre2->fils_gauche;
			    
				    if( fils1 == NULL || fils2 == NULL)
					{
					    return !strcmp(arbre1->name, arbre2->name);
					}
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
    if(verif_type(depart, ERROR_T) || verif_type(depart, ERROR_T))
	{
	    return basic_type(ERROR_T, strdup(name));
	}
    arbre->root= FCT_T;
    arbre->fils_gauche= depart;
    arbre->fils_droit= arrivee;
    arbre->name= strdup(name);

    return arbre;
}

arbre_t *ptr_type(arbre_t *t, char* name)
{
    arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
    if(verif_type(t, ERROR_T))
	{
	    return basic_type(ERROR_T, strdup(name));
	}
    arbre->root= PTR_T;	
    arbre->fils_gauche= t;
    arbre->fils_droit= NULL;
    arbre->name= strdup(name);

    return arbre;
}

arbre_t *prod_type(arbre_t *t1, arbre_t *t2, char* name)
{
    arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
    if(verif_type(t1, ERROR_T) || verif_type(t2, ERROR_T))
	{
	    return basic_type(ERROR_T, strdup(name));
	}
    arbre->root= PROD_T;
    arbre->fils_gauche= t1;
    arbre->fils_droit= t2;
    arbre->name= strdup(name);

    return arbre;
}

arbre_t *struc_type(arbre_t *champs, char* name)
{
    arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
    if(verif_type(champs, ERROR_T) )
	{
	    return basic_type(ERROR_T, strdup(name));
	}
    arbre->root= STRUCT_T;	
    arbre->fils_gauche= champs;
    arbre->fils_droit= NULL;
    arbre->name= strdup(name);

    return arbre;
}

/* il est requis que l'argument structure soit un arbre_t dont root est STRUCT_T*/
int get_offset_member(arbre_t *structure, char* member_name)
{
    int size_of_struc=sizeof_type(structure);
    int offset= size_of_struc;
    arbre_t *prod_member= structure->fils_gauche;
    if (prod_member == NULL) {return -1;}
    if (!(verif_type(prod_member, PROD_T))) {if(!(strcmp(prod_member->name, member_name))) {return 0;} else {return -1;}}
    //fprintf(stderr, "prod_member_type: %s\n", get_type_readable(prod_member->root));
    while(prod_member && strcmp(prod_member->fils_droit->name, member_name) )
	{
	    //fprintf(stderr, "offset pour %s: %d\n",member_name,  offset);
	    offset-= sizeof_type(prod_member->fils_droit);
	    prod_member=prod_member->fils_gauche;
	    if(!verif_type(prod_member, PROD_T)) {break;}
	}
    if(prod_member == NULL){return -1;} //on a pas trouvé le champs demandé
    else {
	if(verif_type(prod_member, PROD_T)) {offset-= sizeof_type(prod_member->fils_droit);}
	else {offset-= sizeof_type(prod_member);}
	//fprintf(stderr, "offset pour %s: %d\n",member_name,  offset);
	return offset;}
}


/* il est requis que l'argument structure soit un arbre_t dont root est STRUCT_T*/
arbre_t *get_type_member(arbre_t *structure, char* member_name)
{
    arbre_t *prod_member= structure->fils_gauche;
    if (prod_member == NULL) {return basic_type(ERROR_T, "");}
    if (!(verif_type(prod_member, PROD_T)))
	{	
	    // fprintf(stderr, "LE TYPE RETROUVE POUR %s EST (solo) : %s\n", member_name, draw_type_expr(prod_member));
	    return prod_member;
	}
    while(prod_member && strcmp(prod_member->fils_droit->name, member_name) )
	{
	    //	    fprintf(stderr, "LE TYPE STRUCTURE POUR %s (..........) : %s ........... %s\n", member_name, draw_type_expr(prod_member), draw_type_expr(prod_member->fils_droit));
	    prod_member=prod_member->fils_gauche;
	    if(!verif_type(prod_member, PROD_T)) {break;}
	}
    if(prod_member == NULL){return basic_type(ERROR_T, "");} //on a pas trouvé le champs demandé
    
    if(verif_type(prod_member, PROD_T)){ prod_member=prod_member->fils_droit; }
    //fprintf(stderr, "LE TYPE RETROUVE POUR %s EST : %s\n", member_name, draw_type_expr(prod_member));
    return prod_member;
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
    set_error_code(SEMANTICERROR);
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
    set_error_code(SEMANTICERROR);
    return ;
}

void type_error_function_definition(arbre_t *expected_arrivee, arbre_t *found_arrivee, int line, attributs_t *attribut)
{
    if(expected_arrivee==NULL)
	{fprintf(stderr, "Type error line %d > Expected return type: NULL, Found return type: %s \n", line, draw_type_expr(found_arrivee)); }
    else if (found_arrivee == NULL)
	{fprintf(stderr, "Type error line %d > Expected return type: %s, Found return type: NULL \n", line, draw_type_expr(expected_arrivee)); }
    else
	{
	    if(found_arrivee->root != ERROR_T)
		{
		    fprintf(stderr, "Type error line %d > Expected return type: %s, Found return type: %s \n", line, draw_type_expr(expected_arrivee), draw_type_expr(found_arrivee));
		}
	}
    attribut->type= basic_type(ERROR_T, "");
    set_error_code(SEMANTICERROR);
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
    set_error_code(SEMANTICERROR);
    return ;
}
	
void type_error_relational(arbre_t *found_left_type, arbre_t *found_right_type, int line, attributs_t *attribut )
{
    fprintf(stderr, "Type error line %d Relationnal expression > left type: %s, right type: %s \n", line, draw_type_expr(found_left_type), draw_type_expr(found_right_type) );
    attribut->type= basic_type(ERROR_T, "");
    set_error_code(SEMANTICERROR);
    return;
}

void type_error_custom(char* error_message, attributs_t *attribut )
{
    fprintf(stderr, "%s", error_message);
    attribut->type= basic_type(ERROR_T, "");
    set_error_code(SEMANTICERROR);
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
		    return concatener(s, strdup("[INT_T : "), type_expr->name, strdup("]"), NULL);
		    break;
		case 1: //VOID_T
		    return concatener(s, strdup("[VOID_T : "), type_expr->name, strdup("]"), NULL);
		    break;
		case 2: //ERROR_T
		    return concatener(s, strdup("[ERROR_T : "), type_expr->name, strdup("]"), NULL);
		    break;
		case 3: //FCT_T		    
		    return concatener(s, strdup("[("), draw_type_expr(type_expr->fils_gauche), strdup(") -> ("), draw_type_expr(type_expr->fils_droit), strdup(") : "), type_expr->name, strdup("]"), NULL);
		    break;
		case 4: //PTR_T
		    return concatener(s, strdup("[PTR("), draw_type_expr(type_expr->fils_gauche), strdup(")"), strdup(" : "), type_expr->name, strdup("]"),  NULL);
		    break;
		case 5://PROD_T
		    return concatener(s, draw_type_expr(type_expr->fils_gauche), strdup(" . "), draw_type_expr(type_expr->fils_droit), NULL);
		    break;
		case 6://STRUCT_T
		    return concatener(s, strdup("[STRUCT_T ("), draw_type_expr(type_expr->fils_gauche), strdup(")"), strdup(" : "), type_expr->name, strdup("]"), NULL);
		    break;
		default:
		    return strdup("");
		    break;
		}
	}
}


int sizeof_type(arbre_t *type)
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
		    return 0;
		    break;
		case 3: //FCT_T		    
		    return sizeof(int);
		    break;
		case 4: //PTR_T
		    return sizeof(int*);	    
		    break;
		case 5://PROD_T
		    return (sizeof_type(type->fils_gauche) + sizeof_type(type->fils_droit));
		    break;
		case 6://STRUCT_T
		    return sizeof_type(type->fils_gauche);
		    break;
		default:
		    return 0;
		    break;
		}
	}
}
