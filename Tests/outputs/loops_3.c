extern int printd(int i );
int main(){
int i;
i = 0;
t_0 = i<10;

if t_0 goto label_0;
goto label_1;
label_0:
{
t_1 = printd(i);
t_2 = i+2;
i = t_2;
}

t_0 = i<10;

if t_0 goto label_0;
goto label_1;
label_1:
t_3 = -10;
i = t_3;
t_4 = i<=10;
if t_4 goto label_2;
goto label_3;
label_2:
t_6 = printd(i);

t_5 = i+1;
i = t_5;

t_4 = i<=10;
if t_4 goto label_2;
goto label_3;
label_3:
i = 0;
t_7 = -20;
t_8 = i>=t_7;

if t_8 goto label_4;
goto label_5;
label_4:
{
t_9 = printd(i);
t_10 = i-1;
i = t_10;
}

t_7 = -20;
t_8 = i>=t_7;

if t_8 goto label_4;
goto label_5;
label_5:
return 0 ;
}



Accepted
