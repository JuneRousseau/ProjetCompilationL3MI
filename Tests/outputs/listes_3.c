extern int printd(int i );
not yet implemented: struct specifiernot yet implemented: struct_specifier *affiche(not yet implemented: struct_specifier *p ){
t_0 = p!=0;
if t_0 goto label_1;
goto label_0;
label_1:
t_1 = p->valeur;
t_2 = printd(t_1);
label_0:
return p ;
}
extern void *malloc(int size );
extern void free(void *ptr );
not yet implemented: struct_specifier *allouer(not yet implemented: struct_specifier *p ){
t_3 = p!=0;

if t_3 goto label_3;
goto label_2;
label_3:
{
t_4 = p->suivant;
t_5 = sizeof(p);
t_6 = malloc(t_5);
t_4 = t_6;
t_7 = p->suivant;
return t_7 ;
}
label_2:
{
t_8 = sizeof(p);
t_9 = malloc(t_8);
p = t_9;
return p ;
}
}
not yet implemented: struct_specifier *desallouer(not yet implemented: struct_specifier *p ){
not yet implemented: struct_specifier *q;
t_10 = p->suivant;
q = t_10;
t_11 = free(p);
return q ;
}
not yet implemented: struct_specifier *parcours(not yet implemented: struct_specifier *l ,not yet implemented: struct_specifier *(πίe,V)(not yet implemented: struct_specifier *p ) ){
int i;
not yet implemented: struct_specifier *p;
not yet implemented: struct_specifier *tete;
t_12 = f(l);
p = t_12;
tete = p;
i = 0;
t_13 = i<100;
if t_13 goto label_6;
goto label_7;
label_6:
{
t_15 = f(p);
p = t_15;
t_16 = p!=0;
if t_16 goto label_5;
goto label_4;
label_5:
t_17 = p->valeur;
t_17 = i;
label_4:
}

t_14 = i+1;
i = t_14;

t_13 = i<100;
if t_13 goto label_6;
goto label_7;
label_7:
return tete ;
}
int main(){
not yet implemented: struct_specifier *tete;
not yet implemented: struct_specifier *t;
t_18 = &allouer;
t_19 = parcours(0,t_18);
tete = t_19;
t = tete;
t_20 = &affiche;
t_21 = parcours(t,t_20);
t_22 = &desallouer;
t_23 = parcours(tete,t_22);
return 0 ;
}



Accepted
