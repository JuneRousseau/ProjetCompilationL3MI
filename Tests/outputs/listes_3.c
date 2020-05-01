extern int printd(int i );
not yet implemented: struct specifiernot yet implemented: struct_specifier *affiche(not yet implemented: struct_specifier *p ){
temp_28587412_0 = p!=0;
if temp_28587412_0 goto label_8097840_1;
goto label_67110760_0;
label_8097840_1:
temp_13669317_1 = p->valeur;
temp_61695294_2 = printd(temp_13669317_1);
label_67110760_0:
return p ;
}
extern void *malloc(int size );
extern void free(void *ptr );
not yet implemented: struct_specifier *allouer(not yet implemented: struct_specifier *p ){
temp_55194280_3 = p!=0;

if temp_55194280_3 goto label_95318089_3;
goto label_95004955_2;
label_95318089_3:
{
temp_8657245_4 = p->suivant;
temp_68361723_5 = sizeof(p);
temp_12259303_6 = malloc(temp_68361723_5);
temp_8657245_4 = temp_12259303_6;
temp_17115605_7 = p->suivant;
return temp_17115605_7 ;
}
label_95004955_2:
{
temp_95044012_8 = sizeof(p);
temp_19578425_9 = malloc(temp_95044012_8);
p = temp_19578425_9;
return p ;
}
}
not yet implemented: struct_specifier *desallouer(not yet implemented: struct_specifier *p ){
not yet implemented: struct_specifier *q;
temp_3500041_10 = p->suivant;
q = temp_3500041_10;
temp_6475563_11 = free(p);
return q ;
}
not yet implemented: struct_specifier *parcours(not yet implemented: struct_specifier *l ,not yet implemented: struct_specifier *(*f)(not yet implemented: struct_specifier *p ) ){
int i;
not yet implemented: struct_specifier *p;
not yet implemented: struct_specifier *tete;
temp_13942604_12 = f(l);
p = temp_13942604_12;
tete = p;
i = 0;
temp_34390087_13 = i<100;
if temp_34390087_13 goto label_15341482_6;
goto label_41532799_7;
label_15341482_6:
{
temp_98121036_15 = f(p);
p = temp_98121036_15;
temp_67807411_16 = p!=0;
if temp_67807411_16 goto label_21165787_5;
goto label_29256289_4;
label_21165787_5:
temp_66930288_17 = p->valeur;
temp_66930288_17 = i;
label_29256289_4:
}

temp_74158773_14 = i+1;
i = temp_74158773_14;

temp_34390087_13 = i<100;
if temp_34390087_13 goto label_15341482_6;
goto label_41532799_7;
label_41532799_7:
return tete ;
}
int main(){
not yet implemented: struct_specifier *tete;
not yet implemented: struct_specifier *t;
temp_50787450_18 = &allouer;
temp_86432712_19 = parcours(0,temp_50787450_18);
tete = temp_86432712_19;
t = tete;
temp_59344542_20 = &affiche;
temp_35388002_21 = parcours(t,temp_59344542_20);
temp_19634395_22 = &desallouer;
temp_40448306_23 = parcours(tete,temp_19634395_22);
return 0 ;
}



Accepted
