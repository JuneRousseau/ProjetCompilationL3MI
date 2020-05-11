/*
int f(int a)
{
	int c;
	if(a==1)
	{ 
		int a;
		int b;
		b=a;
		c=a+b;
		return f(a-1);
	}
	else
	{
		int c;
		c=a;
	}
		return f(a-1);
}
*/
/*
struct liste2 {
int val;
struct liste2 *s;
};*/
				
/*
struct liste1 *koukou(struct liste1 *l1, struct liste2 *l2)
{
l1->suivant = l1;
return l1;
}*/

//int a;
/*
struct liste *parcours(struct liste *l, struct liste *(*f)(struct liste *p)) {
  int i;
  struct liste *p;
  struct liste *tete;
  tete=p=f(l); 
  for (i=0; i<100; i=i+1) {
    p=f(p);
    if(p!=0) p->valeur=i;
  }
  return tete;
}*/

extern int printd(int i);
extern void *malloc(int i);

struct liste {
int valeur;
struct liste *suivant;
};

int main() {

struct liste *l1;
struct liste *(*fct)(struct liste *p);

//struct node *n;
//int a;
l1=malloc(sizeof(l1));

l1->suivant= 0;
l1->valeur= 42;
//l1->n= 0;
//a=41;
//l1->n=&a;
//n->n=&a; 
/*
if(l1 != 0)
{
	a=1;
}
else
{
	l2=malloc(sizeof(l2));
}*/
//*(l1->suivant)= l1;
//l1= koukou(l1, l2);
//a=f(*(l->koukou));
//a=5;
//a= f(a);

return 0;
}
