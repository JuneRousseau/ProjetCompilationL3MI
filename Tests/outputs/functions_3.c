Type error line 6 > Expected type: INT_T , Found_type: VOID_T 
Type error line 8 > Expected type: INT_T , Found_type: VOID_T 
Type error line 8 > Expected type: INT_T , Found_type: INT_T 
Type error line 8 > Expected type: FCT_T , Found_type: ERROR_T 
Type error line 8 > Expected type: INT_T , Found_type: VOID_T 
Type error line 13 > Expected type: INT_T , Found_type: VOID_T 
Type error line 14 > Expected type: INT_T , Found_type: VOID_T 
Type error line 14 > Expected type: FCT_T , Found_type: ERROR_T 
Type error line 14 > Expected type: FCT_T , Found_type: VOID_T 
extern int printd(int i );
int (*fact)(int n );
int foo(int n ){
temp_41413942_0 = n<=1;
if temp_41413942_0 goto label_73312411_1;
goto label_91441184_0;
label_73312411_1:
return 1 ;
label_91441184_0:
temp_36994175_1 = *fact;
temp_36994175_1 = *fact;
temp_92964358_2 = n-1;
temp_48817969_3 = temp_36994175_1(temp_92964358_2);
temp_49749460_4 = n*temp_48817969_3;
return temp_49749460_4 ;
}
int main(){
temp_10408657_5 = &foo;
fact = temp_10408657_5;
temp_36021990_6 = *fact;
temp_36021990_6 = *fact;
temp_77450264_7 = temp_36021990_6(10);
temp_16814527_8 = printd(temp_77450264_7);
return 0 ;
}



Accepted
