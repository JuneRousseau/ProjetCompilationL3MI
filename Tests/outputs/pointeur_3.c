extern int printd(int i );
int main(){
int *i;
int *j;
t_0 = sizeof(int);
t_1 = malloc(t_0);
i = t_1;
t_2 = sizeof(int);
t_3 = malloc(t_2);
j = t_3;
t_4 = *i;
t_4 = 4;
t_5 = *i;
t_6 = printd(t_5);
t_7 = *j;
t_7 = 6;
t_8 = *j;
t_9 = printd(t_8);
t_10 = *j;
t_11 = *j;
t_12 = *i;
t_13 = t_11+t_12;
t_10 = t_13;
t_14 = *j;
t_15 = printd(t_14);
return 0 ;
}



Accepted
