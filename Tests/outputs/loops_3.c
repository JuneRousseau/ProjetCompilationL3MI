Type error line 6 > Expected type: INT_T , Found_type: VOID_T 
Type error line 7 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 8 > Expected type: INT_T , Found_type: INT_T 
Type error line 10 > Expected type: INT_T , Found_type: VOID_T 
Type error line 10 > Expected type: INT_T , Found_type: INT_T 
Type error line 11 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 13 > Expected type: INT_T , Found_type: VOID_T 
Type error line 14 > Expected type: FCT_T , Found_type: VOID_T 
Type error line 15 > Expected type: INT_T , Found_type: INT_T 
extern int printd(int i );
int main(){
int i;
i = 0;
temp_41413942_0 = i<10;

if temp_41413942_0 goto label_36994175_0;
goto label_92964358_1;
label_36994175_0:
{
temp_91441184_1 = printd(i);
temp_73312411_2 = i+2;
i = temp_73312411_2;
}

temp_41413942_0 = i<10;

if temp_41413942_0 goto label_36994175_0;
goto label_92964358_1;
label_92964358_1:
temp_48817969_3 = -10;
i = temp_48817969_3;
temp_49749460_4 = i<=10;
if temp_49749460_4 goto label_77450264_2;
goto label_16814527_3;
label_77450264_2:
temp_36021990_6 = printd(i);

temp_10408657_5 = i+1;
i = temp_10408657_5;

temp_49749460_4 = i<=10;
if temp_49749460_4 goto label_77450264_2;
goto label_16814527_3;
label_16814527_3:
i = 0;
temp_24738534_7 = -20;
temp_89766863_8 = i>=temp_24738534_7;

if temp_89766863_8 goto label_95541493_4;
goto label_97556147_5;
label_95541493_4:
{
temp_99988220_9 = printd(i);
temp_43655295_10 = i-1;
i = temp_43655295_10;
}

temp_24738534_7 = -20;
temp_89766863_8 = i>=temp_24738534_7;

if temp_89766863_8 goto label_95541493_4;
goto label_97556147_5;
label_97556147_5:
return 0 ;
}



Accepted
