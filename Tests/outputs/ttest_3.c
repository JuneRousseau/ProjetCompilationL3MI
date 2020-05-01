extern int printd(int i );
int main(){
int a;
int b;
int c;
a = 0;
b = 0;
c = 0;
if a goto label_0;
goto label_1;

label_0:
t_0 = b+1;
if t_0 goto label_2;
goto label_1;

label_2:
t_1= 1;

label_1:
t_1= 0;

if t_1 goto label_4;
goto label_3;
label_4:
t_2 = printd(a);
label_3:
t_3 = printd(b);
return 0 ;
}



Accepted
