extern int printd(int i);
extern void *malloc(int i);

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

struct liste2 {
int val;
struct liste2 *s;
};


struct liste1 {
int valeur;
struct liste1 *suivant;
struct liste2 *precedent;
};				

struct liste1 *koukou(struct liste1 *l1, struct liste2 *l2)
{
l1->suivant = l1;
return l1;
}

int foo(int arg)
{
int* p;
if(arg == 0){arg=0;}
else {arg=1;}
}

int a;

int main() {

struct liste1 *l1;
struct liste2 *l2;
int a;
l1=malloc(sizeof(l1));
l1->precedent= 0;
l1->suivant= 0;
l1->valeur= 42;

if(l1 != 0)
{
	a=1;
}
else
{
	l2=malloc(sizeof(l2));
}
//*(l1->suivant)= l1;
//l1= koukou(l1, l2);
//a=f(*(l->koukou));
//a=5;
//a= f(a);

return 0;
}
