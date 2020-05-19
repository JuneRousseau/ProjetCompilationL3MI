#include "strucit_type.h"
#define SEMANTICERROR 2
#define SYNTAXERROR 1
#define MSGMAX 300

int is_leaf(arbre_t *arbre)
{
  int g = (arbre->fils_gauche == NULL);
  int d = (arbre->fils_droit == NULL);

  return (d && g);
}


int compare_arbre_t(arbre_t *arbre1, arbre_t *arbre2)
{return cmp_arbre_t(arbre1, arbre2);}

/* Compare les champs des structures passés en parametres (on passe les champs) */
int cmp_arbre_struct(arbre_t *champs1, arbre_t *champs2)
{
  //printf("\nChamps1: %s \nChamps2: %s\n", draw_type_expr(champs1), draw_type_expr(champs2));
  arbre_t *tmp_member1= champs1;
  arbre_t *tmp_member2= champs2;
  arbre_t *tmp_droit1;
  arbre_t *tmp_droit2;

  if(tmp_member1 == NULL && tmp_member2 == NULL){return 1;}
  else
    {
      if(tmp_member1 == NULL || tmp_member2 == NULL){return 0;}
      else
	{
	  while(tmp_member1 != NULL && tmp_member2 != NULL)
	    {
	      tmp_droit1= tmp_member1->fils_droit;
	      tmp_droit2= tmp_member2->fils_droit;
	      
	      if(!verif_type(tmp_member1, PROD_T) || !verif_type(tmp_member2, PROD_T) ) {break;} //si l'un des 2 n'est plus un PROD_T, on sort de la boucle
	      if(tmp_droit1 != NULL && tmp_droit2 != NULL)
		{
		  if(!cmp_arbre_t(tmp_droit1, tmp_droit2)){return 0;} //si les types des champs ne correspondent pas, on sort de la boucle, c'est faux
		  if(strcmp(tmp_droit1->name, tmp_droit2->name)) {return 0;} //si les noms des champs ne correspondent pas, on sort de la boucle, c'est faux
	        }
	      tmp_member1=tmp_member1->fils_gauche;
	      tmp_member2=tmp_member2->fils_gauche;
	    }

	  if(tmp_member1 == NULL && tmp_member2 == NULL) {return 1;}
	  else
	    {
	      if(tmp_member1 == NULL || tmp_member2 == NULL){return 0;}
	      else
		{
		  if(strcmp(tmp_member1->name, tmp_member2->name)) {return 0;} //si les noms des champs ne correspondent pas, c'est faux
		  else
		    {return cmp_arbre_t(tmp_member1, tmp_member2);}
		}
	    }
	}

    }
}

/* Compare les arbres des expressions de types */
int cmp_arbre_t(arbre_t *arbre1, arbre_t *arbre2)
{
  //printf("\nArbre1: %s \nArbre2: %s\n", draw_type_expr(arbre1), draw_type_expr(arbre2));
  if(arbre1 == NULL && arbre2 == NULL){return 1;} // les 2 sont NULL, c'est vrai
  else
    {
      if(arbre1 == NULL || arbre2 == NULL) {return 0;} // l'un des 2 uniquement est NULL, c'est faux
      else
	{
	  type_t root1=arbre1->root;
	  type_t root2=arbre2->root;
      
	  if(root1 == root2) //les racines sont les memes
	    {
	      if(arbre1->root == PTR_T) //si ce sont des pointeurs on doit verifier si il y a un void*
		{
		  if(cmp_ptr_t(arbre1, arbre2)){return 1;} /* si un des pointeurs est un void *, alors c'est bon*/
		}

	      if(arbre1->root == STRUCT_T) //si ce sont des structures
		{
		  arbre_t *fils1= arbre1->fils_gauche;
		  arbre_t *fils2= arbre2->fils_gauche;
		  if(!(strcmp(arbre1->name, arbre2->name))) // si les noms des structures correspondent
		    {
		      if(fils1 == NULL || fils2 == NULL){return 1;} //si l'un des 2 a des champs NULL, c'est que c'est un type récursif, on vérifie que les noms correspondent
		      else {return cmp_arbre_struct(fils1, fils2);} //sinon on compare les champs
		    }
		}
	      
	      int g= cmp_arbre_t(arbre1->fils_gauche, arbre2->fils_gauche); //on regarde de facon recursive
	      if(g){return cmp_arbre_t(arbre1->fils_droit, arbre2->fils_droit);}
	      else {return 0;}
	    }
	  else {// les racines sont différentes,
	    type_t root1=arbre1->root;
	    type_t root2=arbre2->root;
	    if( (root1==PTR_T && root2==INT_T)) {return 1;} //on peut comparer pointeur et entier
	    else {return 0;}} //sinon c'est faux!
	}
    }
}

