extern int printd(int i );
int (*fact)(int n );
int foo(int n ){
temp_28587412_0 = n<=1;
if temp_28587412_0 goto label_61695294_1;
goto label_13669317_0;
label_61695294_1:
return 1 ;
label_13669317_0:
temp_67110760_1 = *fact;
temp_67110760_1 = *fact;
temp_8097840_2 = n-1;
temp_55194280_3 = temp_67110760_1(temp_8097840_2);
temp_8657245_4 = n*temp_55194280_3;
return temp_8657245_4 ;
}
int main(){
temp_68361723_5 = &foo;
fact = temp_68361723_5;
temp_12259303_6 = *fact;
temp_12259303_6 = *fact;
temp_17115605_7 = temp_12259303_6(10);
temp_95044012_8 = printd(temp_17115605_7);
return 0 ;
}



Accepted
