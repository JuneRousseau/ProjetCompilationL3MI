extern int printd(int i );
int (*fact)(int n );
int foo(int n ){
temp_84934189_0 = n<=1;
if temp_84934189_0 goto label_93507495_1;
goto label_10771506_0;
label_93507495_1:
return 1 ;
label_10771506_0:
temp_11836802_1 = *fact;
temp_11836802_1 = *fact;
temp_55388038_2 = n-1;
temp_70879922_3 = temp_11836802_1(temp_55388038_2);
temp_60942217_4 = n*temp_70879922_3;
return temp_60942217_4 ;
}
int main(){
temp_71438167_5 = &foo;
fact = temp_71438167_5;
temp_83807607_6 = *fact;
temp_83807607_6 = *fact;
temp_73380972_7 = temp_83807607_6(10);
temp_84128972_8 = printd(temp_73380972_7);
return 0 ;
}



Accepted
