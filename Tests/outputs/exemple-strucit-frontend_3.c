not yet implemented: struct specifierextern void *malloc(int size );
extern void free(void *ptr );
not yet implemented: struct_specifier *allouer(not yet implemented: struct_specifier *p ){
temp_28587412_0 = p!=0;

if temp_28587412_0 goto label_12259303_1;
goto label_68361723_0;
label_12259303_1:
{
temp_13669317_1 = p->suivant;
temp_61695294_2 = sizeof(p);
temp_67110760_3 = malloc(temp_61695294_2);
temp_13669317_1 = temp_67110760_3;
temp_8097840_4 = p->suivant;
return temp_8097840_4 ;
}
label_68361723_0:
{
temp_55194280_5 = sizeof(p);
temp_8657245_6 = malloc(temp_55194280_5);
p = temp_8657245_6;
return p ;
}
}
not yet implemented: struct_specifier *desallouer(not yet implemented: struct_specifier *p ){
not yet implemented: struct_specifier *q;
temp_17115605_7 = p->suivant;
q = temp_17115605_7;
temp_95044012_8 = free(p);
return q ;
}
not yet implemented: struct_specifier *parcours(not yet implemented: struct_specifier *l ,not yet implemented: struct_specifier *(*f)(not yet implemented: struct_specifier *p ) ){
int i;
not yet implemented: struct_specifier *p;
not yet implemented: struct_specifier *tete;
temp_19578425_9 = f(l);
p = temp_19578425_9;
tete = p;
i = 0;
temp_95004955_10 = i<100;
if temp_95004955_10 goto label_6475563_2;
goto label_13942604_3;
label_6475563_2:
{
temp_3500041_12 = f(p);
p = temp_3500041_12;
}

temp_95318089_11 = i+1;
i = temp_95318089_11;

temp_95004955_10 = i<100;
if temp_95004955_10 goto label_6475563_2;
goto label_13942604_3;
label_13942604_3:
return tete ;
}
int main(){
not yet implemented: struct_specifier *tete;
temp_34390087_13 = &allouer;
temp_74158773_14 = parcours(0,temp_34390087_13);
tete = temp_74158773_14;
temp_98121036_15 = &desallouer;
temp_67807411_16 = parcours(tete,temp_98121036_15);
return 1 ;
}



Accepted
