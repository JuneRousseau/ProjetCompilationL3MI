extern int printd(int i );
not yet implemented: struct specifiernot yet implemented: struct_specifier *affiche(not yet implemented: struct_specifier *p ){
temp_84934189_0 = p!=0;
if temp_84934189_0 goto label_55388038_1;
goto label_11836802_0;
label_55388038_1:
temp_10771506_1 = p->valeur;
temp_93507495_2 = printd(temp_10771506_1);
label_11836802_0:
return p ;
}
extern void *malloc(int size );
extern void free(void *ptr );
not yet implemented: struct_specifier *allouer(not yet implemented: struct_specifier *p ){
temp_70879922_3 = p!=0;

if temp_70879922_3 goto label_97466734_3;
goto label_1301355_2;
label_97466734_3:
{
temp_60942217_4 = p->suivant;
temp_71438167_5 = sizeof(p);
temp_83807607_6 = malloc(temp_71438167_5);
temp_60942217_4 = temp_83807607_6;
temp_73380972_7 = p->suivant;
return temp_73380972_7 ;
}
label_1301355_2:
{
temp_84128972_8 = sizeof(p);
temp_28041448_9 = malloc(temp_84128972_8);
p = temp_28041448_9;
return p ;
}
}
not yet implemented: struct_specifier *desallouer(not yet implemented: struct_specifier *p ){
not yet implemented: struct_specifier *q;
temp_11619151_10 = p->suivant;
q = temp_11619151_10;
temp_98578547_11 = free(p);
return q ;
}
not yet implemented: struct_specifier *parcours(not yet implemented: struct_specifier *l ,not yet implemented: struct_specifier *(*f)(not yet implemented: struct_specifier *p ) ){
int i;
not yet implemented: struct_specifier *p;
not yet implemented: struct_specifier *tete;
temp_65883254_12 = f(l);
p = temp_65883254_12;
tete = p;
i = 0;
temp_13931440_13 = i<100;
if temp_13931440_13 goto label_520496_6;
goto label_15359545_7;
label_520496_6:
{
temp_91708115_15 = f(p);
p = temp_91708115_15;
temp_47552559_16 = p!=0;
if temp_47552559_16 goto label_49245566_5;
goto label_50116855_4;
label_49245566_5:
temp_83588964_17 = p->valeur;
temp_83588964_17 = i;
label_50116855_4:
}

temp_33585261_14 = i+1;
i = temp_33585261_14;

temp_13931440_13 = i<100;
if temp_13931440_13 goto label_520496_6;
goto label_15359545_7;
label_15359545_7:
return tete ;
}
int main(){
not yet implemented: struct_specifier *tete;
not yet implemented: struct_specifier *t;
temp_85041455_18 = &allouer;
temp_33659861_19 = parcours(0,temp_85041455_18);
tete = temp_33659861_19;
t = tete;
temp_90191409_20 = &affiche;
temp_66810518_21 = parcours(t,temp_90191409_20);
temp_84237705_22 = &desallouer;
temp_75125598_23 = parcours(tete,temp_84237705_22);
return 0 ;
}



Accepted
