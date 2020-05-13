extern void *malloc(int size);

struct A {
int premier;
int *deuxieme;
int troisieme;
};

struct B {
int unique;
};

struct C {
struct B *unique;
};

struct unique{
int unique;
};

struct D{
int v;
};

int main()
{

struct D{
struct D* next;
struct B* prec;
};

struct A *a;
struct B *b;
struct C *c;
struct D *d1;
struct D *d2;

int a1;
int *a2;
int b1;
struct B *c1;

//struct A fail; //ceci n'est pas accepte car structure sans pointeur

a=malloc(sizeof(a));
b=malloc(sizeof(b));
c=malloc(sizeof(c));

a->premier= 42; //offset = 0
a1= a->premier;
a->deuxieme= 0; //offset= 4
a->troisieme= 13; //offset= 12
//a->troisieme= b; //erreur, type invalide
//a->quatrieme= 1; //erreur, quatrieme n'est un champs valide

b->unique= 45; //offset=0
//b->erreur= 46; //erreur, champs invalide
//b->unique= a; //erreur de champs(type invalide)
b->unique= a->premier; // ok

c->unique= b; //offset=0;

d1= malloc(sizeof(d1));
d2= malloc(sizeof(d2));

d1->next= d2;
d2->next= 0;
d1->prec= b;

d1->next->next= 1; //erreur de champs(type invalide)
//d1->v=0; //erreur de champs(invalide)
//d1->next->v=0; //erreur de champs(type invalide)

}
