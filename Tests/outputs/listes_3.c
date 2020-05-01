Type error line 11 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 22 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 25 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 33 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 41 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 42 > Expected type: INT_T , Found_type: VOID_T 
Type error line 42 > Expected type: INT_T , Found_type: INT_T 
Type error line 43 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 52 > Expected type: INT_T , Found_type: VOID_T 
Type error line 52 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 53 > Expected type: INT_T , Found_type: VOID_T 
Type error line 53 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 54 > Expected type: INT_T , Found_type: VOID_T 
Type error line 54 > Expected type: FCT_T , Found_type: VOID_T 
extern int printd(int i );
not yet implemented: struct specifiernot yet implemented: struct_specifier *affiche(not yet implemented: struct_specifier *p ){
temp_41413942_0 = p!=0;
if temp_41413942_0 goto label_92964358_1;
goto label_36994175_0;
label_92964358_1:
temp_91441184_1 = p->valeur;
temp_73312411_2 = printd(temp_91441184_1);
label_36994175_0:
return p ;
}
extern void *malloc(int size );
extern void free(void *ptr );
not yet implemented: struct_specifier *allouer(not yet implemented: struct_specifier *p ){
temp_48817969_3 = p!=0;

if temp_48817969_3 goto label_99988220_3;
goto label_89766863_2;
label_99988220_3:
{
temp_49749460_4 = p->suivant;
temp_10408657_5 = sizeof(p);
temp_36021990_6 = malloc(temp_10408657_5);
temp_49749460_4 = temp_36021990_6;
temp_77450264_7 = p->suivant;
return temp_77450264_7 ;
}
label_89766863_2:
{
temp_16814527_8 = sizeof(p);
temp_24738534_9 = malloc(temp_16814527_8);
p = temp_24738534_9;
return p ;
}
}
not yet implemented: struct_specifier *desallouer(not yet implemented: struct_specifier *p ){
not yet implemented: struct_specifier *q;
temp_43655295_10 = p->suivant;
q = temp_43655295_10;
temp_95541493_11 = free(p);
return q ;
}
not yet implemented: struct_specifier *parcours(not yet implemented: struct_specifier *l ,not yet implemented: struct_specifier *(*f)(not yet implemented: struct_specifier *p ) ){
int i;
not yet implemented: struct_specifier *p;
not yet implemented: struct_specifier *tete;
temp_97556147_12 = f(l);
p = temp_97556147_12;
tete = p;
i = 0;
temp_42151563_13 = i<100;
if temp_42151563_13 goto label_93794235_6;
goto label_3607009_7;
label_93794235_6:
{
temp_70672240_15 = f(p);
p = temp_70672240_15;
temp_41219504_16 = p!=0;
if temp_41219504_16 goto label_80589185_5;
goto label_52376768_4;
label_80589185_5:
temp_72447891_17 = p->valeur;
temp_72447891_17 = i;
label_52376768_4:
}

temp_44897136_14 = i+1;
i = temp_44897136_14;

temp_42151563_13 = i<100;
if temp_42151563_13 goto label_93794235_6;
goto label_3607009_7;
label_3607009_7:
return tete ;
}
int main(){
not yet implemented: struct_specifier *tete;
not yet implemented: struct_specifier *t;
temp_36827765_18 = &allouer;
temp_34642501_19 = parcours(0,temp_36827765_18);
tete = temp_34642501_19;
t = tete;
temp_3155561_20 = &affiche;
temp_98706472_21 = parcours(t,temp_3155561_20);
temp_80894175_22 = &desallouer;
temp_44569504_23 = parcours(tete,temp_80894175_22);
return 0 ;
}



Accepted