/* Verifie si les pointeurs sont des pointeurs sur VOID_T */
int cmp_ptr_t(arbre_t *ptr1, arbre_t *ptr2)
{
  //printf("\nptr1: %s \nptr2: %s\n", draw_type_expr(ptr1), draw_type_expr(ptr2));
  arbre_t *fils1= ptr1->fils_gauche;
  arbre_t *fils2= ptr2->fils_gauche;
  if( fils1 != NULL && fils2 != NULL)
    { if(fils1->root == VOID_T || fils2->root == VOID_T) {return 1;}
      else {return 0;}
    }
  else
    {return 0;}
}

/* Constructeur d'un type de base*/
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

/* Constructeur du type fonction */
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

/* Constructeur du type pointeur */
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

/* Constructeur du type produit cartésien */
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

/* Constructeur du type structure */
arbre_t *struc_type(arbre_t *champs, char* name)
{
  arbre_t *arbre= (arbre_t *) malloc(sizeof(arbre_t));
  if(verif_type(champs, ERROR_T))
    {
      return basic_type(ERROR_T, strdup(name));
    }
  arbre->root= STRUCT_T;	
  arbre->fils_gauche= champs;
  arbre->fils_droit= NULL;
  arbre->name= strdup(name);

  return arbre;
}


/* Verifie si le racine de l'arbre est du type donné */
int verif_type(arbre_t *expr_type, type_t expected_type)
{
  if(expr_type == NULL){return 0;}
  else
    { return expr_type->root == expected_type; }
}



/* Retourne le nom du type donné */
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
      return strdup("NULL");
      break;
    }
}

/* Retourne une chaine de caractere qui represente une expression de type lisible pour l'utilisateur*/
char *draw_type_expr(arbre_t *type_expr)
{
  if(type_expr== NULL){return strdup("NULL");}
  else
    {
      char *s;
      s= malloc(0);
      type_t root= type_expr->root;
      char *name= type_expr->name;
      int not_empty_name= strcmp(name, "");
      char *drawing= malloc(0);
      switch(root)
	{
	case INT_T: //INT_T
	  drawing=strdup("INT_T");
	  break;
	  
	case VOID_T: //VOID_T
	  drawing=strdup("VOID_T");
	  break;
	  
	case ERROR_T: //ERROR_T
	  drawing= strdup("ERROR_T");
	  break;
	  
	case FCT_T: //FCT_T
	  drawing= concatener(drawing, "FCT_T{(", draw_type_expr(type_expr->fils_gauche), ") -> (", draw_type_expr(type_expr->fils_droit), ")}", NULL);
	  break;
	  
	case PTR_T: //PTR_T
	  drawing= concatener(drawing,"PTR(", draw_type_expr(type_expr->fils_gauche), ")", NULL);
	  break;
	  
	case PROD_T://PROD_T
	  drawing= concatener(drawing, draw_type_expr(type_expr->fils_gauche), " x ", draw_type_expr(type_expr->fils_droit), NULL);
	  not_empty_name=0;
	  break;
	  
	case STRUCT_T://STRUCT_T
	  drawing= concatener(drawing, strdup("STRUCT_T( "), draw_type_expr(type_expr->fils_gauche)," )", NULL);
	  break;
	  
	default:
	  drawing= strdup("");
	  break;
	}
      
      if(not_empty_name){s= concatener(s, "[ ", drawing ," : ", name, " ]", NULL);}
      else{s= strdup(drawing);}
      free(drawing);
      return s;
    }
}

/* Calcule la taille de l'expression de type passé en paramètre */
int sizeof_type(arbre_t *type)
{
  if (type == NULL) {return 0;}
  else
    {
      switch(type->root)
	{
	case INT_T: //INT_T
	  return sizeof(int);
	  break;
	case VOID_T: //VOID_T
	  return sizeof(void);
	  break;
	case ERROR_T: //ERROR_T
	  return 0;
	  break;
	case FCT_T: //FCT_T		    
	  return sizeof(int);
	  break;
	case PTR_T: //PTR_T
	  return sizeof(int*);	    
	  break;
	case PROD_T://PROD_T
	  return (sizeof_type(type->fils_gauche) + sizeof_type(type->fils_droit));
	  break;
	case STRUCT_T://STRUCT_T
	  return sizeof_type(type->fils_gauche);
	  break;
	default:
	  return 0;
	  break;
	}
    }
}
