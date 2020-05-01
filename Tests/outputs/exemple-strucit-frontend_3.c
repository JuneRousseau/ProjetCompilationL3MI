not yet implemented: struct specifierextern void *malloc(int size );
extern void free(void *ptr );
not yet implemented: struct_specifier *allouer(not yet implemented: struct_specifier *p ){
temp_84934189_0 = p!=0;

if temp_84934189_0 goto label_83807607_1;
goto label_71438167_0;
label_83807607_1:
{
temp_10771506_1 = p->suivant;
temp_93507495_2 = sizeof(p);
temp_11836802_3 = malloc(temp_93507495_2);
temp_10771506_1 = temp_11836802_3;
temp_55388038_4 = p->suivant;
return temp_55388038_4 ;
}
label_71438167_0:
{
temp_70879922_5 = sizeof(p);
temp_60942217_6 = malloc(temp_70879922_5);
p = temp_60942217_6;
return p ;
}
}
not yet implemented: struct_specifier *desallouer(not yet implemented: struct_specifier *p ){
not yet implemented: struct_specifier *q;
temp_73380972_7 = p->suivant;
q = temp_73380972_7;
temp_84128972_8 = free(p);
return q ;
}
not yet implemented: struct_specifier *parcours(not yet implemented: struct_specifier *l ,not yet implemented: struct_specifier *(*f)(not yet implemented: struct_specifier *p ) ){
int i;
not yet implemented: struct_specifier *p;
not yet implemented: struct_specifier *tete;
temp_28041448_9 = f(l);
p = temp_28041448_9;
tete = p;
i = 0;
temp_1301355_10 = i<100;
if temp_1301355_10 goto label_98578547_2;
goto label_65883254_3;
label_98578547_2:
{
temp_11619151_12 = f(p);
p = temp_11619151_12;
}

temp_97466734_11 = i+1;
i = temp_97466734_11;

temp_1301355_10 = i<100;
if temp_1301355_10 goto label_98578547_2;
goto label_65883254_3;
label_65883254_3:
return tete ;
}
int main(){
not yet implemented: struct_specifier *tete;
temp_13931440_13 = &allouer;
temp_33585261_14 = parcours(0,temp_13931440_13);
tete = temp_33585261_14;
temp_91708115_15 = &desallouer;
temp_47552559_16 = parcours(tete,temp_91708115_15);
return 1 ;
}



Accepted
