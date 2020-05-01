extern int printd(int i );
int main(){
int i;
i = 0;
t_0 = i<1000;
if t_0 goto label_0;
goto label_1;
label_0:
{
t_2 = printd(i);
}

t_1 = i+1;
i = t_1;

t_0 = i<1000;
if t_0 goto label_0;
goto label_1;
label_1:
return 0 ;
}



Accepted
